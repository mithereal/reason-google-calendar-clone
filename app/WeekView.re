open WeekShared
open Util


let component = ReasonReact.reducerComponent("WeekView");

let make = (_children) => {
  ...component,
  initialState:  () => {startDate: weekstart(MomentRe.momentNow()), weekDays: getAllDaysInTheWeek(MomentRe.momentNow()), showAddEventModal: false, eventStart: "", eventEnd: ""},
  reducer: reducer,
  render: ({state,send}) =>
  <div className="container">


    <AddEventModal           title=""
                             visible=state.showAddEventModal
                             eventStart=state.eventStart
                             eventEnd=state.eventEnd
                             appSend=send
                             />

    <WeekToolbar appSend=send formattedDate = Util.monthyear(state.startDate) />

    <WeekHeader weekDays=state.weekDays />


   </div>
};