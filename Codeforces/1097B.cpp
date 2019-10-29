// Codeforces 2019
// Vinicius Rodrigues 15.10.2019
// Petr and a Combination Lock : Problem 1097B

#include <stdio.h>
#include <vector>

using namespace std;

void input(vector<int> *vec)
{
	int rots, num;
	scanf("%d", &rots);
	for(int i = 0; i < rots; i++)
	{
		scanf("%d", &num);
		vec -> push_back(num);
	}
}

int sumWithBitmask(vector<int> nums, int bitmask)
{
	int summation = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(bitmask bitand 1 << i)
			summation += nums[i];
		else
			summation -= nums[i];
	} 
	return summation;
}

bool checkIfValid(vector<int> nums)
{
	for(int i = 0; i < 1 << nums.size(); i++)
		if(sumWithBitmask(nums, i) % 360 == 0)
			return true;
	return false;
}

int main()
{
	vector<int> nums(0);
	input(&nums);
	if(checkIfValid(nums))
		printf("YES\n");
	else
		printf("NO\n");
}
