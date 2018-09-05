  let card = style([
    display(flexBox),
    flexDirection(column),
    alignItems(stretch),
    backgroundColor(white),
    boxShadow(~y=px(3), ~blur=px(5), rgba(0, 0, 0, 0.3)),

  ]);

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

  let actionButton = disabled =>
    style([
      background(disabled ? darkgray : white),
      color(black),
      border(px(1), solid, black),
      borderRadius(px(3)),
    ])

  let body = style([
  margin: 0;
  padding: 0;
  font-family: sans-serif;
  ]);

  let col = style([
     border: '#e0e0e0 1px solid',

  ]);

  let weekDays = style([
     height: 100,

  ]);

  let weekDayName = style([
       fontSize: 12,
       lineHeight: '32px',
       textTransform: 'capitalize',
       color: '#757575',
       marginLeft: 10,

  ]);

  let container = style([
       paddingRight: '10em',
       paddingTop: '2em',
       paddingBottom: '2em',

  ]);

  let weekDates = style([
         fontSize: 40,
         lineHeight: '12px',
         color: '#9e9e9e',
         marginLeft: 10,

  ]);

  let slot = style([
  height: 40,
  cursor: 'pointer',

  ]);

  let timeCol = style([
    fontSize: 10,
    color: '#212121',
    textAlign: 'right',
    padding: 6,

  ]);

  let timeString = style([
      position: 'absolute',
      right: 8,
      top: -8,

  ]);

  let row = style([
        position: 'relative',

  ]);

  let toolbar = style([
       paddingBottom: 10,

  ]);

  let toolbarDate = style([
        fontSize: 20,
         fontWeight: 400,
         opacity: 0.54,
         lineHeight: '30px',
         textAlign: 'right',

  ]);

  let appTitle = style([
  fontSize: 20,
  fontWeight: 400,
  lineHeight: '30px',

  ]);

  let alignRight = style([
  textAlign: 'right',

  ]);

  let spacify = style([
  marginRight: 5,

  ]);


  let inputStyles = style([
  marginTop: 25,
  marginBottom: 15,

  ]);

  let weekButtons = style([
  paddingRight: 0,
  paddingLeft: 14,
  textAlign: 'center',
  ]);

  let lightHighlighter = style([
  backgroundColor: 'rgba(0,0,0,0.04)',
  ]);

  let eventHighlighter = style([
   position: 'absolute',
   backgroundColor: '#b3e1f7',
   border: '1px solid #81cdf2',
   borderRadius: '4px',
   color: 'white',
   padding: '2px 4px',
   fontSize: '12px',
   zIndex: 1,
   cursor: 'pointer',
  ]);
