
type action =
| GOTONEXTWEEK
| GOTOPREVIOUSWEEK
| GOTOTODAY
| ONOKADDEVENTMODAL(string)
| ONCLOSEADDEVENTMODAL
| ONCURRENTEVENTTIMECHANGE
| ONTITLECHANGE


type state = {
startDate: string,
weekDays: string,
showAddEventModal: bool,
eventStart: string,
eventEnd: string,
}

let component = ReasonReact.reducerComponent("WeekView");

let make = (_children) => {
  ...component,
  initialState:  () => {startDate: "", weekDays: "", showAddEventModal: false, eventStart: "", eventEnd: ""},
  reducer: (action, state) =>
                 switch(action) {
                 | GOTONEXTWEEK => ReasonReact.Update({...state, showAddEventModal: false})
                 | ONCLOSEADDEVENTMODAL => ReasonReact.Update({...state, showAddEventModal: false})
                 | ONCURRENTEVENTTIMECHANGE => ReasonReact.Update({...state, showAddEventModal: false})
                 | GOTOPREVIOUSWEEK => ReasonReact.Update({...state, showAddEventModal: false})
                 | GOTOTODAY => ReasonReact.Update({...state, showAddEventModal: false})
                 | ONOKADDEVENTMODAL(title) => ReasonReact.Update({...state, showAddEventModal: false})
                 },
  render: ({state,send}) =>
  <div className="container">
    <WeekHeader weekDays="" />

    <AddEventModal           title=""
                            visible=state.showAddEventModal
                             onCancel=send(ONCLOSEADDEVENTMODAL)
                             onClose=send(ONCLOSEADDEVENTMODAL)
                             onOk=send(ONOKADDEVENTMODAL("x"))
                             eventStart=state.eventStart
                             eventEnd=state.eventEnd
                             onTimeChange=send(ONCURRENTEVENTTIMECHANGE)
                             onTitleChange=send(ONCURRENTEVENTTIMECHANGE)
                             />

    <WeekToolbar           goToPreviousWeek=send(GOTOPREVIOUSWEEK)
                           goToNextWeek=send(GOTONEXTWEEK)
                           startDate=state.startDate
                           goToToday=send(GOTOTODAY)
                           />


   </div>
};