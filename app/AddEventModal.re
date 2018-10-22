open Antd;
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

let make = ( ~title, ~visible, ~onCancel, ~onClose, ~onOk, ~eventStart, ~eventEnd, ~onTimeChange, ~onTitleChange, _children ) => {
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
        onOk=onOk
        onCancel=onClose
        footer={[
          <Button key="back" onClick=onCancel >
          /*  {this.props.editMode ? 'Delete' : 'Cancel'} */
          </Button>,
          <Button key="submit"  onClick=onOk>
            /*  {this.props.editMode ? 'Update Event' : 'Add Event'} */
          </Button>,
        ]}
      >
        <AddEvent
          title=title
          start=eventStart
          evtend=eventEnd
          onTimeChange=onTimeChange
          onTitleChange=onTitleChange
        />
      </Modal>
  };