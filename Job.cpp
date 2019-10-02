/*
 * Job.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "Job.h"

Job::Job() :
jobID(0), assigned(false), lastAssignedMachine(0), startingTime(0), endTime(0), slack(0)
{
}

Job::Job(const Job& aJob) :
jobID(aJob.jobID), assigned(aJob.assigned), lastAssignedMachine(aJob.lastAssignedMachine),
startingTime(aJob.startingTime), endTime(aJob.endTime), slack(aJob.slack), taskVector(aJob.taskVector)
{
}

Job::Job(unsigned short anID, const std::vector<Task>& aTaskVector) :
jobID(anID), assigned(false), lastAssignedMachine(0), startingTime(0), endTime(0), slack(0), taskVector(aTaskVector)
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

unsigned long Job::getSlack() const {

	return slack;
}

void Job::setSlack(const unsigned long aSlack){

	slack = aSlack;
}

std::vector<Task> Job::getTaskVector() const{

	return taskVector;
}
void Job::setTaskVector(const std::vector<Task> aVector){

	taskVector = aVector;

}

unsigned long Job::CalculateMostSlack(unsigned short timeDuration)
{
	for(int i = 0; i < taskVector.size(); i++)
	{
		mostSlack += taskVector[1][i];
	}
}

const unsigned long Job::getMostSlack() const
{
	return mostSlack;
}

unsigned long Job::CalculateLeastSlack()
{
	for(int i = taskVector.size(); i < 0; i--)
	{
		//leastSlack =
	}
}

const unsigned long Job::getLeastSlack() const
{
	return mostSlack;
}
