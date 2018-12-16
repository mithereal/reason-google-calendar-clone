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

let getAllDaysInTheWeek = () => {


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