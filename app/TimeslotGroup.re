open Antd;

let component = ReasonReact.statelessComponent("TimeSlot");


let make = (~appSend, ~appState , ~days, ~time: string, children) => {


    <Row type_="flex" >
      <Col >
        <span >

        </span>
      </Col>

      children
    </Row>

}