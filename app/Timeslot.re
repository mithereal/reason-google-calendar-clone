open Antd;
open WeekShared;
let component = ReasonReact.statelessComponent("Timeslot");


let make = (~appSend,  ~time, _children) => {
...component,
  render: (_self) =>
  <div onClick=(_event => appSend(ONOPENADDEVENTMODAL))>
    <Col
      span = "3"
    />
    </div>
}