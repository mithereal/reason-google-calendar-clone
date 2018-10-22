open Antd;

let component = ReasonReact.statelessComponent("TimeSlot");


let make = (~appSend, ~dateStamp: string, ~time: string, _children) => {
...component,
  render: (_self) =>
  <div>

    <Col
    /*
      key_="dateStamp"

      onClick=(_event => appSend(OPENADDEVENTMODAL(dateStamp, time)))
      */
    />

    </div>
}