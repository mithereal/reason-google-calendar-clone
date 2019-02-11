open Type;

type action =
| GOTONEXTWEEK
| GOTOPREVIOUSWEEK
| GOTOTODAY
| EVENTMODALOK
| EVENTMODALOPEN
| EVENTMODALCLOSE
| FETCHEVENTS
| TITLECHANGE(string)
| NEWEVENT(MomentRe.Moment.t, integer)

type state = {
startDate: MomentRe.Moment.t,
weekDays: weekdays,
showAddEventModal: bool,
current_event: option(event),
events: events,
timeslots: timeslots
}


let reducer = (action, state) => {
                     switch(action) {
                     | EVENTMODALOPEN => ReasonReact.Update({...state, showAddEventModal: true})
                     | EVENTMODALCLOSE => ReasonReact.Update({...state, showAddEventModal: false})
                     | EVENTMODALOK =>
                        let new_events = switch(state.current_event){
                            | None => state.events
                            | Some(evt) => switch(state.events){
                                             | Some(x) => Some(List.append(x, [evt]))
                                             | None => Some([evt])
                            }
                        }
                        ReasonReact.Update({...state, showAddEventModal: false, events: new_events })
                     | GOTONEXTWEEK =>
                        let day = MomentRe.Moment.startOf(`week, state.startDate);
                        let duration = MomentRe.duration(7,`days);

                          MomentRe.Moment.mutableAdd(day, duration);
                          MomentRe.Moment.setMinute(0,day);
                          MomentRe.Moment.setHour(0,day);

                         let weekdays = Util.getAllDaysInTheWeek(Util.weekstart(day))
                         ReasonReact.Update({...state, startDate: day, weekDays: weekdays})
                     | GOTOPREVIOUSWEEK =>
                        let day = MomentRe.Moment.startOf(`week, state.startDate);
                        let duration = MomentRe.duration(7,`days);

                          MomentRe.Moment.mutableSubtract(day, duration);
                          MomentRe.Moment.setMinute(0,day);
                          MomentRe.Moment.setHour(0,day);

                          let weekdays = Util.getAllDaysInTheWeek(Util.weekstart(day))
                          ReasonReact.Update({...state, startDate: day, weekDays: weekdays})
                     | GOTOTODAY =>
                        let day = MomentRe.momentNow();
                        let weekdays = Util.getAllDaysInTheWeek(Util.weekstart(day));
                        ReasonReact.Update({...state, startDate: Util.weekstart(day), weekDays: weekdays})
                     | FETCHEVENTS =>
                        let events = None;
                        let timeslots = Util.convertToTimeslots(state.weekDays, Util.times);
                        ReasonReact.Update({...state, events: None, timeslots: timeslots})
                     | TITLECHANGE(t) =>
                        switch(String.length(t) > 0){
                        | false => ReasonReact.Update({...state, current_event: None})
                        | true =>
                             let ce = switch(state.current_event){
                                       | None => let evt:event = {
                                                  id: "",
                                                  eventName: t,
                                                  eventStart: None,
                                                  eventEnd: None,
                                                  startWeek: None,
                                                  endWeek: None

                                                  };
                                                  Some(evt)

                                       | Some(x) => let evt:event = {
                                            id: "",
                                            eventName: t,
                                            eventStart: None,
                                            eventEnd: None,
                                            startWeek: None,
                                            endWeek: None
                                       };
                                       Some(evt)
                                       }};

                          ReasonReact.Update({...state, current_event: ce})
                      | NEWEVENT(datestamp, hour) =>
                                                        let evt = switch(state.current_event){
                                                        | None => None
                                                        | Some(e) =>
                                                            let md = MomentRe.Moment.setHour(hour,datestamp);
                                                            let evt_start  = MomentRe.Moment.setMinute(0,md);

                                                            let md = MomentRe.Moment.setHour(hour + 1,datestamp);

                                                            let evt_end  = MomentRe.Moment.setMinute(0 ,md);
                                                            let startweek  = 1;
                                                            let endweek  = 1;

                                                            let evt:event = {
                                                                 id: generateUniqueId(e.eventName, evt_start, evt_end),
                                                                 eventName: e.eventName,
                                                                 eventStart: Some(evt_start),
                                                                 eventEnd: Some(evt_end),
                                                                 startWeek: Some(startweek),
                                                                 endWeek: Some(endweek)
                                                                 }
                                                         Some(evt)
                                                        }


                        ReasonReact.Update({...state, showAddEventModal: true, current_event: evt})
                     };
                     }