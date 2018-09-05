open Webapi.Dom

open Shared

let window = Webapi.Dom.Document.asEventTarget(Webapi.Dom.window)

let component = ReasonReact.reducerComponent("GoogleCalendar")

type action =
| FETCH
| GENERATE
| ADD
| DELETE
| UPDATE

let reducer = (action, state) =>
      switch(action) {
      FETCH => let events = Js.Json.array_(Dom_storage.getItem("events"))
                     ReasonReact.Update(...state, events: events)
      }

let make = (_children) => {

  ...component,
   initialState: () => {events: [||]},
  reducer,
   didMount: (self) =>
 {
 self.send(FETCHEVENTS)
},
  render: (self) =>
<WeekView
        events=self.state.events
        onNewEvent=self.addNewEvent
        onEventUpdate=self.updateEvent
        onEventDelete=self.deleteEvent
      />
  };
  
