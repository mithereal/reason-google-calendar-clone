open Antd;
open Shared;

let component = ReasonReact.statelessComponent("WeekToolbar");

let make = (~goToPreviousWeek, ~goToNextWeek, ~startDate, ~goToToday, _children) => {

...component,
render: (_self) =>
<div>

 <Row type_="flex" gutter=4 style="toolbar">
      <Col span=6 offset=3 style="appTitle">
        <Icon type_="calendar" style="spacify" />( ReasonReact.string("Meeting Calendar") )
      </Col>
      <Col span=3 offset=8 style="alignRight">
        <Tooltip placement="topLeft" >
          <Button onClick=(_event => goToToday)>( ReasonReact.string("Today") )</Button>
        </Tooltip>
      </Col>

      <Col span=2 style="weekButtons">
        <Button  onClick=(_event => goToToday)
        style="spacify" icon="left" />
        <Button onClick=(_event => goToNextWeek) />
      </Col>

      <Col span=2 style="toolbarDate">
/*      formattedDate   */
      </Col>

    </Row>

</div>
}



