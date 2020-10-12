#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Matrix
{
public:
   Matrix() {}
   vector<vector<int>> a;
   Matrix operator+(const Matrix &m)
   {
      Matrix sum = (*this);
      for (int i = 0; i < a.size(); i++)
         for (int j = 0; j < a[i].size(); j++)
            sum.a[i][j] += m.a[i][j];
      return sum;
   }
};
int main()
{
   int cases, k;
   cin >> cases;
   for (k = 0; k < cases; k++)
   {
      Matrix x;
      Matrix y;
      Matrix result;
      int n, m, i, j;
      cin >> n >> m;
      for (i = 0; i < n; i++)
      {
         vector<int> b;
         int num;
         for (j = 0; j < m; j++)
         {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for (i = 0; i < n; i++)
      {
         vector<int> b;
         int num;
         for (j = 0; j < m; j++)
         {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x + y;
      for (i = 0; i < n; i++)
      {
         for (j = 0; j < m; j++)
         {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }
   return 0;
}
... 
class Matrix
{
public:
   vector<vector<int>> a;
};
Matrix operator+(Matrix matrix1, Matrix matrix2)
{
   Matrix result;
   int num;
   for (int i = 0; i < matrix1.a.size(); i++)
   {
      vector<int> new_row;
      num = 0;
      for (int j = 0; j < matrix1.a[0].size(); j++)
      {
         num = matrix1.a[i][j] + matrix2.a[i][j];
         new_row.push_back(num);
      }
      result.a.push_back(new_row);
   }
   return result;
}