open Type;

type action =
| GOTONEXTWEEK
| GOTOPREVIOUSWEEK
| GOTOTODAY
| EVENTMODALOK
| EVENTMODALOPEN
| EVENTMODALCLOSE
| TITLECHANGE(string)
| NEWEVENT(MomentRe.Moment.t, string, string)

type state = {
startDate: MomentRe.Moment.t,
weekDays: list(MomentRe.Moment.t),
showAddEventModal: bool,
current_event: option(event),
events: events,
timeslots: timeslots
}

let reducer = (action, state) =>
                     switch(action) {
                     | GOTONEXTWEEK => let day = MomentRe.Moment.startOf(`week, state.startDate);
                                       let duration = MomentRe.duration(7,`days);

                                         MomentRe.Moment.mutableAdd(day, duration);
                                         MomentRe.Moment.setMinute(0,day);
                                         MomentRe.Moment.setHour(0,day);
                                        let weekdays = Util.getAllDaysInTheWeek(Util.weekstart(day))
                        ReasonReact.Update({...state, startDate: day, weekDays: weekdays})
                     | EVENTMODALCLOSE => ReasonReact.Update({...state, showAddEventModal: false})
                     | NEWEVENT(datestamp, hour, minute) =>
                     let md = MomentRe.Moment.setHour(int_of_string(hour),datestamp);
                     let evt_start  = MomentRe.Moment.setMinute(int_of_string(minute),md);
                     let evt:event = {
                          eventName: "",
                          eventStart: hour,
                          eventEnd: "",
                          target: None
                          }

                      ReasonReact.Update({...state, showAddEventModal: true, current_event: Some(evt)})
                     | GOTOPREVIOUSWEEK => let day = MomentRe.Moment.startOf(`week, state.startDate);
                                       let duration = MomentRe.duration(7,`days);

                                         MomentRe.Moment.mutableSubtract(day, duration);
                                         MomentRe.Moment.setMinute(0,day);
                                         MomentRe.Moment.setHour(0,day);
                                         let weekdays = Util.getAllDaysInTheWeek(Util.weekstart(day))
                                         ReasonReact.Update({...state, startDate: day, weekDays: weekdays})
                     | GOTOTODAY => let day = MomentRe.momentNow();
                                     let weekdays = Util.getAllDaysInTheWeek(Util.weekstart(day));
                     ReasonReact.Update({...state, startDate: Util.weekstart(day), weekDays: weekdays})
                     | EVENTMODALOK => let new_events = switch(state.current_event){
                        | None => state.events
                        | Some(evt) => switch(state.events){
                                         | Some(x) => Some(List.append(x, [evt]))
                                         | None => Some([evt])
                        }}


                     ReasonReact.Update({...state, showAddEventModal: false, events: new_events })
                     | EVENTMODALOPEN => ReasonReact.Update({...state, showAddEventModal: true})
                     | TITLECHANGE(t) => switch(String.length(t) > 0){
                        | false => ReasonReact.Update({...state, current_event: None})
                        | _ =>
                     let ce = switch(state.current_event){
                                                                | None => let evt:event = {
                                                                                                                                          eventName: t,
                                                                                                                                          eventStart: "",
                                                                                                                                          eventEnd: "",
                                                                                                                                          target: None,
                                                                                                                                          };
                                                                                                                                          Some(evt)

                                                                | Some(x) => let evt:event = {
                                                                eventName: t,
                                                                eventStart: x.eventStart,
                                                                eventEnd: x.eventEnd,
                                                                target: None,
                                                                };
                                                                Some(evt)
                                                                };

                                               ReasonReact.Update(
                     {...state, current_event: ce})
                     };
                     }