// seperatedSpouses.cpp : Defines the entry point for the console application.
//This is a program to calculates the number of seating permutations for a party where no spouses are seated next to each other.
// This program uses the inclusion-exculsion principle and combination

#include "stdafx.h"
#include <iostream>
#include <math.h>
unsigned long factorial(unsigned long);//function to get the factorial output needed.
unsigned long chooseXOfY(unsigned long, unsigned long); //combination forumula function
unsigned long includeExlude(unsigned long); //inclusion-exculsion principle function
int main()
{
	unsigned long numOfCouples;
	std::cout << "Please enter the number of couples attending.\n";
	std::cin >> numOfCouples;
	int numOfPeople = numOfCouples * 2;
	if (numOfCouples == 1)
		std::cout << "There are no possible permutations" << std::endl;
	else
	{
		unsigned long factoredPlp = factorial(numOfPeople - 1);
		std::cout << "There are " << factoredPlp - (includeExlude(numOfPeople)) << " permutations." << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(255, '\n');
	std::cin.get();
    return 0;
}
unsigned long factorial(unsigned long factoredPlp)
{
	if (factoredPlp <= 0)
		return 1;
	else
	{
		unsigned long factorial = 1;
		for (int cnt = 1; cnt <= factoredPlp; ++cnt) {
			factorial *= cnt;
		}
		return factorial;
	}
	
}
unsigned long chooseXOfY(unsigned long n, unsigned long y)
{
	unsigned long Xof = n / 2;
	return factorial(Xof) / (factorial(y)*factorial(Xof - y));
}
unsigned long includeExlude(unsigned long n)
{
	int holder = 0;
	for (int cnt = 1; cnt <= (n / 2); ++cnt)
	{
		int testHolder = (n - cnt - 1);
		unsigned long x = chooseXOfY(n, cnt), y = factorial(testHolder), z = pow(2, cnt);
		if (cnt % 2 != 0)
			holder += (x*y* z);
		else if (cnt % 2 == 0)
			holder -= (x*y* z);
	}
	return holder;
}
