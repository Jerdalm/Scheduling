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
	/**
	 * Initialises a Job object
	 */
	Job();
	/**
	 * Copy-constructor for Job
	 * @param aJob
	 */
	Job(const Job& aJob);
	/**
	 * Initialises a Job object with anID and a vector TaskVector.
	 * Within this vector are all the tasks with their duration and machine number.
	 * @param anID
	 * @param aTaskVector
	 */
	Job(unsigned short anID, const std::vector<Task>& aTaskVector);
	/**
	 * Destructor for Job
	 */
	virtual ~Job();
	/**
	 * Returns jobID
	 */
	unsigned short getJobID() const;
	/**
	 * Sets jobID
	 * @param anJobID
	 */
	void setJobID(const unsigned short anJobID);
	/**
	 * Returns startingTime
	 */
	unsigned long getStartingTime() const;
	/**
	 * Sets startingTime
	 * @param aStartingTime
	 */
	void setStartingTime(const unsigned long aStartingTime);
	/**
	 * Returns endTime
	 */
	unsigned long getEndTime() const;
	/**
	 * sets endTime;
	 * @param anEndTime
	 */
	void setEndTime(const unsigned long anEndTime);
	/**
	 * Returns totalDuration
	 */
	unsigned long getTotalDuration() const;
	/**
	 * Sets totalDuration
	 * @param aTotalDuration
	 */
	void setTotalDuration(const unsigned long aTotalDuration);
	/**
	 * Returns vector<Task> taskVector
	 * @return
	 */
	std::vector<Task> getTaskVector() const;
	/**
	 * Sets vector<Task> aVector
	 * @param aVector
	 */
	void setTaskVector(const std::vector<Task> aVector);
	/**
	 * Calculates slack for jobs
	 * @param timeDuration
	 */
	void CalculateSlack(unsigned short timeDuration);
	/**
	 * Calculates slack
	 * Returns slack
	 */
	unsigned long getSlack() const;
	/**
	 * Returns taskVectorSize
	 */
	unsigned long getTaskVectorSize() const;
	/**
	 * Returns nextFinishedTaskTime
	 */
	unsigned long getNextFinishedTaskTime() const;
	/**
	 * Sets nextFinishedTaskTime
	 * @param aFinishedTaskTime
	 */
	void setNextFinishedTaskTime(const unsigned long aFinishedTaskTime);
	/**
	 * Returns true or false for assigned
	 * @return
	 */
	bool getAssigned() const;
	/**
	 * Sets assigned
	 * @param assignedState
	 */
	void setAssigned(const bool assignedState);
	/**
	 * Returns taskMachineNumber
	 * @param aTaskNo
	 */
	unsigned short getTaskMachineNumber(const unsigned short aTaskNo);
	/**
	 * Returns timeDuration
	 * @param aTaskNo
	 */
	unsigned short getTimeDuration(const unsigned short aTaskNo);

	void deleteSolvedTask();


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
