let component = ReasonReact.reducerComponent("WeekView");

type ACTION =
|

let reducer = (action, _state) =>
      switch(action) {

      }

let goToNextWeek () => {

}

let goToPreviousWeek () => {

}

let goToToday () => {

}

let openAddEventModal (dateStamp, tim) => {

}

let onCloseAddEventModal () => {

}

let onOkAddEventModal (title) => {

}

let onCurrentEventTimeChange (dates) => {

}

let make = ( _children) => {
  ...component,
  render: ({state,self}) => <div className="container">
  <AddEventModal visible={showAddEventModal}
                           onCancel=self.onCloseAddEventModal
                           onClose=self.onCloseAddEventModal
                           onOk=self.onOkAddEventModal
                           eventStart=state.eventStart
                           eventEnd=state.eventEnd
                           onTimeChange=self.onCurrentEventTimeChange
                           />
  <WeekToolbar goToPreviousWeek=goToPreviousWeek
                         goToNextWeek=self.goToNextWeek
                         startDate=state.startDate
                         goToToday=self.goToToday
                         />
  <WeekHeader weekDays=state.weekDays />
   </div>
};