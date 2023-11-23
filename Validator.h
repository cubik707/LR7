#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Validator
{
public:
	static int getIntVar(int minLim, int maxLim);
	static double getDoubleVar(double minLim, double maxLim);
	static string getValidStr();
	static void convert(std::string& str);
};

void printLine(int length);