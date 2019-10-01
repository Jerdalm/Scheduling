/*
 * FileParser.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: Jerem
 */

#include "FileParser.h"

FileParser::FileParser() {
	// TODO Auto-generated constructor stub

}

FileParser::~FileParser() {
	// TODO Auto-generated destructor stub
}

void FileParser::extractFile(const std::string& argv)
{
	batchFile.open(argv);
	if (!batchFile.is_open())
	{
		std::cout << "something went wrong" << '\n';
	}

	getline(batchFile, line);
	std::istringstream iss(line);

	//iss >> jobAmount >> MachineAmount;

	while (getline(batchFile, line))
	{
		std::istringstream iss(line);

		while (iss >> machineNumber)
		{

			iss >> timeDuration;


		}

	}
	batchFile.close();
}

