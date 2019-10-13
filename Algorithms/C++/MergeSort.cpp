#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(const vector<int> &vec, int l, int r)
{
  if (vec.size() <= 1)
    return vec;
  if (r - l <= 1)
    return {vec[l]};
  int m = (l + r) / 2;
  vector<int> left = mergeSort(vec, l, m);
  vector<int> right = mergeSort(vec, m, r);

  vector<int> ans;
  int iL = 0, iR = 0;

  while (iL < left.size() || iR < right.size())
  {
    if (iL == left.size())
      ans.push_back(right[iR++]);
    else if (iR == right.size())
      ans.push_back(left[iL++]);
    else
    {
      if (left[iL] < right[iR])
        ans.push_back(left[iL++]);
      else
        ans.push_back(right[iR++]);
    }
  }

  return ans;
}
