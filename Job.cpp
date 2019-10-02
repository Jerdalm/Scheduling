/*
 * Job.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "Job.h"

Job::Job() :
startingTime(0), endTime(0), totalDuration(0)
{
}

Job::Job(const Job& aJob) :
startingTime(aJob.startingTime), endTime(aJob.endTime), totalDuration(aJob.totalDuration), taskVector(aJob.taskVector)
{
}

Job::Job(const std::vector<Task>& aTaskVector) :
startingTime(0), endTime(0), totalDuration(0), taskVector(aTaskVector)
{
}

Job::~Job()
{
}

unsigned short Job::getStartingTime() const {

	return startingTime;
}

void Job::setStartingTime(const unsigned long aStartingTime){

	startingTime = aStartingTime;
}

unsigned short Job::getEndTime() const {

	return endTime;
}

void Job::setEndTime(const unsigned long anEndTime){

	endTime = anEndTime;
}

unsigned short Job::getTotalDuration() const {

	return totalDuration;
}

void Job::setTotalDuration(const unsigned long aTotalDuration){

	totalDuration = aTotalDuration;
}

