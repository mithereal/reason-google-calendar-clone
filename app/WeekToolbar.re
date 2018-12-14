open Antd;
open Shared;

let component = ReasonReact.statelessComponent("WeekToolbar");

let make = (~goToPreviousWeek, ~goToNextWeek, ~startDate, ~goToToday, _children) => {

...component,
render: (_self) =>
<div>

 <Row type_="flex" gutter=4 >
      <Col span=6 offset=3 >
        <Icon type_="calendar"  />( ReasonReact.string("Meeting Calendar") )
      </Col>
      <Col span=3 offset=8 >
        <Tooltip placement="topLeft" >
          <Button >( ReasonReact.string("Today") )</Button>
        </Tooltip>
      </Col>

      <Col span=2 >
        <Button
         icon="left" />
        <Button />
      </Col>

      <Col span=2 >
/*      formattedDate   */
      </Col>

    </Row>

</div>
}



