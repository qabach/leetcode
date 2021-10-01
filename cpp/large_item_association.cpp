/*
In order to improve customer experience, Amazon has developed a system to provide recommendations to the customer regarding the item they can purchase. 
Based on historical customer purchase information, an item association can be defined as 
- If an item A is ordered by a customer, then item B is also likely to be ordered by the same customer (e.g. Book 1 is frequently orderered with Book 2). 
All items that are linked together by an item association can be considered to be in the same group. 
An item without any association to any other item can be considered to be in its own item association group of size 1.

Given a list of item association relationships(i.e. group of items likely to be ordered together), write an algorithm that outputs the largest item association group. 
If two groups have the same number of items then select the group which contains the item that appears first in lexicographic order.

Input
The itput to the function/method consists of an argument - itemAssociation, a list containing paris of string representing the items that are ordered together.

Output
Return a list of strings representing the largest association group sorted lexicographically.

Example
Input:
itemAssociation: [
[Item1, Item2],
[Item3, Item4],
[Item4, Item5]
]

Output:
[Item3, Item4, Item5]

Explanation:
There are two item association groups:
group1: [Item1, Item2]
group2: [Item3,Item4,Item5]
In the available associations, group2 has the largest association. So, the output is [Item3, Item4, Item5].
*/


/*
Problem Analysis:
	- Input: List(List<string>); contains pairs of string denoting the items.
	- All items that are linked together by an item association can be considered to be in the same group.
	- An item without any association to any other item can be considered to be in its own item association group of size 1.

Questions:
	- How to associate item linked other items in the same group [?]
	- How to form groups [?]
	- What information to use for lexicographical order [?]

Directions:
	- look at a new group -> form a group -> store the group information in a map
	- each time look at an elem, check if elem already in any group -> if yes, store in the same group, else form a new group.

Example:
	[1 2] -> form a group
	[3 4] -> form a group
	[4 5] -> form a group -> combine with prev group when there is a same element -> [3 4 5]

 	-> [3 4 5] 
*/



#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>


using namespace std;


class PairString
{
	public:
		string first;
		string second;

		PairString(string _first, string _second)
		{
			this->first = _first;
			this->second = _second;
		}
};



/* Function Prototypes */
set<string>  LargestItemAssociation(vector<PairString> itemAssociation);



int main()
{
	auto pair1 = PairString("1","2");
	auto pair2 = PairString("3","4");
	auto pair3 = PairString("4","5");
	auto pair4 = PairString("6","7");
	auto pair5 = PairString("7","8");
	auto pair6 = PairString("1","3");



	auto itemAssociation = vector<PairString>();

	itemAssociation.push_back(pair1);
	itemAssociation.push_back(pair2);
	itemAssociation.push_back(pair3);
	itemAssociation.push_back(pair4);
	itemAssociation.push_back(pair5);
	itemAssociation.push_back(pair6);


	auto largestGroup = LargestItemAssociation(itemAssociation);

	for (auto it = largestGroup.begin(); it != largestGroup.end(); it++)
	{
		cout << *it << " ";
	}

	return 0;
}


/* Function: Large Item Association */
/* Take a vector contains pair of strings as input, output the largest item association group */
set<string>   LargestItemAssociation(vector<PairString> itemAssociation)
{

	//map to identify group number for
	auto groupMap = map<string, int>();

	//vector to contain all the groups 
	auto groupVector = vector<set<string>>();

	//group ID
	int groupID = 0;


	//main loop to traverse thru the item association list
	for (auto i = itemAssociation.begin(); i != itemAssociation.end(); i++)
	{
		//If the element has been assigned agroup
		if (groupMap.find(i->first) != groupMap.end())
		{

			//update the group map
			//if map does not have the second item
			if (groupMap.find(i->second) == groupMap.end())
			{
				groupMap[i->second] = groupMap[i->first];
			}
			else
			{
				auto value = groupMap[i->second];
				for (auto it : groupMap)
				{
					if(it.second == value)
						groupMap[it.first] = groupMap[i->first];
				}
			}

			//update group vector 
			for (auto it : groupMap)
			{
				groupVector[it.second].insert(it.first);
			}
		}
		else if (groupMap.find(i->second) != groupMap.end())
		{

			//update the group map
			//if map does not have the second item
			if (groupMap.find(i->second) == groupMap.end())
			{
				groupMap[i->first] = groupMap[i->second];
			}
			else
			{
				auto value = groupMap[i->second];
				for (auto it : groupMap)
				{
					if(it.second == value)
						groupMap[it.first] = groupMap[i->second];
				}
			}

			//update group vector 
			for (auto it : groupMap)
			{
				groupVector[it.second].insert(it.first);
			}
		}
		//If the elements have not been assigned any group
		else
		{
			//form a new group
			auto newGroup = set<string>();
			newGroup.insert(i->first);
			newGroup.insert(i->second);

			//add info to the map
			groupMap[i->first] = groupID;
			groupMap[i->second] = groupID;

			//add the new group to the vector
			groupVector.push_back(newGroup);

			//increment the group ID after creating new group
			++groupID;
		}
	}

/* Uncomment to print out the map and groups 

	for (auto it = groupMap.begin(); it != groupMap.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}


	for(auto i = groupVector.begin(); i != groupVector.end(); i++)
	{
		for(auto j = i->begin(); j != i->end();j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
*/
	//iterator to find the longest group
	auto it = groupVector.begin();
	//max length of the group
	int max = it->size();

	for (auto i = groupVector.begin(); i != groupVector.end(); i++)
	{
		if( i->size() > max)
		{
			max = i->size();
			it = i;
		}
	}
	
	//return set
	auto largestGroup = set<string>();

	for(auto i = it->begin(); i != it->end(); i++)
	{
		largestGroup.insert(*i);
	}


	return largestGroup;

}	











