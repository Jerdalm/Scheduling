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
	batchFile.open(inputParameters);

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
	//std::cout << "reeeeee1" << std::endl;
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
	//std::cout << "reeeeee2" << std::endl;
	Job *AssignableJob = nullptr;
	for (Job &j : priorityList) {
		{
			AssignableJob = &j;
			machineNr = AssignableJob->getTaskMachineNumber(1);

			if (machineVector[machineNr]) {
				AssignableJob->setNextFinishedTaskTime(
						currTime + AssignableJob->getTimeDuration(1));
				machineVector[machineNr] = false;
			}
		}
	}
}

void JobShop::jobDeassigner() {
	//std::cout << "reeeeee3" << std::endl;
	unsigned long nextDeassign = JobNumber;
//	Job *nextDeassign = nullptr;
//	for(Job &aj : jobVector){
//		if( aj.getAssigned()){
//			nextDeassign = &aj;
//			break;
//		}
//	void JobShop::jobDeassigner()
//	{
	//unsigned short nextDeassign;
	for (int i = 0; i < jobVector.size(); ++i) {
		if (jobVector[i].getNextFinishedTaskTime() < nextDeassign
				&& jobVector[i].getAssigned() == true) {
			nextDeassign = i;
		}
	}
	//std::cout<< "reeeeTIETENeeeeeeeeeee"<<std::endl;
	currTime = jobVector[nextDeassign].getNextFinishedTaskTime();
	//std::cout<< "reeeeTIETENe"<<std::endl;
	jobVector[nextDeassign].setNextFinishedTaskTime(0);
	//std::cout<< "reeeeTIETENe"<<std::endl;
	jobVector[nextDeassign].setAssigned(false);
	jobVector[nextDeassign].
	//std::cout<< "reeeeTIETEN"<<std::endl;
	if (jobVector[nextDeassign].getTaskVectorSize() == 1) {
		jobVector[nextDeassign].setEndTime(currTime);
		//std::cout<< "reeeeTIETENNNNNNNNNNN"<<std::endl;
	}
}

//for (int i; i<jobVector.size(); ++i){
//
//		if (jobVector[i].getNextFinishedTaskTime()
//				< nextDeassign
//				&& jobVector[i].getAssigned() == true) {
//			std::cout<< "reeeeee3eneenhalf"<<std::endl;
//			nextDeassign = jobVector[i].getNextFinishedTaskTime();
//		}
//	}
//	std::cout<< "reeeeTIETENe"<<std::endl;
//		currTime = nextDeassign->getNextFinishedTaskTime();
//		nextDeassign->setNextFinishedTaskTime(0);
//		nextDeassign->setAssigned(false);
//		machineVector[machineNr] = true;
//		if (nextDeassign->getTaskVectorSize() == 1) {
//			nextDeassign->setEndTime(currTime);
//			std::cout<< "reeeeee666"<<std::endl;
//		}
//	}

bool JobShop::checkJobsFinished() {
	//std::cout << "reeeeee5" << std::endl;
	Job *currJobToCheck = nullptr;
	for (Job j : jobVector) {
		currJobToCheck = &j;
		if (currJobToCheck->getTaskVectorSize() >= 1) {
			return true;
		}
	}
	return false;
}

void JobShop::solveAlgorithm() {

	while (checkJobsFinished()) {
		//std::cout << "reeeeee" << std::endl;
		criticalPathCalculation(jobVector);
		jobAssigner();
		jobDeassigner();
	}
}

