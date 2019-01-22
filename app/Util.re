open MomentRe;
open Duration;

let times = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 ];

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

let m = switch(currentDate){
| _ => momentNow()
}

 let days = List.mapi((index: int, d: int) =>
 {
 let day = Moment.startOf(`week, m);
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

let today = momentNow();
let dateStamp = moment(dateStamp);
let ddiff = diff(today, dateStamp);
let dur = duration(0, `days);
let return = switch(today == dateStamp){
             | true => true
             | _ => false
}

return;

}