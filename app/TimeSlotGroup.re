open Antd;

let component = ReasonReact.statelessComponent("TimeSlotGroup");


let make = (~appSend, ~weekDays, ~time, children) => {
...component,
render: (_self) =>

    <Row type_="flex" className=Styles.row>

      <Col className=Styles.timeCol span="3">
        <span className=Styles.timeString>
         (
         ReasonReact.string(string_of_int(time))
         )
        </span>
      </Col>

      (
                      ReasonReact.array(
                         Array.of_list(
                            List.mapi(
                              (index: int, t: int) =>

                                        <Timeslot
                                                  key="5"
                                                  time=""
                                                  appSend=appSend
                                                />
                               ,
                             children
                           ),
                       ),
                     )
         )


    </Row>

}