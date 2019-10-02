/*
 * JobShop.h
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

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

	void extractFile(const std::string& argv);
	void OrderJobs(unsigned long firstJob);


private:
	/**
	 * BatchFile die de input levert voor het algorithme
	 */
	std::ifstream batchFile;
	/**
	 * A row of characters to input into the vector
	 */
	std::string line;
	std::string inputParameters;
	unsigned short jobAmount;
	unsigned short machineAmount;
	unsigned short machineNumber;
	unsigned short JobNumber;

	unsigned short timeDuration;

	std::vector<Task> taskVector;

	std::map<int,int> PriorityMap;
};

#endif /* JOBSHOP_H_ */
