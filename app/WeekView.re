open WeekShared
open Util


let component = ReasonReact.reducerComponent("WeekView");

let events=[1,2,3];

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

(
                ReasonReact.array(
                   Array.of_list(
                      List.mapi(
                        (index: int, t: int) =>

                         <TimeSlotGroup
                                    key = (string_of_int(index))
                                    time = t
                                    weekDays = state.weekDays
                                    appSend= send
                                  >

                                  </TimeSlotGroup>
                         ,
                       Util.times,
                     ),
                 ),
               )
            )


   </div>
};