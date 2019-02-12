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


  let col = style([
    border(px(1), solid, rgb(224,224,224)),
  ]);

  let dates = style([
   height(vh(100.)),
  ]);

  let weekDayName = style([
   lineHeight(px(32)),
   fontSize(px(12)),
   lineHeight(px(32)),
   textTransform(capitalize),
   color(rgb(117,117,117)),
   marginLeft(px(10)),
  ]);

  let container = style([
    paddingRight(em(10.0)),
     paddingTop(em(2.0)),
     paddingBottom(em(2.0)),
  ]);

  let weekDates = style([
      fontSize(px(40)),
      lineHeight(px(12)),
      color(rgb(158, 158, 158)),
      marginLeft(px(10)),
  ]);


 let slot = style([
  height(px(40)),
  
]);

 let timeCol = style([
  fontSize(px(10)),
  color(rgb(33, 33, 33)),
  
  padding(px(6)),
]);

 let timeString = style([
  position(absolute),
  right(px(8)),
  top(px(-8)),
]);

 let row = style([
  position(relative),
]);

 let toolbar = style([
  paddingBottom(px(10)),
]);

 let toolbarDate = style([
  fontSize(px(20)),
  fontWeight(400),
  opacity(0.54),
  lineHeight(px(30)),

]);

 let appTitle = style([
  fontSize(px(20)),
  fontWeight(400),
  lineHeight(px(30)),
]);

 let alignRight = style([
  
]);

 let spacify = style([
  marginRight(px(5)),
]);

 let inputStyles = style([
  marginTop(px(25)),
  marginBottom(px(15)),
]);

 let weekButtons = style([
  paddingRight(px(0)),
  paddingLeft(px(14)),
  textAlign(center),
]);

 let dateStyles = style([
  width(px(100)),
]);

 let lightHighlighter = style([
  backgroundColor(rgba(0,0,0,0.04)),
]);

 let eventHighlighter = style([
  position(absolute),
  backgroundColor(rgb(179,225,247)),
  border(px(1), solid, rgb(129,205,242)),
  borderRadius(px(4)),
  color(white),

  fontSize(px(12)),
  zIndex(1),
  
]);


