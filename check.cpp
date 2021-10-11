#include <iostream>
#include <string>

using namespace std;

string arith_geo_sequence(int nums[], const int size) {

	int diff_arith = 0, diff_geo = 0;
	bool arith_flag = true, geo_flag = true;

	diff_arith = nums[1] - nums[0];
	diff_geo = nums[1] / nums[0];

	for (int y = 0; y < size-1 && arith_flag; y++)
	{
		arith_flag = false;
		
		if (nums[y] + diff_arith == nums[y + 1])
		{
			arith_flag = true;
		}
	}
	for (int z = 0; z < size - 1 && geo_flag; z++)
	{
		geo_flag = false;
		
		if (nums[z] * diff_geo == nums[z + 1])
		{
			geo_flag = true;
		}
	}

	if (arith_flag)
	{
		return "Arithmetic sequence";
	}
	else if (geo_flag)
	{
		return "Geometric sequence";
	}
	else
	{
		return "Not Arithmetic/Geometric sequence";
	}
}

int main() {

	int nums1[] = { 1, 3, 5, 7 };
	int nums2[] = { 2, 4, 8, 16, 32 };
	int nums3[] = { 1, 2, 3, 4, 5, 6, 8 };
	int nums4[] = { 3, 6, 9, 12 };
	cout << arith_geo_sequence(nums1, sizeof(nums1) / sizeof(nums1[0])) << endl;
	cout << arith_geo_sequence(nums2, sizeof(nums2) / sizeof(nums2[0])) << endl;
	cout << arith_geo_sequence(nums3, sizeof(nums3) / sizeof(nums3[0])) << endl;
	cout << arith_geo_sequence(nums4, sizeof(nums4) / sizeof(nums4[0])) << endl;
	return 0;
