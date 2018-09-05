open MomentRe;

let times = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, ];

let generateWeekViewCoordinates = (event, startDate) => {
let start = Moment(event.start)
let end = Moment(event.end)
let duration = Moment.duration(end.diff(start))
let weekStart = Moment(startDate)

let top = start.minutes() == 30 ? '50%' : '0%'
let timeFactor = duration.hours() + duration.minutes() / 60
let height = timeFactor * 100

let weekDay = weekStart.week() == start.week() ? start.weekday() : 0
let daysDiff =  weekStart.week() == start.week() && weekStart.week() == end.week() ? duration.days() : 0

let left = (weekDay + 1) * 12.5
let width = (daysDiff + 1) * 12.5 - 2



}

let getAllDaysInTheWeek = (currentDate = Moment()) => {
    let date = currentDate.clone()
    let weekStart = date.startOf('week')

    let dates_array = [|0,1,2,3,4,5,6|]

    let days = dates_array.map( a =>
     let ws = moment(weekStart)
     let ds = ws.add(day, 'days')
     ds.set('minutes', 0)
     ds.set('seconds', 0)
     ds
      )

      let result = days.map(a =>
      {
         date: a.date(),
         dateStamp: a,
         weekDayName: a.format ('ddd'),
      }
      )

      result
}

let isTodaysDate = (dateStamp) => {
    let today = Moment()
    let dateStamp = Moment(dateStamp)

    let duration = Moment.duration(dateStamp.diff(today))

    let dresult = duration == 0
    let tresult =  today.day() == dateStamp.day

    let results = [dresult,tresult]

    let reply =
      switch (results) {
      [true,true] => true
      _=> false
      }

      reply
}

