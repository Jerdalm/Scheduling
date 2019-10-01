/*
 * FileParser.h
 *
 *  Created on: Sep 27, 2019
 *      Author: Jerem
 */

#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>
#include <vector>

class FileParser {
public:
	FileParser();
	virtual ~FileParser();

	void extractFile(const std::string& argv);


private:
	/**
	 * BatchFile die de input levert voor het algorithme
	 */
	std::ifstream batchFile;
	/**
	 * A row of characters to input into the vector
	 */
	std::string line;
	unsigned short jobAmount;
	unsigned short machineAmount;
	unsigned short machineNumber;
	unsigned short JobNumber;

	unsigned short timeDuration;

};

#endif /* FILEPARSER_H_ */
