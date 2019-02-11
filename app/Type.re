type newEvent = {
eventStart: option(MomentRe.Duration.t),
eventEnd: option(MomentRe.Duration.t),
startWeek: option(int),
endWeek: option(int)
}

type event = {
id: string,
eventName: string,
eventStart: option(MomentRe.Moment.t),
eventEnd: option(MomentRe.Moment.t),
startWeek: option(int),
endWeek: option(int)
}

type events = option(list(event))

type timeslot = {
time: MomentRe.Moment.t,
events: events
}

type timeslots = option(list(timeslot))

type weekday = {
date: string,
timeslots: timeslots
}

type weekdays = list(weekday)

type coordinate = {
top: string,
left: string,
height: string,
width: string
}
