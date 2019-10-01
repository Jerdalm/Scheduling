/*
 * Job.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: Jerem
 */

#include "Job.h"

Job::Job() {
	// TODO Auto-generated constructor stub

}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

unsigned long Job::CalculateLongestSlack(unsigned short timeDuration)
{
	for(int i = 0; i < vTask.size(); i++)
	{
		mostSlack += vTask[1][i];
	}
}

const unsigned long Job::getLongest() const
{
	return mostSlack;
}

//unsigned long Job::CalculateLeastSlack()
//{
//	for(int i = vTask.size(); i < 0; i--)
//	{
//		leastSlack =
//	}
//}

