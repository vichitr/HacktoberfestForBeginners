#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int l, int r)
{
  int pivot = vec[r];
  int i = l - 1;
  for (int j = l; j < r; j++)
  {
    cout << j << endl;
    cout << i << endl;
    if (vec[j] <= pivot)
      swap(vec[++i], vec[j]);
  }

  swap(vec[i + 1], vec[r]);

  return (i + 1);
}

void quicksort(vector<int> &vec, int l, int r)
{
  if (l < r)
  {
    int pivot = partition(vec, l, r);
    quicksort(vec, l, pivot - 1);
    quicksort(vec, pivot, r);
  }
}
