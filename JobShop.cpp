/*
 * JobShop.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "JobShop.h"
#include <iostream>

JobShop::JobShop()
{
}

JobShop::~JobShop()
{
}

std::vector<Job> JobShop::getJobVector(){

	return jobVector;

}
void JobShop::setJobVector(const std::vector<Job>& aVector){

	jobVector = aVector;

}

void JobShop::extractFile(const std::string& inputParameters)
{
  //std::cout <<  inputParameters <<'\n';
  batchFile.open("Batches/" + inputParameters);

  if (!batchFile.is_open())
  {
    std::cout << "something went wrong" << '\n';
  }

  getline(batchFile, line);
  std::istringstream iss(line);

  iss >> jobAmount >> machineAmount;
  //std::cout << line<<std::endl;

  while (getline(batchFile, line))
  {
    std::istringstream iss(line);

    while (iss >> machineNumber)
    {
      iss >> timeDuration;
      taskVector.push_back(Task(machineNumber, timeDuration));
    }
    ++currjobID;
    jobVector.push_back(Job(currjobID, taskVector));
    taskVector.clear();
  }
  batchFile.close();
}

void JobShop::generateOutput(){
  for (std::vector<Job>::iterator it = jobVector.begin(); it != jobVector.end(); ++it)
  {
    std::cout<<(*it).getJobID()<<" "<<(*it).getStartingTime()<<" "<<(*it).getEndTime()<< std::endl;
  }
}

void JobShop::criticalPathCalculation()
{

//	for(int i = 0; i < jobVector.size(); i++)
//	{

		priorityMap.insert ( std::pair<unsigned short,unsigned short>(1,1) ); //(jobVector[i],jobVector[i].getTotalDuration())

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

std::map JobShop::getCriticalPathCalculation()
{
	return priorityMap;
}

void JobShop::jobAssigner()
{
	for(int i = 0; i < priorityMap.size(); i++)
	{
		machineNr = priorityMap[i].getMachineNumber();
		if(machineVector[machineNr])
		{
			machineVector[machineNr] = false;
		}
	}
}

void JobShop::jobDeassigner()
{

}

