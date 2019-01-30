type state =
 | LOADING
 | LOADED

type action =
 | LOADINGSCREEN

let reducer = (action, _state) =>
      switch(action) {
       | LOADINGSCREEN => ReasonReact.Update(LOADED)
      }

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => LOADING,
  reducer,
  didMount: self => {
      self.send(LOADINGSCREEN)
    },
  render: (self) =>
  switch(self.state){
  | LOADING => <>
                <PageHeader />
                <div> ( ReasonReact.string("Loading... ") ) </div>
                <PageFooter />
               </>
  | LOADED => <>
                <PageHeader />
                <GoogleCalendar />
                <PageFooter />
               </>
  }
};