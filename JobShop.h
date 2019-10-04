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

	/**
	 * Initialises a jobShop
	 */
  JobShop();
  /**
   * Deconstructor for Jobshop
   */
  virtual ~JobShop();
  /**
   * Returns a Job vector jobVector
   * @return
   */
  std::vector<Job> getJobVector();
  /**
   * Sets jobVector
   * @param aVector
   */
  void setJobVector(const std::vector<Job>& aVector);
  /**
   * Extracts the job count, machine count and the tasks(machine number and duration)
   * from the .txt file.
   * @param argv
   */
  void extractFile(const std::string& argv);
  /**
   * Generates the output for the terminal
   */
  void generateOutput();
  /**
   * Calculates the critical path with the getSlack from every job
   * The job with te most slack will be at the first position
   * @param aJobVector
   */
  void criticalPathCalculation(std::vector<Job>& aJobVector);
  /**
   *
   */
  void jobAssigner();
  void jobDeassigner();


  //void JobShop::SolveAlgorithm();
  void assigner();

  bool checkJobsFinished();
  void solveAlgorithm();

  static unsigned long currTime;

private:

  std::ifstream batchFile;
  std::vector<Job> priorityList;

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

  bool assign = false;

};

#endif /* JOBSHOP_H_ */
