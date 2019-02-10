open Shared;
open Antd;

let component = ReasonReact.statelessComponent("TimeSlotGroup");


let make = (~appSend, ~weekDays:list(MomentRe.Moment.t),  ~timeslot:Type.timeslot , _children) => {
...component,
render: (_self) =>

    <Row type_="flex" style=Style.row >
      <Col style=Style.timeCol span=3>
        <span style=Style.timeString>
         (
         ReasonReact.string(Util.addTimeSuffix(int_of_string(timeslot.time)))
         )
        </span>

      </Col>

      (
                      ReasonReact.array(
                    Array.of_list(
                            List.map( day =>


                              <Timeslot
                                      key=string_of_int(MomentRe.Moment.toUnix(day))
                                      datestamp=day
                                      timeslot=timeslot
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