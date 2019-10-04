/*
 * JobShop.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "JobShop.h"
#include <iostream>

unsigned long JobShop::currTime = 0;

JobShop::JobShop() {
}

JobShop::~JobShop() {
}

std::vector<Job> JobShop::getJobVector() {

	return jobVector;

}
void JobShop::setJobVector(const std::vector<Job> &aVector) {

	jobVector = aVector;

}

void JobShop::extractFile(const std::string &inputParameters) {
	//std::cout <<  inputParameters <<'\n';
	batchFile.open("Batches/" + inputParameters);

	if (!batchFile.is_open()) {
		std::cout << "something went wrong" << '\n';
	}

	getline(batchFile, line);
	std::istringstream iss(line);

	iss >> jobAmount >> machineAmount;
	//std::cout << line<<std::endl;

	while (getline(batchFile, line)) {
		std::istringstream iss(line);

		while (iss >> machineNumber) {
			iss >> timeDuration;
			taskVector.push_back(Task(machineNumber, timeDuration));
		}
		++currjobID;
		jobVector.push_back(Job(currjobID, taskVector));
		taskVector.clear();
	}
	batchFile.close();
}

void JobShop::generateOutput() {
	for (std::vector<Job>::iterator it = jobVector.begin();
			it != jobVector.end(); ++it) {
		std::cout << (*it).getJobID() << " " << (*it).getStartingTime() << " "
				<< (*it).getEndTime() << std::endl;
	}
}

void JobShop::criticalPathCalculation(std::vector<Job> &aJobVector) {

	for (Job &j : jobVector) {
		if (!j.getAssigned()) {
			{
				priorityList.push_back(j);
			}
		}

		// sort using a custom function object
		struct {
			bool operator()(Job A, Job B) const {
				return A.getSlack() < B.getSlack();
			}
		} customLess;
		std::sort(priorityList.begin(), priorityList.end(), customLess);
	}

}

void JobShop::jobAssigner() {
	Job *AssignableJob = nullptr;
	for (Job &j : priorityList) {
		{
			AssignableJob = &j;
			machineNr = AssignableJob->getTaskMachineNumber(1);

			if (machineVector[machineNr]) {
				AssignableJob->nextFinishedTaskTime = currTime
						+ AssignableJob->getTimeDuration(1);
				machineVector[machineNr] = false;
			}
		}
	}
}

void JobShop::jobDeassigner() {
	Job *nextDeassign = nullptr;

	for (Job &j : jobVector) {
		if (j.getNextFinishedTaskTime()
				< nextDeassign->getNextFinishedTaskTime()
				&& j.getAssigned() == true) {
			nextDeassign = &j;
		}
	}

	if (nextDeassign != nullptr) {
		currTime = nextDeassign->getNextFinishedTaskTime();
		nextDeassign->setNextFinishedTaskTime(0);
		nextDeassign->setAssigned(false);
		machineVector[machineNr] = true;
		if (nextDeassign->getTaskVectorSize() == 1) {
			nextDeassign->setEndTime(currTime);
		}
	}
}

bool JobShop::checkJobsFinished() {
	Job *currJobToCheck = nullptr;
	for (Job j : jobVector) {
		currJobToCheck = &j;
		if (currJobToCheck->getTaskVectorSize() == 1) {
			return false;
		}
	}
	return true;
}

void JobShop::solveAlgorithm() {

	while (checkJobsFinished()) {
		criticalPathCalculation();
		jobAssigner();
		jobDeassigner();
	}
}

