open Antd;
open WeekShared

type target = {
value: string
}

type event = {
target: target,
e_start: string,
e_end: string
}

type retainedProps = {title: string};

let component = ReasonReact.statelessComponentWithRetainedProps("AddEventModal");

let make = ( ~title, ~visible, ~eventStart, ~eventEnd,  ~appSend, _children ) => {
  ...component,
  retainedProps: {title: title},
    didUpdate: ({oldSelf, newSelf}) =>
      if (oldSelf.retainedProps.title !== newSelf.retainedProps.title) {
        /* do whatever sneaky imperative things here */
        Js.log("props `message` changed!")
      },
  render:  ({state,send}) =>
 <Modal
        visible=visible
        onOk=(_event => appSend(ONCLOSEADDEVENTMODAL))
        onCancel=(_event => appSend(ONCLOSEADDEVENTMODAL))
        footer={[
          <Button key="back" onClick=(_event => appSend(ONCLOSEADDEVENTMODAL)) >
          /*  {this.props.editMode ? 'Delete' : 'Cancel'} */
          </Button>,
          <Button key="submit"  onClick=(_event => appSend(ONOKADDEVENTMODAL("x")))>
            /*  {this.props.editMode ? 'Update Event' : 'Add Event'} */
          </Button>,
        ]}
      >
        <AddEvent
          title=title
          start=eventStart
          evtend=eventEnd
          appSend=appSend
        />
      </Modal>
  };