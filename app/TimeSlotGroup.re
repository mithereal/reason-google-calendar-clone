open Antd;
open WeekShared;
let component = ReasonReact.statelessComponent("TimeSlotGroup");


let make = (~appSend, ~weekDays:list(MomentRe.Moment.t), ~time,  ~events:events , _children) => {
...component,
render: (_self) =>

    <Row type_="flex" style=Style.row >
      <Col style=Style.timeCol span=3>
        <span style=Style.timeString>
         (
         ReasonReact.string(Util.addTimeSuffix(time))
         )
        </span>

      </Col>

      (
                      ReasonReact.array(
                    Array.of_list(
                            List.mapi(
                              (index: int, t) =>


                              <Timeslot
                                      key=string_of_int(MomentRe.Moment.toUnix(t))
                                      datestamp=t
                                      time=string_of_int(index + 1)
                                      events=events
                                      appSend=appSend
                              />
                               ,
                            weekDays
                           ),
                )
                     )



         )


    </Row>
}