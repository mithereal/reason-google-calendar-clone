open WeekShared
open Util


let component = ReasonReact.reducerComponent("WeekView");


let make = (~appSend, ~startDate,  _children) => {
  ...component,
  initialState:  () => {startDate: weekstart(startDate), weekDays: getAllDaysInTheWeek(startDate), showAddEventModal: false, events: None, current_event: None },
  reducer: reducer,
  render: ({state,send}) =>
  <div className="container">

(
switch(state.current_event){
| None =>     <AddEventModal           title=""
                                       visible=state.showAddEventModal
                                       eventStart=""
                                       eventEnd=""
                                       editMode="cancel"
                                       appSend=send
                                       />
| Some(e) =>     <AddEventModal           title=e.eventName
                                          visible=state.showAddEventModal
                                          eventStart=e.eventName
                                          eventEnd=e.eventEnd
                                          editMode="add"
                                          appSend=send
                                          />
}
)

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


       ( switch(state.events){
       | None => None
       | Some(x) => None
       }
        )

                                  </TimeSlotGroup>
                         ,
                       Util.times,
                     ),
                 ),
               )
            )


   </div>
};