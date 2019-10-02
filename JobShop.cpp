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



JobShop::JobShop()
{
	// TODO Auto-generated constructor stub

}

JobShop::~JobShop()
{
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

	while (getline(batchFile, line))
	{
		std::istringstream iss(line);

		while (iss >> machineNumber)
		{
			iss >> timeDuration;
			taskVector.push_back(Task(machineNumber, timeDuration));
		}
		Job(taskVector);
		taskVector.clear();
	}
	batchFile.close();
}

void JobShop::OrderJobs()
{

//	for(int i = 0; i < jobVector.size(); i++)
//	{

		priorityMap.insert ( std::pair<unsigned short,unsigned short>(1,1) ); //(i,jobVector[i])

//	}


	struct setLongest
	{
		template<typename N>
		bool operator()(const N& l, const N& r) const
		{
			if (l.second != r.second)
				return l.second < r.second;

			return l.first < r.first;
		}
	};


	std::set<std::pair<unsigned short,unsigned short>, setLongest> set(priorityMap.begin(), priorityMap.end());

}

std::map JobShop::getOrderJobs()
{
	return priorityMap;
}


