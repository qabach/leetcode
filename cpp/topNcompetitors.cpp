/*
Input
The input to the function/method consists of five arguments - numCompetitors, an integer representing the number of competitors for the Echo device;
topNCompetitors, is an integer representing the maximum number of competitors that Amazon wants to identify;
competitors, a list of strings representing the competitors;
numReviews, an integer representing the number of reviews from different websites that are identified by the automated webcrawler;
reviews, a list of string where each element is a string that consists of space-separated words representing user reviews.

Output
Return a list of strings representing Amazon's top N competitors in order of most frequently mentioned to least frequent.

Note
The comparison of strings is case-insensitive. If the value of topNCompetitors is more than the number of competitors discussed in the reviews then output the names of only the competitors mention.
If competitors have the same count (e.g. newshop=2, shopnow=2, mymarket=4), sort alphabetically. topNCompetitors=2, Output=[mymarket, newshop]

Example
Input:
numCompetitors=6
topNCompetitors = 2
competitors = [newshop, shopnow, afashion, fashionbeats, mymarket, tcellular]
numReviews = 6
reviews = [
"newshop is providing good services in the city; everyone should use newshop",
"best services by newshop",
"fashionbeats has great services in the city",
"I am proud to have fashionbeats",
"mymarket has awesome services",
"Thanks Newshop for the quick delivery"]

Output
["newshop", "fashionbeats"]

Explanation
"newshop" is occurring in 3 different reviews. "fashionbeats" is occuring in 2 different user reviews and "mymarket" is occurring in only 1 review.


*/


/*
	Problem Analysis:
		Input:
		- numCompetitors: 	<int> number of competitors for Echo.
		- topNcompetitors: 	<int> maximum number of competitors.
		- competitors: 		List<string> contains competitors
		- numReviews:		<int> the number of reviews from different websites.
		- reviews:			List<string> each elem is a review. 
		
		Output:
		- Return a list of top N competitors MFM -> LFM 

		Analysis:
		- find the count of the the competitor names in the reviews
		- the comparison is case-sensitive.
		- if topNcompetitors > discussed_competitors -> return the discussed competitors 

	Questions:

	Directions: 
		- perform map n reduce to find the count of each competitor. 
		- need to traverse the entire reviews and change them all to lowercase 


*/




#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include<sstream>
#include <vector>



std::vector<std::string> split(const std::string &s,  char delim); 

std::string * topNcompetitors (int _numberOfCompetitors, int _topNCompetitors, std::string * _competitors, int _numReviews, std::string * _reviews);





int main()
{
	 // Initialize String Array
	std::string reviews[6] = {"newshop is providing good services in the city; everyone should use newshop", "best services by newshop", "fashionbeats has great services in the city", "I am proud to have fashionbeats", "mymarket has awesome services", "Thanks Newshop for the quick delivery"};
 	

 	std::string competitors [6] = {"newshop", "shopnow", "afashion", "fashionbeats", "mymarket", "tcellular"};

 	//Create a dict of top competitors
	std::map<std::string,int> competitors_map;

    // Print Strings
    std::string superStr;
    for (auto i : reviews)
    {
    	superStr += i;
    	superStr.append(" ");
    }

    
	std::transform(superStr.begin(), superStr.end(), superStr.begin(), [](unsigned char c){ return std::tolower(c); });


	for (int i = 0; i < competitors->size(); i++)
	{
		competitors_map[competitors[i]] = 0;
	}

	auto words = split(superStr, ' ');

	for (auto i : words)
	{
		if(competitors_map.find(i) != competitors_map.end())
		{
			competitors_map[i] += 1;
		}
	}

	for (auto i = competitors_map.begin(); i != competitors_map.end(); i++)
	{
		if (i->second != 0)
			std::cout << i->first <<  " : " << i->second << std::endl;
	}
	return 0;
}

std::vector<std::string> split(const std::string &s, char delim) 
{
    auto elems = std::vector<std::string>();
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) 
    {
      elems.push_back(item);
    }
    return elems;
}



std::string * topNcompetitors (int _numberOfCompetitors, int _topNCompetitors, std::string * _competitors, int _numReviews, std::string * _reviews)
{
	//First get the size to return 
	int return_size;
	if (_topNCompetitors <= _numberOfCompetitors)
		return_size = _topNCompetitors;
	else
		return_size = _numberOfCompetitors;

	//Create the return array
	std::string * topCom;
	topCom = new std::string [return_size];

	//Combine all the reviews into a string and lowercase all.
	std::string superStr;

    for (auto i : *_reviews)
    {
    		superStr += i;
    		superStr.append(" ");
	}

	//Convert the super string to all lowercase
	std::transform(superStr.begin(), superStr.end(), superStr.begin(), [](unsigned char c){ return std::tolower(c); });


	//Create a dict of top competitors
	std::map<std::string,int> competitors_map;

	for (int i = 0; i < _competitors->size(); i++)
	{
		competitors_map[_competitors[i]] = 0;
	}

	auto words = split(superStr, ' ');

	for (auto i : words)
	{
		if(competitors_map[i])
		{
			competitors_map[i] += 1;
		}
	}
	//Traverse the super string and increment the count of each mentioned
	return topCom;

}