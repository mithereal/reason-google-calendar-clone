open Webapi.Dom;

open Shared;



type action =
| FETCH
| GENERATE
| ADD
| DELETE
| UPDATE

let reducer = (action, state) =>
      switch(action) {
     | FETCH => ReasonReact.Update({...state, events: [||]})
      }

let component = ReasonReact.reducerComponent("GoogleCalendar")

let make = (_children) => {

  ...component,
   initialState: () => {events: [||]},
  reducer,
   didMount: (self) =>
 {
 self.send(FETCH)
},
  render: (self) =>
<>
<WeekView />
</>
  };

