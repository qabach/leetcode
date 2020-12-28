# -*- coding: utf-8 -*-
"""
Created on Mon Dec 28 15:36:25 2020

@author: QB
"""

def romanToInt(s):
    # initialize the symbol value lists
    symbol = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
    val = [1,5,10,50,100,500,1000]
        
    # the return total
    total = 0
    
    # convert string to list 
    s = list(s)
    
    # iterate through the whole string
    for i in range(len(s)):
        # if last value, just add 
        if i == len(s) -1:
            total += val[symbol.index(s[i])]
        else:
            # check if the next value is larger or smaller
            # if smaller    -> deduction 
            # else          -> addition
            if symbol.index(s[i]) < symbol.index(s[i+1]):
                total -= val[symbol.index(s[i])]
            else:
                total += val[symbol.index(s[i])]
    return total

# COMPLEXITY 
# TIME: O(N)
# SPACE: O(1)
# leetcode: 56ms 14.2MB 19.18% 

def romanToInt_copy(self, s: str) -> int:
        _dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
                 'C': 100, 'D': 500, 'M': 1000}
        prev = 0
        total = 0

        for i in s[::-1]:
            curr = _dict[i]
            if prev > curr:
                total -= curr
            else:
                total += curr
            prev = curr
        return total
# COMPLEXITY
# TIME: O(N)
# SPACE: O(1)
# leetcode 32ms 14.3MB 99.39% 


if __name__ == '__main__':
    s = 'MCMXCIV'
    print (romanToInt(s))