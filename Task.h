/*
 * Task.h
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#ifndef TASK_H_
#define TASK_H_

#include <vector>

class Task {
public:
	Task(unsigned short machineNumber, unsigned short timeDuration);
	virtual ~Task();
	Task(Task& aTask);
	InsertIntoVector;


private:

};

#endif /* TASK_H_ */
