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

Task::Task(Task& aTask) :
machineNumber(aTask.machineNumber), timeDuration(aTask.timeDuration)
{
}

Task::~Task()
{
}

unsigned short Task::getMachineNumber(){

	return machineNumber;
}

unsigned short Task::getTimeDuration(){

	return timeDuration;
}

void Task::setMachineNumber(unsigned short aMachineNumber){

	machineNumber = aMachineNumber;

}
void Task::setTimeDuration(unsigned short aTimeDuration){

	timeduration = aTimeDuration;
}





