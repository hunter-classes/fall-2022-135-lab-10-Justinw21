#include <iostream>
#include "time.h"
#include "timeslot.h"
#include "movie.h"

int minutesSinceMidnight(Time time)
{
    int hours = time.h;
    int minutes = time.m;
    int hourstoMinutes = hours * 60;
    int sum = hourstoMinutes + minutes;
    return sum;
}

int minutesUntil(Time earlier, Time later)
{
    int earlierMin = minutesSinceMidnight(earlier);
    int laterMin = minutesSinceMidnight(later);
    int difference = laterMin - earlierMin;
    return difference;
}

Time addMinutes(Time time0, int min)
{
    int timeMin = minutesSinceMidnight(time0);
    int totalMin = timeMin + min;
    int hours = totalMin/60;
    int minutes = totalMin % 60;
    Time result = {hours, minutes};
    return result;
}

std::string getMovie(Movie mv)
{
    std::string g;
    std::string result;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    result = mv.title + " " + g + " (" + std::to_string(mv.duration) + " min";
    return result;
}

std::string getTimeSlot(TimeSlot ts)
{
    std::string result;
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    result = getMovie(ts.movie) + ") [starts at " + std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m) + ", ends by " + std::to_string(endTime.h) + ":" + std::to_string(endTime.m) + "]";
    return result;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Time newTime = addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot result = {nextMovie, newTime};
    return result;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    int timeBetween = abs(minutesUntil(ts1.startTime, ts2.startTime));
    if(minutesUntil(ts1.startTime, ts2.startTime) > 0)
    {
        return timeBetween < ts1.movie.duration;
    }
    else
    {
        return timeBetween < ts2.movie.duration;
    }
        
}
