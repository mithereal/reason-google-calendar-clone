open Antd;
open Util;
open WeekShared;

let component = ReasonReact.statelessComponent("AddEvent");

let make = (~title , ~start: string, ~evtend: string,  ~appSend, _children) => {
...component,
render:  ({state,send}) =>
    <>

      <Input
        type_="text"
        placeholder="Add Title"
        value = title
        /* style={ Styles.inputStyles } */
        size="large"
       /* autoFocus={true} */
        onChange=(event => appSend(ONTITLECHANGE(ReactEvent.Form.target(event)##value)))
      />


    </>

};
