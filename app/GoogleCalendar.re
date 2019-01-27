open Webapi.Dom;

open Shared;
open WeekShared;

type action =
| WEEKLY

type state = {
view: action
}


let reducer = (action, state) =>
      switch(action) {
     | WEEKLY => ReasonReact.Update({...state, view: WEEKLY})
      }

let component = ReasonReact.reducerComponent("GoogleCalendar")

let make = (_children) => {

  ...component,
   initialState: () => {view: WEEKLY},
  reducer,
  render: (self) =>

(
switch(self.state.view){
| _ => <WeekView appSend = self.send startDate = MomentRe.momentNow() />
}
)

  };

