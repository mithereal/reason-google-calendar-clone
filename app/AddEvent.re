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
        value="title"
        /* style={ Styles.inputStyles } */
        size="large"
       /* autoFocus={true} */
        onChange=(_event => appSend(ONTITLECHANGE))
      />

            <DatePicker
           /*    style={ Styles.dateStyles } */
              value=""
              onChange=""
              showTime=""
              format="MMM Do, YYYY hh:mm a"
            />

    </>

};
