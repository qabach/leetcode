"""
Created on Mon Dec 21 14:10:13 2020

@author: QB

We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:

1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.


"""

def isOneBitCharacter(self, bits: List[int]) -> bool:
     ones_count = 0
        idx = len(bits) - 2
        
        while(bits[idx] != 0 and idx >= 0):
            if bits[idx] == 1:
                ones_count += 1
            idx -= 1
        # based on the condition of 1 that it cannot stand by itself i.e. either 11 or 10 not just 1
        # the count of ones will determine if the last 0 is needed to make a complete  bit intepretation 
        # An example:
        # 01110 -> False
        # 011110 -> True 
        return ones_count % 2 == 0
        
    


# COMPLEXITY 
# O(n)
# leetcode: 48ms 14.3MB 