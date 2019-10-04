/*
 * JobShop.h
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include "Task.h"
#include "Job.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <list>
#include <set>



class JobShop {
public:


  JobShop();
  virtual ~JobShop();

  std::vector<Job> getJobVector();
  void setJobVector(const std::vector<Job>& aVector);

  void extractFile(const std::string& argv);
  void criticalPathCalculation(std::vector<Job>& aJobVector);
    //std::map getCriticalPathCalculation();
  void jobAssigner();
  void jobDeassigner();
  void generateOutput();

  //static unsigned long currTime = 0;

private:

  std::ifstream batchFile;
  std::list<Job> priorityList;

  std::string line;
  std::string inputParameters;

  std::vector<Task> taskVector;
  std::vector<Job> jobVector;

  std::vector<bool> machineVector;

  unsigned short currjobID = 0;
  unsigned short jobAmount;
  unsigned short machineAmount;
  unsigned short machineNumber;
  unsigned short JobNumber;
  unsigned short timeDuration;
  unsigned short machineNr;


};

#endif /* JOBSHOP_H_ */
