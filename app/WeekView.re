open Shared;
open Util;


let component = ReasonReact.reducerComponent("WeekView");


let make = (~appSend, ~startDate,  _children) => {
  ...component,
  initialState:  () => {startDate: weekstart(startDate), weekDays: getAllDaysInTheWeek(startDate), showAddEventModal: false, events: None, current_event: None, timeslots: None },
  reducer: reducer,
   didMount: self => {
        self.send(FETCHEVENTS)
      },
  render: ({state,send}) =>
  <div style=Style.container >

(
switch(state.current_event){
| None =>     <EventModal           title=""
                                       visible=state.showAddEventModal
                                       eventStart=""
                                       eventEnd=""
                                       editMode="cancel"
                                       appSend=send
                                       />
| Some(e) =>     <EventModal              title=e.eventName
                                          visible=state.showAddEventModal
                                          eventStart=e.eventStart
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
                                    key = (string_of_int(t))
                                    weekDays = state.weekDays
                                    timeslot = t
                                    appSend = send

                                  />
                         ,
                       state.timeslots,
                     ),
                 ),
               )
            )


   </div>
};