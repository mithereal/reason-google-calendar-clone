open Type;
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

let getAllDaysInTheWeek = (currentDate) => {

 let days_list = [0,1,2,3,4,5,6];

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

let evt_start = switch (event.eventStart) {
| None => None
| Some(e) => e
}

let evt_end = switch (event.eventEnd) {
| None => None
| Some(e) => e
}

let diff = diff(evt_end, evt_start)
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


let convertToTimeslots = (weekdays, times) => {

let momentTimes = List.map( t => MomentRe.Duration(t) , times )

let ts = List.map( w => {
               time: t,
               events: None
               }
               , weekdays )

Some(ts)
}

let sortbyTimeslots = (events, timeslots) => {

let evts = List.map( t => {
               time: t,
               events: None
               }
               , timeslots )

Some(evts)
}

let generateUniqueId = (title, e_start, e_end) => {
   title
}

let eventExist = (events,time) => {
false
}

let addEvent = (allEvents, newEvent) => {
   let time = MomentRe.Duration.hours(newEvent.e_start)

   let eventWithInfo = () => {
      ...newEvent ,
     startWeek: MomentRe.Duration.weeks(newEvent.e_start),
     endWeek: MomentRe.Duration.weeks(newEvent.e_end)

   }

   let complete_event = eventWithInfo()

   let eventexists = eventExist(allEvents, time)

   let newevents = switch(eventexists){
   | false => List.append(allEvents, [complete_event])
   | true => allEvents
   }

   newevents
}

