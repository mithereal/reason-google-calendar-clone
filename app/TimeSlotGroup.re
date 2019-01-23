open Antd;

let component = ReasonReact.statelessComponent("TimeSlotGroup");


let make = (~appSend, ~weekDays, ~time, _children) => {
...component,
render: (_self) =>

    <Row type_="flex" >

      <Col className=Styles.timeCol span="3">
        <span className=Styles.timeString>
         (
         ReasonReact.string(string_of_int(time))
         )
        </span>
      </Col>



    </Row>

}