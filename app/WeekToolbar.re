open Shared;
open Util;
open Antd;

let component = ReasonReact.statelessComponent("WeekToolbar");

let make = (~appSend, ~formattedDate, _children) => {

...component,
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
         icon="left"
          onClick=(_event => appSend(GOTOPREVIOUSWEEK))
         />
        <Button
        icon="right"
        onClick=(_event => appSend(GOTONEXTWEEK))
        />
      </Col>

      <Col span=2 >
      ( ReasonReact.string(formattedDate) )
      </Col>

    </Row>

</div>
}



