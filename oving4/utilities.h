#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, const int& increment, const int& numTimes);
void swapNumbers(int& a, int& b);

struct Student {
    string name;
    string studyProgram;
    int age;
};

bool isInProgram(Student student, string studyProgram);
string randomizeString(int stringLength, char lowerInInterval, char upperInInterval);
int randomWithLimits(int lowerLimit, int upperLimit);
string readInputToString(int stringLength, char lowerCharLimit, char upperCharLimit); 
int countChar(string strToCheck, char charToCount); 