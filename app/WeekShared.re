type action =
| GOTONEXTWEEK
| GOTOPREVIOUSWEEK
| GOTOTODAY
| ONOKADDEVENTMODAL(string)
| ONCLOSEADDEVENTMODAL
| ONCURRENTEVENTTIMECHANGE
| ONTITLECHANGE


type state = {
startDate: MomentRe.Moment.t,
weekDays: list(MomentRe.Moment.t),
showAddEventModal: bool,
eventStart: string,
eventEnd: string,
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
                     | ONOKADDEVENTMODAL(title) => ReasonReact.Update({...state, showAddEventModal: false})
                     };