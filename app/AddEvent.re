open Antd;
open Shared;

let component = ReasonReact.statelessComponent("AddEvent");

let make = (~appSend, ~title , ~start: string, ~eend: string, ~time: string, _children) => {
...component,
render:  ({state,send}) =>
    <Fragment>

      <Input
        type_="text"
        placeholder="Add Title"
        value="title"
        style="inputStyles"
        size="large"
        onChange=(_event => appSend(ONTITLECHANGE))
      />

    </Fragment>

};
