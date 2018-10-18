open Antd;
open Shared;

let component = ReasonReact.statelessComponent("WeekToolbar");

let make = (~appSend,  _children) => {

...component,
render: (_self) =>
 <Row type_="flex" gutter=4 style="toolbar">
      <Col span=6 offset=3 style="appTitle">
        <Icon type_="calendar" style="spacify" />( ReasonReact.string("Meeting Calendar") )
      </Col>
      <Col span=3 offset=8 style="alignRight">
        <Tooltip placement="topLeft" >
          <Button onClick=(_event => appSend(GOTOTODAY))>( ReasonReact.string("Today") )</Button>
        </Tooltip>
      </Col>

      <Col span=2 style="weekButtons">
        <Button  onClick=(_event => appSend(GOTOPREVIOUSWEEK))
        style="spacify" icon="left" />
        <Button onClick=(_event => appSend(GOTONEXTWEEK)) />
      </Col>

      <Col span=2 style="toolbarDate">

      </Col>

    </Row>
}



