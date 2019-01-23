let component = ReasonReact.statelessComponent("PageFooter");

let make = ( _children) => {
  ...component,
  render: (_self) => <div id="footer"> </div>
};