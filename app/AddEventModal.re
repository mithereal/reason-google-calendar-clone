type target = {
value: string
}

type event = {
target: target,
e_start: string,
e_end: string
}

 type state = {
    title: string,
    visable: bool,
    editMode: string
  }

  type action =
  | HANDLETITLECHANGE(event)
  | HANDLEOK
  | HANDLECLOSE
  | HANDLECANCEL
  | HANDLETIMECHANGE

  let component = ReasonReact.reducerComponent("AddEventModal");


let reducer = (action, state) =>
 switch(action) {
 | HANDLETITLECHANGE(event) => ReasonReact.Update({...state, title: event.target.value})
 | HANDLEOK => ReasonReact.Update({...state, visable: false})
 | HANDLECLOSE => ReasonReact.Update({...state, visable: false})
 | HANDLECANCEL => ReasonReact.Update({...state, visable: false})
 | HANDLETIMECHANGE => ReasonReact.Update({...state, visable: false})
}

let make = ( _children ) => {
  ...component,
  initialState: () => {title: "test", visable: false, editMode: "123"},
  reducer,
  render:  ({state,send}) =>
<div>

</div>
  };