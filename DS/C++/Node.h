#include <iostream>

using namespace std;

class Node
{
 private:
          int Data;
 public:
         Node()
         {
           Data = 0;
         }
         
         Node(int data)
         {
           Data = data;
         }
         
         void Set_Data(int data)
         {
           Data = data;
         }
         
         int Get_Data()
         {
             return Data;
         }
         
         void Print()
         {
           cout << Data;
         }
};
