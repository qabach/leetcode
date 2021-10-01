

#include <iostream>
#include <vector>
#include <array>

int maxSubarray(std::vector<int> &nums)
{
	int local_max = 0;
	int global_max = INT_MIN; //negative infinity

	for (int i = 0; i < nums.size(); i++)
	{
		local_max  = std::max(nums[i], nums[i] + local_max);
		if (global_max < local_max)
		{
			global_max = local_max;
		}
	}

	return global_max;
}


int main()
{
	std::array<int,9> myints = {-2,1,-3,4,-1,2,1,-5,4};
	std::vector<int> nums;

	for (int i = 0; i < myints.size(); i++)
	{
		nums.push_back(myints[i]);
	}

	std::cout << maxSubarray(nums) << std::endl;

	return 0;
}