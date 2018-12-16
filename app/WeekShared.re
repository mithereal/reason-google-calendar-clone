type action =
| GOTONEXTWEEK
| GOTOPREVIOUSWEEK
| GOTOTODAY
| ONOKADDEVENTMODAL(string)
| ONCLOSEADDEVENTMODAL
| ONCURRENTEVENTTIMECHANGE
| ONTITLECHANGE


type state = {
startDate: string,
weekDays: string,
showAddEventModal: bool,
eventStart: string,
eventEnd: string,
}

let reducer = (action, state) =>
                     switch(action) {
                     | GOTONEXTWEEK => ReasonReact.Update({...state, showAddEventModal: false})
                     | ONCLOSEADDEVENTMODAL => ReasonReact.Update({...state, showAddEventModal: false})
                     | ONCURRENTEVENTTIMECHANGE => ReasonReact.Update({...state, showAddEventModal: false})
                     | GOTOPREVIOUSWEEK => ReasonReact.Update({...state, showAddEventModal: false})
                     | GOTOTODAY => ReasonReact.Update({...state, showAddEventModal: false})
                     | ONOKADDEVENTMODAL(title) => ReasonReact.Update({...state, showAddEventModal: false})
                     };