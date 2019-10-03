/*
 * Task.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "Task.h"

Task::Task(unsigned short aMachineNumber, unsigned short aTimeDuration) :
machineNumber(aMachineNumber), timeDuration(aTimeDuration)
{

}

Task::Task(const Task& aTask) :
machineNumber(aTask.machineNumber), timeDuration(aTask.timeDuration)
{
}

Task::~Task()
{
}

unsigned short Task::getMachineNumber() const {

	return machineNumber;
}

unsigned short Task::getTimeDuration() const {

	return timeDuration;
}

void Task::setMachineNumber(const unsigned short aMachineNumber){

	machineNumber = aMachineNumber;

}

unsigned short Task::getMachineNumber()
{
	return machineNumber;
}

void Task::setTimeDuration(const unsigned short aTimeDuration){

	timeDuration = aTimeDuration;
}





