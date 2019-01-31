type target = {
value: string
}

type event = {
eventName: string,
eventStart: string,
eventEnd: string,
target: option(target),
}

type events = option(list(event))

type timeslot = {
time: string,
events: events
}

type timeslots = option(list(timeslot))

type weekday = {
date: string,
timeslots: timeslots
}

type weekdays = list(weekday)