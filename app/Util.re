open Type;
open MomentRe;
open Duration;

module Format = {

let daynumber = (m) => {
MomentRe.Moment.format("d", m);
}

let dayname = (m) => {
MomentRe.Moment.format("dddd", m);
}

let daydate = (m) => {
MomentRe.Moment.format("Do", m);
}

let monthyear = (m) => {
MomentRe.Moment.format("MMM YYYY", m);
}
}

let weekstart = (m) => {
Moment.startOf(`week, m);
}

let getAllDatesInTheWeek = (currentDate) => {

 let days_list = [0,1,2,3,4,5,6];

 let dates = List.mapi((index: int, d: int) =>
 {
 let day = Moment.startOf(`week, currentDate);
 let duration = duration(d,`days);

 Moment.mutableAdd(day, duration);
 Moment.setMinute(0,day);
 Moment.setHour(0,day);


 let date:date = {
 date: daynumber(day),
 dateStamp: day,
 weekday: d,
 timeslots: None
 };

 date
}, days_list
 ) ;


dates
};


let isTodaysDate = (dateStamp) => {

let m = momentNow()

let now = Moment.setMinute(0,m);
let now1 = Moment.setSecond(0,now);
let today = Moment.setHour(0,now1);

let ds = Moment.setMinute(0,dateStamp);
let ds1 = Moment.setSecond(0,ds);
let query = Moment.setHour(0,ds1);

let diff = diff(query, today, `minutes)

switch( int_of_float(diff) == 0){
| false => false
| true => true
}
}

let addTimeSuffix = (time) => {
switch(time > 11){
| true => switch(time == 12){
        | true => string_of_int(time) ++ "pm"
         | false => switch(time == 24){
           | false => let ct = time - 12;
                      string_of_int(ct) ++ "pm"
           | true =>  let ct = time - 12;
                      string_of_int(ct) ++ "am"
         }

            }
| _ => string_of_int(time) ++ "am"
}
}


let convertToTimeslots = (times) => {

let momentTimes = List.map( t => t , times )

let ts = List.map( t => {
               time: t,
               events: None
               }
               , momentTimes )

Some(ts)
}

let sortbyTimeslots = (events, timeslots) => {

let ts = List.map( t => {
               time: t,
               events: None
               }
               , timeslots )

Some(ts)
}

let generateUniqueId = (title, e_start, e_end) => {
   title
}

let eventExist = (events,time) => {
false
}

