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
  //void JobShop::SolveAlgorithm();

  static unsigned long currTime;

private:

  std::ifstream batchFile;
  std::list<Job> priorityList;

  std::string line;
  std::string inputParameters;

  std::vector<Task> taskVector;
  std::vector<Job> jobVector;

  std::vector<bool> machineVector;

  unsigned short currjobID = 0;
  unsigned short jobAmount = 0;
  unsigned short machineAmount = 0;
  unsigned short machineNumber = 0;
  unsigned short JobNumber = 0;
  unsigned short timeDuration = 0;
  unsigned short machineNr = 0;


};

#endif /* JOBSHOP_H_ */
