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
| NEWEVENT(MomentRe.Moment.t, new_event)

type state = {
startDate: MomentRe.Moment.t,
weekDays: list(MomentRe.Moment.t),
showAddEventModal: bool,
current_event: option(event),
events: events,
timeslots: timeslots
}

let sortbyTimeslots = (events, timeslots) => {

switch(events){
| None => None
| Some(e) => Some(e)
}

let timeslot = {
time: "123",
events: None
}

Some([timeslot])
}

let generateUniqueId = (title, e_start, e_end) => {
   e_start + title + e_end
}

let eventExist = (events,time) => {
false
}

let addEvent = (allEvents, newEvent) => {
   let time = Duration.hours(newEvent.e_start)

   let eventWithInfo = () => {
      ...newEvent ,
     startWeek: Duration.weeks(newEvent.e_start),
     endWeek: Duration.weeks(newEvent.e_end)

   }

   let complete_event = eventWithInfo()

   let eventexists = eventExist(allEvents, time)

   let newevents = switch(eventexists){
   | false => List.append(allEvents, [complete_event])
   | true => allEvents
   }

   newevents
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
                     | NEWEVENT(datestamp, new_event) =>

                 let evt = switch(state.current_event){
                     | None => None
                     | Some(e) =>
                                         let md = MomentRe.Moment.setHour(int_of_string(new_event.hour),datestamp);
                                         let evt_start  = MomentRe.Moment.setMinute(int_of_string(new_event.minute),md);

                                         let md = MomentRe.Moment.setHour(int_of_string(new_event.hour) + 1,datestamp);
                                         let evt_end  = MomentRe.Moment.setMinute(0 ,md);

                                         let evt:event = {
                                              eventName: generateUniqueId(e.title, evt_start, evt_end),
                                              eventStart: evt_start,
                                              eventEnd: evt_end,
                                              target: None
                                              }
                                              Some(evt)
                     }


                      ReasonReact.Update({...state, showAddEventModal: true, current_event: evt})
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
Js.log(new_events);

                     ReasonReact.Update({...state, showAddEventModal: false, events: new_events })
                     | EVENTMODALOPEN => ReasonReact.Update({...state, showAddEventModal: true})
                     | FETCHEVENTS => let events = None;
                                      let timeslots = sortbyTimeslots(events, Util.times);
                     ReasonReact.Update({...state, events: None, timeslots: timeslots})
                     | TITLECHANGE(t) => switch(String.length(t) > 0){
                        | false => ReasonReact.Update({...state, current_event: None})
                        | true =>
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