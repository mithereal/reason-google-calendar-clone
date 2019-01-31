open Shared;
open Antd;

let component = ReasonReact.statelessComponent("Timeslot");


let make = (~appSend, ~datestamp , ~time, ~events , _children) => {
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
                 switch(events){
                 | None =>  <div style = Style.slotButton onClick=(_event => appSend(EVENTMODALOPEN)) />
                 | Some(e) =>  <div style = Style.eventButton onClick=(_event => appSend(EVENTMODALOPEN)) />
                 }
                 }

    </Col>

}