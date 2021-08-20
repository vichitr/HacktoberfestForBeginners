#include<iostream>
using namespace std;

int binarySearch (int a[], int items, int search, int position);

int main()
{
  int items;
  cout << "\nHow many elements do you want in your array? ";
  cin >> items;
  int a[items];
  cout << "\nPlease enter " << items << " values in sorted order: ";
  for (int i = 0; i < items; i++)
  {
    cin >> a[i];
    cout << a[i];
  }
  
  int search;                                                     // stores number user wants to search for
  cout << "\nWhat item do you want to search for? ";
  cin >> search;
  int position = -1;
  int result;
  result = binarySearch(a, items, search, position);
  if (result == -1)
  {
    cout << "\nItem not found\n";
  }
  else
  {
    cout << "\nItem found at position " << result << "\n";
  }
  
  
  return 0;
}
// -----------------------------------------------------------------------------------------------------------------------
int binarySearch (int a[], int items, int search, int position)
{
  int first = 0;                                                  // stores index of first element in array 
  int last = items;                                               
  int mid;                                                        // stores index of midpoint of array 
  bool found;
  while (first <= last && !found)
  {
    mid = (first + last)/2;
    if (a[mid] < search)
    {
      first = mid + 1;
    }
    else if (a[mid] > search)
    {
      last = mid - 1;
    }
    else
    {
      found = true;
      position = mid;
    }
  }
    return position;
}
