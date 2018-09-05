

let component = ReasonReact.statelessComponent("Topbar");

let make = (_children) => {
...component,
render: (_self) =>
<header className=Styles.header>
      <a href="#">

      </a>
       <span className=Styles.title> {ReasonReact.string("Calendar")} </span>
      </header>
};
