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

	virtual ~Job();

	unsigned short getStartingTime() const;
	void set(const unsigned long aStartingTime);

	unsigned short getEndTime() const;
	void set(const unsigned long anEndTime);

	unsigned short getTotalDuration() const;
	void set(const unsigned long aTotalDuration);

private:
	unsigned long startingTime;
	unsigned long endTime;
	unsigned long totalDuration;
	std::vector<Task> taskVector;
};

#endif /* JOB_H_ */
