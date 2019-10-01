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

unsigned short getMachineNumber();
unsigned short getTimeDuration();

void setMachineNumber(unsigned short aMachineNumber);
void setTimeDuration(unsigned short aTimeDuration);

private:
unsigned short machineNumber;
unsigned short timeDuration;
};

#endif /* TASK_H_ */
