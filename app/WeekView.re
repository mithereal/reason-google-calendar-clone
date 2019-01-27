open WeekShared
open Util


let component = ReasonReact.reducerComponent("WeekView");


let make = (_children) => {
  ...component,
  initialState:  () => {startDate: weekstart(MomentRe.momentNow()), weekDays: getAllDaysInTheWeek(MomentRe.momentNow()), showAddEventModal: false, events: None, current_event: None },
  reducer: reducer,
  render: ({state,send}) =>
  <div className="container">


    <AddEventModal           title="test"
                             visible=state.showAddEventModal
                             eventStart=""
                             eventEnd=""
                             editMode="Cancel"
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
                                    appSend=send
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