# -*- coding: utf-8 -*-
"""
Created on Mon Dec 21 16:46:47 2020

@author: QB
"""

def reverse(x):
        
        total = 0
        str_x = str(x)
        if str_x[0] == '-':
            pow = len(str_x) - 2
            end = 0
        else:
            pow = len(str_x) - 1
            end = -1
        
        for i in range(len(str_x)-1,end,-1):
            total += int(str_x[i])* 10**pow
            pow -= 1
        
        if str_x[0] == '-':
            total *= -1
        if total >= 2**31 -1 or total <= (-1)*2**31:
            return 0
        return total
# COMPLEXITY 
# O(n) with n is the length of the str(x)
# Space O(1)
# leetcode 36ms 14.1MB 31.26%
    
def reverse_copy(x):  
        if x > 0:  # handle positive numbers  
            a =  int(str(x)[::-1])  
        if x <=0:  # handle negative numbers  
            a = -1 * int(str(x*-1)[::-1])  
        # handle 32 bit overflow  
        mina = -2**31  
        maxa = 2**31 - 1  
        if a not in range(mina, maxa):  
            return 0  
        else:  
            return a
# COMPLEXITY 
# O(n) with n is the length of the str(x)
# Space O(1)
# leetcode 32ms 14.1MB 31.26%

    
if __name__ == '__main__':
    x = 1534236469
    print(reverse(x))
    
    
