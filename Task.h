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
	Task(const Task& aTask);

	virtual ~Task();

	unsigned short getMachineNumber() const;
	void setMachineNumber(const unsigned short aMachineNumber);

	unsigned short getTimeDuration() const;
	void setTimeDuration(const unsigned short aTimeDuration);

private:
unsigned short machineNumber;
unsigned short timeDuration;
};

#endif /* TASK_H_ */
