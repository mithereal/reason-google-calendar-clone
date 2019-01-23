open Antd;

let component = ReasonReact.statelessComponent("Timeslot");


let make = (~appSend, ~key, ~time, _children) => {
...component,
  render: (_self) =>
    <Col
      key = key
      span = "3"
    />
}