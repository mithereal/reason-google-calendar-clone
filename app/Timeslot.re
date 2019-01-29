open Antd;
open WeekShared;
let component = ReasonReact.statelessComponent("Timeslot");


let make = (~appSend,  ~datestamp ,~time, _children) => {
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
<div style = Style.slotButton onClick=(_event => appSend(ONOPENADDEVENTMODAL)) />
    </Col>

}