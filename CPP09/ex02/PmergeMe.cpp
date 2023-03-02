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
	for (unsigned long i = 0; i < vec.size() && i < 5; i++)
		std::cout << vec.at(i) << " ";
	if (vec.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

void displayTimes(std::vector<int> &vec, std::list<int> &lst, double vecTime, double lstTime)
{
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << lstTime << " us" << std::endl;
}

// Merge-sort function for a vector container
void vecMergeSort(std::vector<int> &v, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int m = (l + r) / 2;
	vecMergeSort(v, l, m);
	vecMergeSort(v, m + 1, r);

	std::vector<int> tmp;
	tmp.reserve(r - l + 1);

	int i = l;
	int j = m + 1;

	while (i <= m && j <= r)
	{
		if (v[i] < v[j])
		{
			tmp.push_back(v[i]);
			i++;
		}
		else
		{
			tmp.push_back(v[j]);
			j++;
		}
	}

	while (i <= m)
	{
		tmp.push_back(v[i]);
		i++;
	}

	while (j <= r)
	{
		tmp.push_back(v[j]);
		j++;
	}

	for (unsigned long k = 0; k < tmp.size(); k++)
	{
		v[l + k] = tmp[k];
	}
}

// Insertion-sort function for a vector container
void vecInsertionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
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

// Merge-insertion-sort function for a vector container
void sortVector(std::vector<int> &vec, double &vecTime)
{
	struct timeval start_time;
	struct timeval stop_time;
	gettimeofday(&start_time, NULL);
	const int kThreshold = 16; // Insertion sort threshold

	vecMergeSort(vec, 0, vec.size() - 1);

	for (unsigned long i = kThreshold; i < vec.size(); i += kThreshold)
	{
		int start = i - kThreshold;
		int end = i - 1;
		vecInsertionSort(std::vector<int>::iterator(&vec[start]), std::vector<int>::iterator(&vec[end + 1]));
	}

	vecInsertionSort(std::vector<int>::iterator(&vec[vec.size() - vec.size() % kThreshold]), vec.end());
	gettimeofday(&stop_time, NULL);
	vecTime = (stop_time.tv_sec - start_time.tv_sec) * 1000000.0 + (stop_time.tv_usec - start_time.tv_usec);
}

// Merge-sort function for a list container
void merge(std::list<int> &l, std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right) {
    std::list<int> merged;
    std::list<int>::iterator i = left;
    std::list<int>::iterator j = mid;
	(void)l;
    while (i != mid && j != right) {
        if (*i < *j) {
            merged.push_back(*i);
            ++i;
        } else {
            merged.push_back(*j);
            ++j;
        }
    }
    while (i != mid) {
        merged.push_back(*i);
        ++i;
    }
    while (j != right) {
        merged.push_back(*j);
        ++j;
    }
    std::copy(merged.begin(), merged.end(), left);
}

void listMergeSort(std::list<int> &l, std::list<int>::iterator lbegin, std::list<int>::iterator lend) {
    if (std::distance(lbegin, lend) > 1) {
        std::list<int>::iterator mid = lbegin;
        std::advance(mid, std::distance(lbegin, lend) / 2);
        listMergeSort(l, lbegin, mid);
        listMergeSort(l, mid, lend);
        merge(l, lbegin, mid, lend);
    }
}

// Insertion-sort function for a list container
void listInsertionSort(std::list<int> &lst)
{
	for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i) {
        int value = *i;
        std::list<int>::iterator j = i;
        while (j != lst.begin() && *(--j) > value) {
            *(j++) = *j;
        }
        *j = value;
    }
}

// Merge-insertion-sort function for a list container
void sortList(std::list<int> &lst, double &lstTime)
{
	struct timeval start_time;
	struct timeval stop_time;
	gettimeofday(&start_time, NULL);

	const int kThreshold = 16;

    listMergeSort(lst, lst.begin(), lst.end());

    std::list<int>::iterator it = lst.begin();
    while (std::distance(it, lst.end()) >= kThreshold) {
        std::list<int>::iterator it1 = it;
        std::advance(it1, kThreshold);
		std::list<int> tmp(it, it1);
        listInsertionSort(tmp);
        it = it1;
    }
	std::list<int> tmp2(it, lst.end());
    listInsertionSort(tmp2);

	gettimeofday(&stop_time, NULL);
	lstTime = (stop_time.tv_sec - start_time.tv_sec) * 1000000.0 + (stop_time.tv_usec - start_time.tv_usec);
}