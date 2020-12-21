"""
Created on Mon Dec 21 14:10:13 2020

@author: QB

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].


"""


# BRUTE FORCE SOLUTION 
def twoSum(self, nums: List[int], target: int) -> List[int]:
        sol = [] 
        for i in range(0,len(nums)):
            for j in range(0,len(nums)):
                if nums[i] + nums[j] == target:
                    sol.append(i)
                    sol.append(j)
        return sol
    
# COMPLEXITY O(n^2)
#   (n-1)(n-2)/2 deducted from Gauss's sum 
# leetcode: 460ms 14.5MB





# OPTIMIZE SOLUTION USING HASHMAP 
# TWO-PASS HASH MAP 
def twoSum(self, nums: List[int], target: int) -> List[int]:
        sol = [] 
        map = {}
        for i in range(0,len(nums)):
            map[nums[i]] = i            
        found = False
        j = 0
        while (not found and j < len(nums)):
            if ((target - nums[j]) in map.keys()) and (j != map[target-nums[j]]):
                sol.append(j)
                sol.append(map[target-nums[j]])
                found = True
            j += 1
        return sol

# COMPLEXITY 
# O(n) to map
# O(i) to look up and O(n) to loop through to array 
# leetcode: 48ms 14.5MB 


# OPTIMIZE SOLUTION USING HASHMAP
# ONE-PASS HASH MAP
# THIS SOLUTION IS BETTER SINCE IT CHECK FOR THE COMPLEMENT WHILE CONSTRUCTING THE MAP

def twoSum(self, nums:List[int], target: int) -> List[int]:
    sol = []
    map = {}
    for i in range(0, len(nums)):
        compement = target - nums[i]
        if (compement in map.keys()):
            sol.append(i)
            sol.append(map[compement])
            return sol
        map[nums[i]] = i
    return sol