open MomentRe;
open Duration;

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

let weekstart = (m) => {
Moment.startOf(`week, m);
}


let times = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24];

type target = {
value: string
}

type event = {
target: target,
e_start: string,
e_end: string
}

type coordinate = {
top: string,
left: string,
height: string,
width: string
}

let days_list = [0,1,2,3,4,5,6];

let getAllDaysInTheWeek = (currentDate) => {

 let days = List.mapi((index: int, d: int) =>
 {
 let day = Moment.startOf(`week, currentDate);
 let duration = duration(d,`days);

 Moment.mutableAdd(day, duration);
 Moment.setMinute(0,day);
 Moment.setHour(0,day);

 day
}, days_list
 ) ;


days
};

let generateWeekViewCoordinates = (event, startDate) => {

let start = moment(event.e_start)
let evtend = moment(event.e_end)
let diff = diff(evtend, start)
let total_duration = duration(2)

let weekStart = moment(startDate)

 let timeFactor = 5;

 let top = "50%";
 let left = "50%";
 let height = "50%";
 let width = "50%";

  let coordinate:coordinate = {
      top: top,
      left: left,
      height: height,
      width: width
      };

coordinate;

}

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

let getEventsinRange = (e) => {
e
}
