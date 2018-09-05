let component = ReasonReact.statelessComponent("Footer");

let make = ( _children) => {
  ...component,
  render: (_self) => <div id="footer"> </div>
};