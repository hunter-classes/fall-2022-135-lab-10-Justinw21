#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include "doctest.h"

Time time1 = {0,0};
Time time2 = {10,15};
TEST_CASE("A")
{
    CHECK(minutesSinceMidnight(time1) == 0);
    CHECK(minutesSinceMidnight(time2) == 615);
    CHECK(minutesUntil(time1, time2) == 615);
    CHECK(minutesUntil(time2, time1) == -615);
}

TEST_CASE("B")
{
    CHECK(addMinutes(time1, 100).h == 1);
    CHECK(addMinutes(time1, 100).m == 40);
    CHECK(addMinutes(time2, 40).h == 10);
    CHECK(addMinutes(time2, 40).m == 55);
}

TEST_CASE("C")
{
    Movie movie1 = {"Back to the Future", COMEDY, 15};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};
    CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (15 min) [starts at 9:15, ends by 9:30]");
    CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
    CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");
}

TEST_CASE("D")
{
    Movie movie1 = {"Back to the Future", COMEDY, 15};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}}; 
    CHECK(scheduleAfter(morning, movie1).startTime.h == 9);
    CHECK(scheduleAfter(morning, movie1).startTime.m == 30);
    CHECK(scheduleAfter(daytime, movie2).startTime.h == 14);
    CHECK(scheduleAfter(daytime, movie2).startTime.m == 29);
}

TEST_CASE("E")
{
    Movie movie1 = {"Back to the Future", COMEDY, 15};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot overlap1 = {movie1, {10, 00}};
    TimeSlot overlap2 = {movie2, {10, 15}};
    TimeSlot overlap3 = {movie1, {10, 14}};
    TimeSlot overlap4 = {movie2, {22, 00}};
    CHECK(timeOverlap(overlap1, overlap2) == 0);
    CHECK(timeOverlap(overlap1, overlap3) == 1);
    CHECK(timeOverlap(overlap3, overlap4) == 0);   
}