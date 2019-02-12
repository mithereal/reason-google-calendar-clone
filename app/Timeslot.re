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

                     switch(timeslot.events){
                         | None =>  let ts:Type.newEvent = { start: Some(timeslot.time) };
                         <div style = Style.slotButton onClick=(_event => appSend(NEWEVENT(datestamp, ts))) />
                         | Some(e) =>  <div style = Style.eventButton onClick=(_event => appSend(EVENTMODALOPEN)) />
                                                    }



                 }

    </Col>

}