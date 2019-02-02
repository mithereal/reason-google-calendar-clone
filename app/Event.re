open Shared;
open Util;
open Antd;

   let complete_event = eventWithInfo()

   let eventexists = eventExist(allEvents, time)

   let newevents = switch(eventexists){
   | true => allEvents
   | _ => allEvents
   }

   newevents
}

let component = ReasonReact.statelessComponent("Event");

let make = (~title , ~start, ~evtend,  ~appSend, _children) => {
...component,
render:  ({state,send}) =>

    <>

      <Input
        type_="text"
        placeholder="Add Title"
        value = title
        style=Style.inputStyles
        size="large"
       /* autoFocus={true} */
        onChange=(event => appSend(TITLECHANGE(ReactEvent.Form.target(event)##value)))
      />
        <DatePicker
        style=Style.datePicker
        value=MomentRe.moment(start)
        format="MMM Do, YYYY hh:mm a"

        />

    </>

};
