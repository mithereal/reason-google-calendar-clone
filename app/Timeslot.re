open Antd;

let component = ReasonReact.statelessComponent("Timeslot");


let make = (~appSend,  _children) => {
...component,
  render: (_self) =>
    <Col
      span = "3"
    />
}