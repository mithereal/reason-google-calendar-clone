open Shared;
open Antd;

let component = ReasonReact.statelessComponent("TimeSlotGroup");


let make = (~appSend, ~weekDays:list(MomentRe.Moment.t), ~time,  ~timeslots:Type.timeslots , _children) => {
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
                              (index: int, day) =>


                              <Timeslot
                                      key=string_of_int(MomentRe.Moment.toUnix(day))
                                      datestamp=day
                                      time=string_of_int(time)
                                      events=None
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