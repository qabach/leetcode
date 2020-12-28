# -*- coding: utf-8 -*-
"""
Created on Mon Dec 28 14:17:25 2020

@author: QB

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Follow up: Could you solve it without converting the integer to a string?

 

Example 1:

Input: x = 121
Output: true
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Example 4:

Input: x = -101
Output: false
 

Constraints:

-231 <= x <= 231 - 1
"""

def isPalindrome(x):
    # return False if x falls outside of memory constraints
    # the contraint here is 0 because negative numbers are definitely not palindromes 
    if (x < 0 or x > 2**31 -1):
        return False
    # get the stopping point in the middle of the string         
    stop = int(len(str(x))/2)
    
    # turn int x into a list 
    x_list = [int(i) for i in str(x)]
        

    # initialize pointers 
    i=0
    j=-1
        
    while (i <= stop):
        if x_list[i] == x_list[j]:
            i += 1
            j -= 1
        else:
            return False
            
    return True
# COMPLEXITY
# TIME: O(N) with N is the lenght of the int i.e. number of digits 
# SPACE: O(1)
# leetcode: 84ms 14.4MB 15.07%

if __name__ == '__main__':
    x = 12321
    print(isPalindrome(x))