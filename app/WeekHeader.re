open Antd;

let component = ReasonReact.statelessComponent("WeekHeader");

let make = (_children) => {
...component,
render: (_self) =>
<Row type_="flex">
      <Col span=3 />
    </Row>
};

