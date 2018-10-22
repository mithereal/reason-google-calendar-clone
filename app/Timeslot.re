open Antd;

let component = ReasonReact.statelessComponent("TimeSlot");


let make = (~appSend, ~dateStamp: string, ~time: string, _children) => {
...component,
  render: (_self) =>
    <Col

       /* key_=dateStamp */
      span="3"
     /*  onClick=(_event => appSend(OPENADDEVENTMODAL(dateStamp, time))) */

    />
}