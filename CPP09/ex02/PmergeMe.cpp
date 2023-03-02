#include "PmergeMe.hpp"

int exitPrint(const char *str, int ret)
{
	std::cout << str << std::endl;
	return (ret);
}

int fillContainers(std::vector<int> &vec, std::list<int> &lst, int argc, char **argv)
{
	int tmp;
	for (int i = 1; i < argc; i++)
	{
		std::istringstream ss(argv[i]);
		if (ss >> tmp)
		{
			if (tmp < 0)
				return (exitPrint("Error: Negative number", -1));
			vec.push_back(tmp);
			lst.push_back(tmp);
		}
		else
			return (exitPrint("Error: Wrong character or number too big", -1));
	}
	return (0);
}

void displayPreview(std::vector<int> &vec, char state)
{
	if (state == 'b')
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (unsigned long i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << " ";
	std::cout << std::endl;
}

void displayTimes(std::vector<int> &vec, std::list<int> &lst, double vecTime, double lstTime)
{
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << lstTime << " us" << std::endl;
}

void vecMergeSort(std::vector<int> &vec, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	vecMergeSort(vec, left, mid);
	vecMergeSort(vec, mid + 1, right);
	std::vector<int> tmp;
	tmp.reserve(right - left + 1);
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (vec[i] < vec[j])
			tmp.push_back(vec[i++]);
		else
			tmp.push_back(vec[j++]);
	}
	while (i <= mid)
		tmp.push_back(vec[i++]);
	while (j <= right)
		tmp.push_back(vec[j++]);
	for (unsigned long k = 0; k < tmp.size(); k++)
		vec[left + k] = tmp[k];
}

void vecInsertionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (begin == end)
		return;
	for (std::vector<int>::iterator it = begin + 1; it != end; ++it)
	{
		std::vector<int>::iterator jt = it;
		while (jt != begin && *(jt - 1) > *jt)
		{
			std::swap(*(jt - 1), *jt);
			--jt;
		}
	}
}

void sortVector(std::vector<int> &vec, double &vecTime, int threshold)
{
	struct timeval start_time;
	struct timeval stop_time;
	gettimeofday(&start_time, NULL);
	vecMergeSort(vec, 0, vec.size() - 1);
	for (unsigned long i = threshold; i < vec.size(); i += threshold)
	{
		int start = i - threshold;
		int end = i - 1;
		vecInsertionSort(std::vector<int>::iterator(&vec[start]), std::vector<int>::iterator(&vec[end + 1]));
	}
	vecInsertionSort(std::vector<int>::iterator(&vec[vec.size() - vec.size() % threshold]), vec.end());
	gettimeofday(&stop_time, NULL);
	vecTime = (stop_time.tv_sec - start_time.tv_sec) * 1000000.0 + (stop_time.tv_usec - start_time.tv_usec);
}

void mergeLists(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right) {
    std::list<int> merged;
    std::list<int>::iterator i = left;
    std::list<int>::iterator j = mid;
    while (i != mid && j != right) {
        if (*i < *j)
            merged.push_back(*i++);
        else
            merged.push_back(*j++);
    }
    while (i != mid)
        merged.push_back(*i++);
    while (j != right)
        merged.push_back(*j++);
    std::copy(merged.begin(), merged.end(), left);
}

void listMergeSort(std::list<int> &lst, std::list<int>::iterator lbegin, std::list<int>::iterator lend) {
    if (std::distance(lbegin, lend) > 1) {
        std::list<int>::iterator mid = lbegin;
        std::advance(mid, std::distance(lbegin, lend) / 2);
        listMergeSort(lst, lbegin, mid);
        listMergeSort(lst, mid, lend);
        mergeLists(lbegin, mid, lend);
    }
}

void listInsertionSort(std::list<int> &lst)
{
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        int value = *it;
        std::list<int>::iterator j = it;
        while (j != lst.begin() && *(--j) > value)
            *(j++) = *j;
        *j = value;
    }
}

void sortList(std::list<int> &lst, double &lstTime, int threshold)
{
	struct timeval start_time;
	struct timeval stop_time;
	gettimeofday(&start_time, NULL);
    listMergeSort(lst, lst.begin(), lst.end());
    std::list<int>::iterator it = lst.begin();
    while (std::distance(it, lst.end()) >= threshold) {
        std::list<int>::iterator it1 = it;
        std::advance(it1, threshold);
		std::list<int> tmp(it, it1);
        listInsertionSort(tmp);
        it = it1;
    }
	std::list<int> tmp2(it, lst.end());
    listInsertionSort(tmp2);
	gettimeofday(&stop_time, NULL);
	lstTime = (stop_time.tv_sec - start_time.tv_sec) * 1000000.0 + (stop_time.tv_usec - start_time.tv_usec);
}
