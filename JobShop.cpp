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
	std::cout << "assignerstart" << std::endl;
	Job *AssignableJob = nullptr;
	for (Job &j : priorityList) {
		{
			std::cout << "assignerloop" << std::endl;
			AssignableJob = &j;
			if (AssignableJob->getTaskVectorSize() >= 1) {
				machineNr = AssignableJob->getTaskMachineNumber(1);
				std::cout << "nnumber "+machineNr << std::endl;
			}
			if (machineVector[machineNr]) {
				std::cout << "machineVector[machineNr]" << std::endl;
				AssignableJob->setNextFinishedTaskTime(
						currTime + AssignableJob->getTimeDuration(1));
				std::cout << "currtime"+currTime + AssignableJob->getTimeDuration(1)
						<< std::endl;
				machineVector[machineNr] = false;
			}
		}
	}
}

//std::cout << "reeeeee3" << std::endl;

//	Job *nextDeassign = nullptr;
//	for(Job &aj : jobVector){
//		if( aj.getAssigned()){
//			nextDeassign = &aj;
//			break;
//		}
//	void JobShop::jobDeassigner()
//	{
//unsigned short nextDeassign;

void JobShop::jobDeassigner() {
	std::cout << "deassignStart" << std::endl;
	unsigned long nextDeassign = JobNumber;
	for (int i = 0; i < jobVector.size(); ++i) {
		std::cout << "loopJVecDEASSIGN" << std::endl;
		if (jobVector[i].getNextFinishedTaskTime() < nextDeassign
				&& jobVector[i].getAssigned() == true) {
			nextDeassign = i;
		}
	}
	std::cout << "setCURRtime" << std::endl;
	currTime = jobVector[nextDeassign].getNextFinishedTaskTime();
	std::cout << "setNEXTtaskTIME" << std::endl;
	jobVector[nextDeassign].setNextFinishedTaskTime(0);
	std::cout << "setASSIGNED" << std::endl;
	jobVector[nextDeassign].setAssigned(false);
	std::cout << "machineVector[machineNr]==true" << std::endl;
	machineVector[machineNr] = true;
	std::cout << "deletesolvedtaskbegin" << std::endl;
	if(jobVector[nextDeassign].getTaskVectorSize() != 0){
	jobVector[nextDeassign].deleteSolvedTask();
	std::cout << "deletesolvedtask" << std::endl;
	}
	if (jobVector[nextDeassign].getTaskVectorSize() == 0) {
		std::cout << "SETendTIME" << std::endl;
		jobVector[nextDeassign].setEndTime(currTime);
		std::cout << currTime << std::endl;
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
	Job *currJobToCheck = nullptr;
	for (Job j : jobVector) {
		std::cout << "loopjobVector" << std::endl;
		currJobToCheck = &j;
		if (currJobToCheck->getTaskVectorSize() >= 1) {
			std::cout << "algorithmeloop" << std::endl;

			return true;
		}
	}
	std::cout << "breakoutofalgorihtm" << std::endl;
	return false;
}

void JobShop::solveAlgorithm() {

	while (checkJobsFinished()) {

		criticalPathCalculation(jobVector);
		std::cout << "critpath" << std::endl;
		jobAssigner();
		std::cout << "assign" << std::endl;
		jobDeassigner();
		std::cout << "DEassign" << std::endl;
	}
}

