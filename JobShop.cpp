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

void JobShop::criticalPathCalculation(std::vector<Job>& aJobVector)
{

	for(int i = 0; i < jobVector.size(); i++)
	{
		if(!jobVector[i].getAssigned())
		{		{
		priorityList.push_back(jobVector[i]);
		}
	}

	    // sort using a custom function object
	    struct {
	        bool operator()(Job A, Job B) const
	        {
	            return A.getSlack < B.getSlack;
	        }
	    } customLess;
	    std::sort(priorityList.begin(), priorityList.end(), customLess);
	}

}

//std::map JobShop::getCriticalPathCalculation()
//{
//	return priorityMap;
//}

void JobShop::jobAssigner()
{
	for(int i = 0; i < priorityMap.size(); i++)
	{

		machineNr = priorityMap.begin();
		if(machineVector[machineNr])
		{
			machineVector[machineNr] = false;
		}
	}
}

void JobShop::jobDeassigner()
{

}

