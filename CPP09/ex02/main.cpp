#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int>	vec;
	std::list<int>		lst;
	double				vecTime = 0.0;	
	double				lstTime = 0.0;	
	int					threshold = 16;

	if (argc < 2)
		return (exitPrint("Error: Not enough arguments", -1));
	if (fillContainers(vec, lst, argc, argv) == -1)
		return(-1);
	displayPreview(vec, 'b');
	sortVector(vec, vecTime, threshold);
	sortList(lst, lstTime, threshold);
	displayPreview(vec, 'a');
	displayTimes(vec, lst, vecTime, lstTime);
	return (0);
}
