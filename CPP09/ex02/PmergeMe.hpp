#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <sys/time.h>

int fillContainers(std::vector<int> &vec, std::list<int> &lst, int argc, char **argv);
void displayPreview(std::vector<int> &vec, char state);
void sortVector(std::vector<int> &vec, double &vecTime);
void sortList(std::list<int> &lst, double &lstTime);
void displayTimes(std::vector<int> &vec, std::list<int> &lst, double vecTime, double lstTime);

#endif