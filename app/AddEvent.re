open Antd;
open Shared;

let component = ReasonReact.statelessComponent("AddEvent");

let make = (~title , ~start: string, ~evtend: string,  ~onTitleChange, ~onTimeChange, _children) => {
...component,
render:  ({state,send}) =>
    <Fragment>

      <Input
        type_="text"
        placeholder="Add Title"
        value="title"
        style="inputStyles"
        size="large"
        onChange=(_event => onTitleChange)
      />

    </Fragment>

};
