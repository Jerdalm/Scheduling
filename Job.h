/*
 * Job.h
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#ifndef JOB_H_
#define JOB_H_

#include <vector>
#include "Task.h"

class Job {
public:
	Job();
	Job(const Job& aJob);
	Job(unsigned short anID, const std::vector<Task>& aTaskVector);

	virtual ~Job();

	unsigned short getJobID() const;
	void setJobID(const unsigned short anJobID);

	unsigned long getStartingTime() const;
	void setStartingTime(const unsigned long aStartingTime);

	unsigned long getEndTime() const;
	void setEndTime(const unsigned long anEndTime);

	unsigned long getTotalDuration() const;
	void setTotalDuration(const unsigned long aTotalDuration);

	std::vector<Task> getTaskVector() const;
	void setTaskVector(const std::vector<Task> aVector);

	void CalculateSlack(unsigned short timeDuration);
	unsigned long getSlack() const;

	unsigned long getTaskVectorSize() const;

	unsigned long getNextFinishedTaskTime() const;
	void setNextFinishedTaskTime(const unsigned long aFinishedTaskTime);

	bool getAssigned() const;
	void setAssigned(const bool assignedState);

	unsigned short getTaskMachineNumber(const unsigned short aTaskNo);
	unsigned short getTimeDuration(const unsigned short aTaskNo);

	unsigned short Priority();

private:
	unsigned short jobID;
	bool assigned;
	unsigned short lastAssignedMachine;
	unsigned long startingTime;
	unsigned long endTime;
	unsigned long totalDuration;
	std::vector<Task> taskVector;
	unsigned short priorityNumber;
	unsigned long nextFinishedTaskTime;
	unsigned long slack;

};

#endif /* JOB_H_ */
