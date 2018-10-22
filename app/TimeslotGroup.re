open Antd;

let component = ReasonReact.statelessComponent("TimeSlot");


let make = (~appSend, ~appState , ~days, ~time: string, children) => {
let formattedTime = "";

    <Row type_="flex" >
      <Col style="timeCol" span="3">
        <span >
/* formattedTime */
        </span>
      </Col>

      children
    </Row>

}