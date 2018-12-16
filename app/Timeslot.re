open Antd;

let component = ReasonReact.statelessComponent("TimeSlot");


let make = (~openevt, ~dateStamp: string, ~time: string, _children) => {
...component,
  render: (_self) =>
    <Col

       key=dateStamp
      span="3"
    /* onClick=(_event => openevt(dateStamp, time)) */

    />
}