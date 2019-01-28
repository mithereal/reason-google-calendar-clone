open Antd;
open Style;

let component = ReasonReact.statelessComponent("WeekHeader");


let make = (~weekDays, _children) => {
...component,
render: (_self) =>
<Row type_="flex">
  <Col span=3 />
    (
                ReasonReact.array(
                   Array.of_list(
                      List.mapi(
                        (index: int, m: MomentRe.Moment.t) =>

                         <Col
                            key=(string_of_int(index))
                            span=3
                             style={
                             let ts = "timestamp"
                                    switch(Util.isTodaysDate(ts)){
                                    | true =>  weekDaysColSelected
                                    | false =>  weekDaysCol
                                    }
                                    } >
                            <p style=Style.weekDayName >
                            (
                            ReasonReact.string(Util.dayname(m))
                            )
                            </p>
                            <p style=Style.weekDates >
                            (
                            ReasonReact.string(Util.daydate(m))
                            )
                            </p>
                         </Col>

                         ,
                       weekDays,
                     ),
                 ),
               )
            )

</Row>
};

