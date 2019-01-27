type action =
| GOTONEXTWEEK
| GOTOPREVIOUSWEEK
| GOTOTODAY
| ONOKADDEVENTMODAL
| ONCLOSEADDEVENTMODAL
| ONCURRENTEVENTTIMECHANGE
| ONTITLECHANGE(string)
| ONOPENADDEVENTMODAL

type event = {
eventName: string,
eventStart: string,
eventEnd: string,
}

type events = option(list(event))


type state = {
startDate: MomentRe.Moment.t,
weekDays: list(MomentRe.Moment.t),
showAddEventModal: bool,
current_event: option(event),
events: events
}

type target = {
value: string
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
                     | ONCLOSEADDEVENTMODAL => ReasonReact.Update({...state, showAddEventModal: false})
                     | ONCURRENTEVENTTIMECHANGE => ReasonReact.Update({...state, showAddEventModal: false})
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
                     | ONOKADDEVENTMODAL => let new_events = switch(state.current_event){
                        | None => state.events
                        | Some(evt) => switch(state.events){
                                         | Some(x) => Some(List.append(x, [evt]))
                                         | None => Some([evt])
                        }}


                     ReasonReact.Update({...state, showAddEventModal: false, events: new_events })
                     | ONOPENADDEVENTMODAL => ReasonReact.Update({...state, showAddEventModal: true})
                     | ONTITLECHANGE(t) => switch(String.length(t) > 0){
                        | false => ReasonReact.Update({...state, current_event: None})
                        | _ =>
                     let ce = switch(state.current_event){
                                                                | None => let evt:event = {
                                                                                                                                          eventName: t,
                                                                                                                                          eventStart: "",
                                                                                                                                          eventEnd: "",
                                                                                                                                          };
                                                                                                                                          Some(evt)

                                                                | Some(x) => let evt:event = {
                                                                eventName: t,
                                                                eventStart: x.eventStart,
                                                                eventEnd: x.eventEnd,
                                                                };
                                                                Some(evt)
                                                                };

                                               ReasonReact.Update(
                     {...state, current_event: ce})
                     };
                     }