  open Css;

  let header = style([
    display(flexBox),
    flexDirection(column),
    alignItems(stretch),
    backgroundColor(white),
    boxShadow(~y=px(3), ~blur=px(5), rgba(0, 0, 0, 0.3)),

  ]);

  let title = style([
    fontSize(rem(1.5)),
    margin(auto),

  ]);

  let app = style([
    fontSize(rem(1.5)),
    background( darkgray ),
   height(vh(100.)),
  ]);


