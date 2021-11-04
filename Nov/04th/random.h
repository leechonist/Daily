#ifndef RANDOM_H_
#define RANDOM_H_
#include <cstdlib>
#include <ctime>
#include <iostream>
class Random
{
public:
	Random()
	{
		srand(time(NULL));
	}
	int operator() (int aMin,int aMax)
	{
		return rand()%(aMax-aMin+1)+aMin;
	}
};

#endif