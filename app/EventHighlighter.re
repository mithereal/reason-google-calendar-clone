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
 /* <AddEventModal
          editMode={true}
          eventTitle={this.props.event.title}
          visible={showEditEventModal}
          onCancel={this.deleteEvent}
          onClose={this.closeModal}
          onOk={this.updateEvent}
          eventStart={eventNewStart}
          eventEnd={eventNewEnd}
          onTimeChange={this.onCurrentEventTimeChange}
        />
        <div
          onClick={this.openEditEventModal}
          style={{
            ...generateWeekViewCoordinates (
              this.props.event,
              this.props.startDate
            ),
            ...eventHighlighter,
          }}
        >
          {this.props.event.title} <br />
          <span style={{fontSize: 10}}>
            {moment (this.props.event.start).format ('hh:mm a')}
            {' '}
            -
            {' '}
            {moment (this.props.event.end).format ('hh:mm a')}
          </span>
        </div>
        */
      </Fragment>
      </div>
  };