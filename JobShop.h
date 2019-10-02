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
#include <map>
#include <set>

class JobShop {
public:
  JobShop();
  virtual ~JobShop();

  std::vector<Job> getJobVector();
  void setJobVector(const std::vector<Job>& aVector);

  void extractFile(const std::string& argv);
  void OrderJobs(unsigned long firstJob);
    std::map getOrderJobs();
    void AssignMachine();
    void SkipTime();
  void generateOutput();

private:

  std::ifstream batchFile;
  std::map<int,int> priorityMap;

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

  unsigned short machineNr; //Is deze wel nodig? machineNumber bestaat ook.


};

#endif /* JOBSHOP_H_ */
