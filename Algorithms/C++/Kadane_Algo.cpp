#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(vector<int> nums)
{
  int maxSum = INT_MIN, currMax = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    currMax = currMax + nums[i];
    if (maxSum < currMax)
      maxSum = currMax;

    if (currMax < 0)
      currMax = 0;
  }
  return maxSum;
}
