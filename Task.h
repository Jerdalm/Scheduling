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
	/**
	 * Initialize a Task object with an machine number and time duration
	 * @param machineNumber
	 * @param timeDuration
	 */
	Task(unsigned short machineNumber, unsigned short timeDuration);
	/**
	 * copy-constructor for Task
	 * @param aTask
	 */
	Task(const Task& aTask);
	/**
	 * Deconstructor for Task
	 */
	virtual ~Task();
	/**
	 * returns machineNumber
	 */
	unsigned short getMachineNumber() const;
	/**
	 * sets machineNumber
	 * @param aMachineNumber
	 */
	void setMachineNumber(const unsigned short aMachineNumber);
	/**
	 * returns timeDuration
	 */
	unsigned short getTimeDuration() const;
	/**
	 * sets timeDuration
	 * @param aTimeDuration
	 */
	void setTimeDuration(const unsigned short aTimeDuration);

private:
unsigned short machineNumber;
unsigned short timeDuration;
};

#endif /* TASK_H_ */
