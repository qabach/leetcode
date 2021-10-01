/*
Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/


/*

Problem Analysis:
	- find the length of ONLY the last word in the string.
	- the string contains English letters and spaces.
	- a word is a maximal substring consisting of non-space chars only. 
	
Direction:
	- reverse the string.
	- find the last word.
	- compute the length of the last word. 

Q's :
	- How to identify a word [?]
		- a word starts with white space (or nothing/punc if reversing) and ends with white space (or nothing if the string has only one word).

	- How to find the last word [?]
		- the last word is the FIRST word in an reverse array.

*/		



#include <iostream>
#include <string>
#include <locale>	//std::locale, std::isalpha, std::ispunct
 

int lengthOfLastWord(std::string s) 
{
	//the return length of the last word
	int re_len = 0;
	
	//initialize locale
	std::locale loc; 

	//reverse the string 
	std::string reverse_s;
	for (std::string::iterator it = s.end()-1; it !=s.begin()-1; --it)
	{
		reverse_s += *it;
	}

	//add the null terminator for the reverse string
	reverse_s += "\0";
	//find the FIRST word of the reversed string 
	//find the first char that is an alphabet letter of the FIRST word 
	std::string::iterator it = reverse_s.begin(); //add -1 to avoid starting at the null terminator
	while (!std::isalpha(*it,loc))
	{
		it++;
	}

	std::string::iterator it2 = it;

	while (std::isalpha(*it2,loc))
	{
		it2++;
	}

	return it2-it;   
}


int main()
{
	std::string s = "Hello World";
	std::cout << lengthOfLastWord(s) << std::endl;

	return 0;
}



/*
Algorithm Analysis:
	- Time complexity: O(n); since the algorithm only iterate over the string once
	- Space complexity: O(1); since the memory does not grow with the size of the input string
	
*/