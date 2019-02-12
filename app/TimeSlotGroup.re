open Shared;

open Antd;

let component = ReasonReact.statelessComponent("TimeSlotGroup");


let make = (~appSend, ~dates:Type.dates,  ~time , _children) => {
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
                            List.map( day =>


                              <Timeslot
                                      key=string_of_int(MomentRe.Moment.toUnix(day.dateStamp))
                                      datestamp=day.dateStamp
                                      timeslot=day.timeslots[time]
                                      appSend=appSend
                              />
                               ,
                            dates
                           ),
                )
                     )



         )


    </Row>
}