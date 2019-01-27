open Antd;
open WeekShared;
let component = ReasonReact.statelessComponent("TimeSlotGroup");


let make = (~appSend, ~weekDays, ~time,  children) => {
...component,
render: (_self) =>
<div onClick=(_event => appSend(ONOPENADDEVENTMODAL))>
    <Row type_="flex" className=Styles.row>
      <Col className=Styles.timeCol span="3">
        <span className=Styles.timeString>
         (
         ReasonReact.string(Util.addTimeSuffix(time))
         )
        </span>

      </Col>

      (
                      ReasonReact.array(

                            Array.mapi(
                              (index: int, t: events) =>

                              switch(t){
                              | Some(x) =>   List.mapi((idx:int, item) =>
                                                                <Timeslot
                                                                 key=string_of_int(idx)
                                                                 time=item.eventStart
                                                                 appSend=appSend
                                                                />, x)
                                | None => None
                              }
                               ,
                            Util.getEventsinRange(children)
                           ),

                     )
         )


    </Row>
</div>
}