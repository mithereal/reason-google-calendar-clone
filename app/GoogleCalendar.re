open Webapi.Dom;

let window = Webapi.Dom.Document.asEventTarget(Webapi.Dom.window);

let component = ReasonReact.reducerComponent("GoogleCalendar");

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
  render: ({state, send}) =>
<WeekView
        events=state.events
        onNewEvent={this.addNewEvent}
        onEventUpdate={this.updateEvent}
        onEventDelete={this.deleteEvent}
      />
  };
  
