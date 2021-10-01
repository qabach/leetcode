/*
Amazon is running a promotion in which customers receive prizes for purchasing a secret combination of fruits. The combination will change each day, and the team running the promotion wants to use a code list to make it easy to change the combination. The code list contains groups of fruits. Both the order of the groups within the code list and the order of the fruits within the groups matter. However, between the groups of fruits, any number, and type of fruit is allowable. The term "anything" is used to allow for any type of fruit to appear in that location within the group.

Consider the following secret code list: [[apple, apple], [banana, anything, banana]]
Based on the above secret code list, a customer who made either of the following purchases would win the prize:
orange, apple, apple, banana, orange, banana
apple, apple, orange, orange, banana, apple, banana, banana

Write an algorithm to output 1 if the customer is a winner else output 0.

Input
The input to the function/method consists of two arguments:
codeList, a list of lists of strings representing the order and grouping of specific fruits that must be purchased in order to win the prize for the day.
shoppingCart, a list of strings representing the order in which a customer purchases fruit.

Output
Return an integer 1 if the customer is a winner else return 0.

Note
'anything' in the codeList represents that any fruit can be ordered in place of 'anything' in the group. 'anything' has to be something, it cannot be "nothing."
'anything' must represent one and only one fruit.
If secret code list is empty then it is assumed that the customer is a winner.

Example 1:

Input: codeList = [[apple, apple], [banana, anything, banana]] shoppingCart = [orange, apple, apple, banana, orange, banana]
Output: 1
Explanation:
codeList contains two groups - [apple, apple] and [banana, anything, banana].
The second group contains 'anything' so any fruit can be ordered in place of 'anything' in the shoppingCart. The customer is a winner as the customer has added fruits in the order of fruits in the groups and the order of groups in the codeList is also maintained in the shoppingCart.

Example 2:

Input: codeList = [[apple, apple], [banana, anything, banana]]
shoppingCart = [banana, orange, banana, apple, apple]
Output: 0
Explanation:
The customer is not a winner as the customer has added the fruits in order of groups but group [banana, orange, banana] is not following the group [apple, apple] in the codeList.

Example 3:

Input: codeList = [[apple, apple], [banana, anything, banana]] shoppingCart = [apple, banana, apple, banana, orange, banana]
Output: 0
Explanation:
The customer is not a winner as the customer has added the fruits in an order which is not following the order of fruit names in the first group.

Example 4:

Input: codeList = [[apple, apple], [apple, apple, banana]] shoppingCart = [apple, apple, apple, banana]
Output: 0
Explanation:
The customer is not a winner as the first 2 fruits form group 1, all three fruits would form group 2, but can't because it would contain all fruits of group 1.
*/


/*
	Problem Analysis:
		- If customer shopping cart match codeList -> return 1
		- order of the groups and order of the fruits in each group matter. 
		- anything can be any item but not 'nothing'.
	Questions:
		- How to to find the 'matches' in the shopping cart [?]
		- How to make sure that the matches maintain order [?]
		- How to match 'anything' [?]
		- What if the code start with 'anything' [?] [anything, orange, orange] -> how to find match [?]
	Approach:
		- treat the code as a 'substring' and find a match in the shopping cart.
		- iterate thru the shopping cart to find the match of each code list.
		- put the codes into a queue -> if queue is empty at the end -> return 1, else return 0.

*/



#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/* Function Prototype */
bool prizeWin(vector<vector<string>> _codeList, vector<string> _shoppingCart);


int main()
{
	//create the shopping cart
	auto shoppingCart = vector<string>();
	shoppingCart.push_back("apple");
	shoppingCart.push_back("apple");
	shoppingCart.push_back("orange");
	shoppingCart.push_back("banana");
	shoppingCart.push_back("orange");


	//create a code list
	auto codeList = vector<vector<string>>();
	vector<string> code1 = {"apple", "apple"};
	vector<string> code2 = {"orange", "anything", "orange"};
	codeList.push_back(code1);
	codeList.push_back(code2);


	cout << prizeWin(codeList,shoppingCart) << endl;


	return 0;
}




/* Function: prizeWin */ 
/* take a code list and a shopping cart as input; output the boolean if the customer wins */
bool prizeWin(vector<vector<string>> _codeList, vector<string> _shoppingCart)
{

	//queue to keep the codes
	auto codeQueue = queue<vector<string>>();

	for (auto it = _codeList.begin(); it != _codeList.end(); it++)
	{
		codeQueue.push(*it);
	}

	//traverse the shopping cart to find matches 
	for (auto iter = _shoppingCart.begin(); iter != _shoppingCart.end(); iter++)
	{
		// cout << *iter << endl;
		//find the initial match of the code
		if (*iter == codeQueue.front()[0] || *iter == "anything")
		{
			//check if the code is found
			auto temp_it = iter + 1;
			auto code_it = codeQueue.front().begin() + 1;

			while ((*temp_it == *code_it || *code_it == "anything") && code_it != codeQueue.front().end())
			{
				++temp_it;
				++code_it;
			}

			//if all the code match
			if (code_it == codeQueue.front().end())
			{
				//set iter to temp iter
				iter = temp_it-1;
				codeQueue.pop();
			}

		}
	}


	if (codeQueue.size() == 0)
		return 1;
	else
		return 0;

}
