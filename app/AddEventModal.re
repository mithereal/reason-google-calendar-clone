open Antd;
open WeekShared
open Util


type retainedProps = {title: string, editMode:string};

let component = ReasonReact.statelessComponentWithRetainedProps("AddEventModal");

let make = ( ~title, ~visible, ~eventStart, ~eventEnd,  ~appSend, ~editMode, _children ) => {
  ...component,
  retainedProps: {title: title, editMode: editMode},
    didUpdate: ({oldSelf, newSelf}) =>
      if (oldSelf.retainedProps.title !== newSelf.retainedProps.title) {
        /* do whatever sneaky imperative things here */
        Js.log("props `message` changed!")
      },
  render:  ({state,send}) =>
 <Modal
        visible=visible
        onOk=(_event => appSend(ONOKADDEVENTMODAL))
        onCancel=(_event => appSend(ONCLOSEADDEVENTMODAL))
        footer={[
          <Button key="back" onClick=(_event => appSend(ONCLOSEADDEVENTMODAL)) >
          (
                  switch(editMode){
                      | "delete" => "Delete"
                      | _ => "Cancel"
                      }

                      )
          </Button>,
          <Button key="submit"  onClick=(_event => appSend(ONOKADDEVENTMODAL))>
            (
        switch(editMode){
            | "update" => "Update Event"
            | _ => "Add Event"
            }

            )

          </Button>
        ]}

      >
        <AddEvent
          title=title
          start=eventStart
          evtend=eventEnd
          appSend=appSend
        />

        <DatePicker

        />
      </Modal>
  };