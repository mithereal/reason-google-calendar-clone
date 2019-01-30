open Shared;
open Webapi.Dom;

type action =
| WEEKLY

type state = {
view: action
}

let reducer = (action, state) => {

      switch(action){
      | WEEKLY => ReasonReact.Update({...state, view: WEEKLY})
      }

}

let component = ReasonReact.reducerComponent("GoogleCalendar")

let make = (_children) => {
  ...component,
  initialState: () => {view: WEEKLY},
  reducer,
  render: (self) =>

    (
    switch(self.state.view){
    | WEEKLY => <WeekView appSend = self.send startDate = MomentRe.momentNow() />
    }

)

  };

