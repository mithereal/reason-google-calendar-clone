
type action =
| GOTONEXTWEEK
| GOTOPREVIOUSWEEK
| GOTOTODAY
| ONOKADDEVENTMODAL(string)


type state = {
showEditEventModal: bool,
startDate: string,
showAddEventModal: bool
}


let component = ReasonReact.reducerComponent("WeekView");

let make = (_children) => {
  ...component,
  initialState:  () => {showEditEventModal: false, startDate: "", showAddEventModal: false},
  reducer: (action, state) =>
                 switch(action) {
                 | GOTONEXTWEEK => ReasonReact.Update({...state, showEditEventModal: false})
                 | GOTOPREVIOUSWEEK => ReasonReact.Update({...state, showEditEventModal: false})
                 | GOTOTODAY => ReasonReact.Update({...state, showEditEventModal: false})
                 | ONOKADDEVENTMODAL(title) => ReasonReact.Update({...state, showEditEventModal: false})
                 },
  render: ({state,send}) =>
  <div className="container">

  <AddEventModal

   />

  <WeekToolbar
   appSend = send
   />

  <WeekHeader/>

   </div>
};