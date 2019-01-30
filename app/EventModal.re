open Shared;
open Util;
open Antd;


type retainedProps = {title: string, editMode:string};

let component = ReasonReact.statelessComponentWithRetainedProps("EventModal");

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
        onOk=(_event => appSend(EVENTMODALOK))
        onCancel=(_event => appSend(EVENTMODALOK))
        footer={[
          <Button key="back" onClick=(_event => appSend(EVENTMODALOK)) >
          (
                  switch(editMode){
                      | "delete" => "Delete"
                      | _ => "Cancel"
                      }

                      )
          </Button>,
          <Button key="submit"  onClick=(_event => appSend(EVENTMODALOK))>
            (
        switch(editMode){
            | "update" => "Update Event"
            | _ => "Add Event"
            }

            )

          </Button>
        ]}

      >
        <Event
          title=title
          start=eventStart
          evtend=eventEnd
          appSend=appSend
        />

        <DatePicker
        style=Style.datePicker
        value=[]
        showTime=[]
        format="MMM Do, YYYY hh:mm a"

        />
      </Modal>
  };