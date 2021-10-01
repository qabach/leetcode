/*
You are on a flight and wanna watch two movies during this flight.
You are given List<Integer> movieDurations which includes all the movie durations.
You are also given the duration of the flight which is d in minutes.
Now, you need to pick two movies and the total duration of the two movies is less than or equal to (d - 30min).

Find the pair of movies with the longest total duration and return they indexes. If multiple found, return the pair with the longest movie.

Example 1:

Input: movieDurations = [90, 85, 75, 60, 120, 150, 125], d = 250
Output: [0, 6]
Explanation: movieDurations[0] + movieDurations[6] = 90 + 125 = 215 is the maximum number within 220 (250min - 30min)
*/


/*
Problem analysis:
	- list of movies duration List<int>
	- [target = (d -30)]; d is the duration of flight
	- find a pair of movies with [sum(durations) <= target] 
	- return the indices of the pair from the original list

Questions:
	- How to find the pairs [?] 
		- compute each sum and get the max s.t. <= target. 
		- for each of the duration, only need to find another duration that closest to the target. 
	- How to compute the sum of all the pairs [?]
		- all the sums computed are not repeated -> memo won't help. 
		- brute force -> O(n^2) complexity. 
		- is it necessray to compute ALL the sums [?]
			- No. for each elem, ONLY need to find the sum s.t. closest to target
	- How to return the indices [?]

Directions:
	- first sort the durations and keep a copy of the original list for idices. 
	- for each of the element, find the [target - elem] value. 
	- then find the duration that closest to the [target - elem].
	Ex: 
		sorted movieDurations = [60, 75, 85, 90, 120, 125, 150].
		target = 250 - 30 = 220.
		target - 60 = 160.
		find movie duration closest to 160 with binary search. 
		record the sum. 
		record the indices. 
		with all the recorded sums and indices. Find the max(sums) and return the indices. 
*/

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

const int TARGET = 220; 

//Function prototypes 
std::vector<int> mergeSort(std::vector<int> _unsortedArr);

std::vector<int> joinVecs(const std::vector<int> _left, const std::vector<int> _right);

void findMovies(std::vector<int> _movieDuration);

void printVec(const std::vector<int> _inputVec);

int findElem (const std::vector<int> _inputVec, int _target);

int max(std::vector<int> _inputVec);


int main()
{
	std::vector<int> moviesDurations;
	moviesDurations.push_back(90);
	moviesDurations.push_back(85);
	moviesDurations.push_back(75);
	moviesDurations.push_back(60);
	moviesDurations.push_back(155);
	moviesDurations.push_back(150);
	moviesDurations.push_back(125);

	printVec(mergeSort(moviesDurations));

	std::cout << "TEST FIND ELEM: "<< findElem(mergeSort(moviesDurations),130) << std::endl;



	std::cout << "MAIN RESULT: " << std::endl;

	findMovies(moviesDurations);

	return 0;
}


//Function Definition: Merge Sort
//Take a unsorted vec and return a sorted vec 
std::vector<int> mergeSort (std::vector<int> _unsortedArr)
{
	//Base case when the array has length = 1
	if (_unsortedArr.size() == 1)
	{
		return _unsortedArr;
	}

	int split = _unsortedArr.size() * 0.5;

	//left and right splitted arrays
	std::vector<int> unsortedL;
	std::vector<int> unsortedR; 

	//populate the splitted array
	for (int i = 0; i < split; i++)
	{
		unsortedL.push_back(_unsortedArr[i]);
	}

	for (int i = split; i < _unsortedArr.size(); i++)
	{
		unsortedR.push_back(_unsortedArr[i]);
	}

	//recursively merge sort the splitted arrays
	std::vector<int> sortedL = mergeSort(unsortedL);
	std::vector<int> sortedR = mergeSort(unsortedR);

	std::vector<int> sortedArr = joinVecs(sortedL,sortedR);


	return sortedArr; 
}

//Function Definition: Join Vectors
//Take 2 vectors and join them by ascending order
std::vector<int> joinVecs(const std::vector<int> _left, const std::vector<int> _right)
{
	//the return sorted vector
	std::vector<int> sortedArr;

	int i = 0;
	int j = 0;

	while (i+j < _left.size() + _right.size())
	{
		//check if left is out of range
		if (i == _left.size())
		{
			sortedArr.push_back(_right[j]);
			j++;
		}
		//check if right is out of range
		else if (j == _right.size())
		{
			sortedArr.push_back(_left[i]);
			i++;
		}
		//joining step
		else if (_left[i] <= _right[j])
		{
			sortedArr.push_back(_left[i]);
			i++;
		}
		else
		{
			sortedArr.push_back(_right[j]);
			j++;
		}

	}

	return sortedArr;
}


//Function Definition: Print Vectors
//Print out the content of input vector
void printVec(const std::vector<int> _inputVec)
{
	std::cout << "TEST PRINT VECTOR: ";
	for (int i = 0; i < _inputVec.size(); i++)
	{
		std::cout << _inputVec[i] << " ";
	}
	std::cout << std::endl;
}

/* Find Element */
/* Take in an vector and a target int. Return an element closest to target */
//sorted movieDurations = [60, 75, 85, 90, 120, 125, 150].
//target = 110
int findElem(const std::vector<int> _inputVec, int _target)
{	
	int return_elem; 

	//Base case when input vec size is 1
	if (_inputVec.size() == 1)
		return _inputVec[0];


	int split = _inputVec.size() * 0.5; 
	if (_inputVec[split] == _target)
	{	
		return _inputVec[split];
	}
	else if (_inputVec[split] < _target)
	{
		//create the splitted right array
		std::vector<int> right; 
		for (int i = split; i < _inputVec.size(); i++)
			right.push_back(_inputVec[i]);

		//binary search again
		return_elem = findElem(right,_target);
	}
	else if (_inputVec[split] > _target)
	{
		//create the splitted right array
		std::vector<int> left; 
		for (int i = 0; i < split; i++)
			left.push_back(_inputVec[i]);

		//binary search again
		return_elem = findElem(left,_target);
	}

	return return_elem;
}

//Function Definition: Find Movies
//Take a list of movies durations and print out the 2 indices of movies with sum closest to target
void findMovies(std::vector<int> _movieDuration)
{

	//create a hash map to map indices and movie duration for look up 
	std::map<int,int> index_map;

	//sum-index map
	std::map<int,std::pair<int,int> > sum_index_map; 

	for (int i = 0; i < _movieDuration.size(); i++)
	{
		index_map[_movieDuration[i]] = i;
	}

	//get the sorted array
	std::vector<int> sortedDuration = mergeSort(_movieDuration);


	// sum array
	std::vector<int> sum_vector; 
	//traverse thru the list to find the elements of interest
	for (int i = 0; i < _movieDuration.size(); i++)
	{
		int elem = findElem(sortedDuration,TARGET - _movieDuration[i]);

		//get the index of the elements of interest
		int index1 = index_map[_movieDuration[i]];
		int index2 = index_map[elem];

		//get the sum of the pair 
		int sum = elem + _movieDuration[i];

		sum_vector.push_back(sum);

		sum_index_map[sum] = std::make_pair(index1,index2);
	}

	for (std::map<int,std::pair<int,int> >::iterator it = sum_index_map.begin(); it != sum_index_map.end(); it++)
	{
		std::cout << "sum: " << it->first << " pair: " << it->second.first << " " << it->second.second << std::endl;
	}


	int max_sum = max(sum_vector);
	std::cout << "final result: " << sum_index_map[max_sum].first << " " << sum_index_map[max_sum].second << std::endl;
}


int max(std::vector<int> _inputVec)
{
	int max = _inputVec[0];

	for (int i = 0; i < _inputVec.size(); i++)
	{
		if (max <= _inputVec[i])
			max = _inputVec[i];
	}

	return max; 
}

