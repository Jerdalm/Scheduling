/*
 * Job.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "Job.h"

Job::Job() :
jobID(0), assigned(false), lastAssignedMachine(0), startingTime(0), endTime(0),
totalDuration(0), priorityNumber(0), nextFinishedTaskTime(0), slack(0)
{
}

Job::Job(const Job& aJob) :
jobID(aJob.jobID), assigned(aJob.assigned), lastAssignedMachine(aJob.lastAssignedMachine),
startingTime(aJob.startingTime), endTime(aJob.endTime), totalDuration(aJob.totalDuration), taskVector(aJob.taskVector),
priorityNumber(aJob.priorityNumber), nextFinishedTaskTime(aJob.nextFinishedTaskTime), slack(aJob.slack)
{
}

Job::Job(unsigned short anID, const std::vector<Task>& aTaskVector) :
jobID(anID), assigned(false), lastAssignedMachine(0), startingTime(0), endTime(0),
totalDuration(0), taskVector(aTaskVector), priorityNumber(anID), nextFinishedTaskTime(0), slack(0)
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

std::vector<Task> Job::getTaskVector() const{

	return taskVector;
}

void Job::setTaskVector(const std::vector<Task> aVector){

	taskVector = aVector;

}

void Job::CalculateSlack(unsigned short timeDuration)
{
	for(int i = 0; i < taskVector.size(); i++)
	{
		slack += taskVector[i].getTimeDuration();
	}
}

unsigned long Job::getSlack() const
{
	return slack;
}

unsigned long Job::getTaskVectorSize() const{

	return taskVector.size();
}

unsigned long Job::getNextFinishedTaskTime() const{

	return nextFinishedTaskTime;
}

void Job::setNextFinishedTaskTime(const unsigned long aFinishedTaskTime){

	nextFinishedTaskTime = aFinishedTaskTime;
}

bool Job::getAssigned() const{

	return (assigned);

}
void Job::setAssigned(const bool assignedState){

	assigned = assignedState;
}

unsigned short Job::getTaskMachineNumber(const unsigned short aTaskNo){

	return taskVector[aTaskNo].getMachineNumber();
}

unsigned short Job::Priority()
{
	return priorityNumber = jobID;
}
