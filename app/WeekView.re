open Type;
open Shared;
open Util;


let component = ReasonReact.reducerComponent("WeekView");


let make = (~appSend, ~startDate,  _children) => {
  ...component,
  initialState:  () => {startDate: Util.weekstart(startDate), dates: Util.getAllDatesInTheWeek(startDate), showAddEventModal: false, events: None, current_event: None, timeslots: Some(Util.times) },
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
                                          eventStart=""
                                          eventEnd=""
                                          editMode="add"
                                          appSend=send
                                          />
}
)

    <WeekToolbar appSend=send formattedDate = Util.monthyear(state.startDate) />

    <WeekHeader dates=state.dates />

(
switch (state.timeslots){
| None => ReasonReact.null
| Some(t) => ReasonReact.array(
                               Array.of_list(
                                  List.mapi(
                                    (index: int, t: timeslot) =>

                                     <TimeSlotGroup
                                                key = (t.time)
                                                dates = state.dates
                                                timeslot = t
                                                appSend = send

                                              />
                                     ,
                                   t,
                                 ),
                             ),
                           )
}

)


   </div>
};