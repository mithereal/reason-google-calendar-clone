open Antd;
open Util;
open WeekShared;

let component = ReasonReact.statelessComponent("AddEvent");

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
