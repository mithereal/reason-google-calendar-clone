open WeekShared
open Util


let component = ReasonReact.reducerComponent("WeekView");

let make = (_children) => {
  ...component,
  initialState:  () => {startDate: "", weekDays: getAllDaysInTheWeek(), showAddEventModal: false, eventStart: "", eventEnd: ""},
  reducer: reducer,
  render: ({state,send}) =>
  <div className="container">


    <AddEventModal           title=""
                             visible=state.showAddEventModal
                             eventStart=state.eventStart
                             eventEnd=state.eventEnd
                             appSend=send
                             />

    <WeekToolbar appSend=send />

    <WeekHeader weekDays=state.weekDays />


   </div>
};