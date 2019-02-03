open Shared;
open Antd;

let component = ReasonReact.statelessComponent("Timeslot");


let make = (~appSend, ~datestamp , ~timeslot: Type.timeslot , _children) => {
...component,
  render: (_self) =>

    <Col
      span = "3"
       style={
             switch(Util.isTodaysDate(datestamp)){
             | true =>  Style.slotSelected
             | false =>  Style.slot
             }
             }
    >
    {

      switch(timeslot){
                     | None =>  <div style = Style.slotButton onClick=(_event => appSend(NEWEVENT(datestamp, timeslot.time , "0"))) />
                     | Some(e) =>
                     switch(timeslot.events){
                         | None =>  <div style = Style.slotButton onClick=(_event => appSend(NEWEVENT(datestamp, timeslot.time , "0"))) />
                         | Some(e) =>  <div style = Style.eventButton onClick=(_event => appSend(EVENTMODALOPEN)) />
                                                    }
                     }


                 }

    </Col>

}