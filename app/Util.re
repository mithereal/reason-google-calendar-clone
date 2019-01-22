open Moment;
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

let getAllDaysInTheWeek = () => {

let m = moment()

let currentDate = m.clone()

let weekStart = currentDate.startOf("week")

let days_list = [0,1,2,3,4,5,6]

 let days = List.mapi((index: int, d: int) =>
 {
 let week = moment(weekStart);
 let day = week.add(d, "days");
 day.set("minutes", 0);
 day.set("seconds", 0);

 day
}, days_list
 ) ;


let weeks = List.mapi((index: int, d: int) => {

}
,
days
);

weeks
};

let generateWeekViewCoordinates = (event, startDate) => {

let start = moment(event.e_start)
let evtend = moment(event.e_end)
let diff = diff(evtend, start)
let total_duration = duration(2)
let weekStart = moment(startDate)


}

let isTodaysDate = (dateStamp) => {
}