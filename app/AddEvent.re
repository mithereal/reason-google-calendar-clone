open Antd;
open Shared;

let component = ReasonReact.statelessComponent("AddEvent");

let make = (~title , ~start: string, ~evtend: string,  ~onTitleChange, ~onTimeChange, _children) => {
...component,
render:  ({state,send}) =>
    <Fragment>

      <Input
        type_="text"
        placeholder="Add Title"
        value="title"

        size="large"
        onChange=(_event => onTitleChange)
      />

            <DatePicker

              value=""
              onChange=onTimeChange
              showTime=""
              format="MMM Do, YYYY hh:mm a"
            />

    </Fragment>

};
