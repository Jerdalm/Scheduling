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
	Job(const std::vector<Task>& v);

	virtual ~Job();

	unsigned short getStartingTime() const;
	void setStartingTime(const unsigned long aStartingTime);

	unsigned short getEndTime() const;
	void setEndTime(const unsigned long anEndTime);

	unsigned short getTotalDuration() const;
	void setTotalDuration(const unsigned long aTotalDuration);

private:
	unsigned long startingTime;
	unsigned long endTime;
	unsigned long totalDuration;
	std::vector<Task> taskVector;
};

#endif /* JOB_H_ */
