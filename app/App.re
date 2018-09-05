
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
  | LOADING => <div className=Styles.app>
                <Topbar />
                <div className=Styles.loading> ( ReasonReact.string("Loading... ") ) </div>
                <Footer />
               </div>
  | LOADED => <div className=Styles.app>
                <Topbar />
                <GoogleCalendar />
                <Footer />
               </div>
  }
};