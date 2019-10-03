/*
 * Job.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "Job.h"

Job::Job() :
jobID(0), assigned(false), lastAssignedMachine(0), startingTime(0), endTime(0), totalDuration(0), priorityNumber(0)
{
}

Job::Job(const Job& aJob) :
jobID(aJob.jobID), assigned(aJob.assigned), lastAssignedMachine(aJob.lastAssignedMachine), startingTime(aJob.startingTime), endTime(aJob.endTime), totalDuration(aJob.totalDuration), taskVector(aJob.taskVector), priorityNumber(aJob.priorityNumber)
{
}

Job::Job(unsigned short anID, const std::vector<Task>& aTaskVector) :
jobID(anID), assigned(false), lastAssignedMachine(0), startingTime(0), endTime(0), totalDuration(0), taskVector(aTaskVector), priorityNumber(anID)
{
}

Job::~Job()
{
}

unsigned short Job::getJobID() const{

	return jobID;
}
void Job::setJobID(const unsigned short anJobID){

	jobID = anJobID;
}

unsigned long Job::getStartingTime() const {

	return startingTime;
}

void Job::setStartingTime(const unsigned long aStartingTime){

	startingTime = aStartingTime;
}

unsigned long Job::getEndTime() const {

	return endTime;
}

void Job::setEndTime(const unsigned long anEndTime){

	endTime = anEndTime;
}

unsigned long Job::getTotalDuration() const {

	return totalDuration;
}

void Job::setTotalDuration(const unsigned long aTotalDuration){

	totalDuration = aTotalDuration;
}

std::vector<Task> Job::getTaskVector() const{

	return taskVector;
}
void Job::setTaskVector(const std::vector<Task> aVector){

	taskVector = aVector;

}

unsigned long Job::CalculateSlack(unsigned short timeDuration)
{
	for(int i = 0; i < taskVector.size(); i++)
	{
		mostSlack += taskVector[i].getTimeDuration();
	}
}

const unsigned long Job::getSlack() const
{
	return mostSlack;
}

unsigned short Job::Priority()
{
	return priorityNumber = jobID;
}
