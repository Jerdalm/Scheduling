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
	virtual ~Job();
	unsigned long CalculateLongestSlack(unsigned short timeDuration);
	const unsigned long getLongest() const;
	unsigned long CalculateLeastSlack();

private:
	unsigned long mostSlack;
	unsigned long leastSlack;
	std::vector<Task> vTask;
};

#endif /* JOB_H_ */
