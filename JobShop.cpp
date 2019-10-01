/*
 * JobShop.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "JobShop.h"
#include <iostream>
#include "Task.h"
#include "Job.h"


JobShop::JobShop() {
	// TODO Auto-generated constructor stub

}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}



void JobShop::extractFile(const std::string& inputParameters)
{
	//std::cout <<  inputParameters << '\n';
	batchFile.open("Batches/" + inputParameters);

	if (!batchFile.is_open())
	{
		std::cout << "something went wrong" << '\n';
	}

	getline(batchFile, line);
	std::istringstream iss(line);

	iss >> jobAmount >> machineAmount;
	std::cout << line;

	std::vector<Task> TaskVector;

	while (getline(batchFile, line))
	{
		std::istringstream iss(line);

		while (iss >> machineNumber)
		{
			iss >> timeDuration;
			TaskVector.push_back(Task(machineNumber, timeDuration));
		}
		Job(TaskVector);
		TaskVector.clear();
	}
	batchFile.close();
}

