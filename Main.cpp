/*
 * Main.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "JobShop.h"
#include <iostream>

int main(int argc, char **argv) {

	JobShop AlgorithmShop;
	AlgorithmShop.extractFile(argv[1]);
	AlgorithmShop.solveAlgorithm();
AlgorithmShop.generateOutput();

	return 0;
}

