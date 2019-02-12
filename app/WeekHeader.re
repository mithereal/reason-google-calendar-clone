open Antd;

let component = ReasonReact.statelessComponent("WeekHeader");


let make = (~dates, _children) => {
...component,
render: (_self) =>
<Row type_="flex">
  <Col span=3 />
    (
                ReasonReact.array(
                   Array.of_list(
                      List.mapi(
                        (index: int, date: Type.date) =>

                         <Col
                            key=(string_of_int(index))
                            span=3
                             style={
                                    switch(Util.isTodaysDate(date.date)){
                                    | true =>  Style.datesColSelected
                                    | false =>  Style.datesCol
                                    }
                                    } >
                            <p style=Style.weekDayName >
                            (
                            ReasonReact.string(Util.dayname(date.date))
                            )
                            </p>
                            <p style=Style.weekDates >
                            (
                            ReasonReact.string(Util.daydate(date.date))
                            )
                            </p>
                         </Col>

                         ,
                       dates,
                     ),
                 ),
               )
            )

</Row>
};

