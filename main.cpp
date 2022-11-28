#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"
int main()
{
    //TASK A
    Time example = {10,20};
    Time example1 = {23,10};
    std::cout << minutesSinceMidnight(example) << std::endl;
    std::cout << minutesUntil(example, example1) << std::endl << minutesUntil(example1, example) << std::endl;

    //TASK B
    Time example2 = addMinutes(example, 20);
    std::cout << example2.h << " " << example2.m << std::endl;

    //TASK C
    Movie movie1 = {"Back to the Future", COMEDY, 15};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};

    std::cout << getTimeSlot(morning) << std::endl;
    std::cout << getTimeSlot(evening) << std::endl; 

    //TASK D
    TimeSlot ts = scheduleAfter(morning, movie2);
    std::cout << ts.startTime.h << ":" << ts.startTime.m << std::endl; 

    //TASK E 
    TimeSlot overlap1 = {movie1, {10, 00}};
    TimeSlot overlap2 = {movie2, {10, 15}};    
    std::cout << timeOverlap(overlap1, overlap2) << std::endl;
}