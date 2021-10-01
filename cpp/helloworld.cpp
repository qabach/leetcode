#include <iostream>
#include <array>
int main()
{
	std::array<int,3> myArr [3] = {1,2,3};

	for (int i = 0; i < myArr.size(); i++)
	{
		std::cout << myArr[i] << std::endl;
	}
}