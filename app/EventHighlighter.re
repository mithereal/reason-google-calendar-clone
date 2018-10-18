type state = {
    showEditEventModal: bool,
    eventNewStart: option(string),
    eventNewEnd: option(string),
  };

  type action =
| DELETEEVENT
| UPDATEEVENT(string,string)
| OPENEDITEVENTMODAL(string,string)
| ONCURRENTEVENTTIMECHANGE(string)
| CLOSEMODAL

let reducer = (action, state) =>
 switch(action) {
 | DELETEEVENT => ReasonReact.Update({...state, showEditEventModal: false})
 | UPDATEEVENT(eventNewStart, eventNewEnd) => ReasonReact.Update({...state, showEditEventModal: false, eventNewStart: Some(eventNewStart), eventNewEnd: Some(eventNewEnd) })
 | OPENEDITEVENTMODAL(eventNewStart, eventNewEnd) => ReasonReact.Update({...state, showEditEventModal: true, eventNewStart: Some(eventNewStart), eventNewEnd: Some(eventNewEnd) })
 | ONCURRENTEVENTTIMECHANGE(dates) => let evt_start = "";
                                      let evt_end = "";
  ReasonReact.Update({...state, eventNewStart: Some(evt_start), eventNewEnd: Some(evt_end) })
 | CLOSEMODAL => ReasonReact.Update({...state, showEditEventModal: false})
}

let component = ReasonReact.reducerComponent("EventHighlighter");

let make = (~event , ~startDate, ~endDate, _children) => {
  ...component,
  initialState: () => { showEditEventModal: false, eventNewStart: None, eventNewEnd: None },
  reducer,
  render:  ({state,send}) =>
<div>
      <Fragment>

           <br />
          <span >



          </span>

      </Fragment>
      </div>
  };