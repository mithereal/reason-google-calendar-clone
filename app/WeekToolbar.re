open Antd;
open Util;
open WeekShared;

let component = ReasonReact.statelessComponent("WeekToolbar");

let make = (~appSend, _children) => {

...component,
didMount: self => {
let formattedDate = "test"
},
render: (_self) =>

<div>
 <Row type_="flex" gutter=4 >
      <Col span=6 offset=3 >
        <Icon type_="calendar"  />( ReasonReact.string("Meeting Calendar") )
      </Col>
      <Col span=3 offset=8  >
        <Tooltip placement="topLeft" >
          <Button onClick=(_event => appSend(GOTOTODAY))>( ReasonReact.string("Today") )</Button>
        </Tooltip>
      </Col>

      <Col span=2 >
        <Button
         icon="left"   />
        <Button onClick=(_event => appSend(GOTONEXTWEEK)) />
      </Col>

      <Col span=2 >
      ( ReasonReact.string("12-15-2018") )
/*      formattedDate   */
      </Col>

    </Row>

</div>
}



