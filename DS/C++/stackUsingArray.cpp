#include <bits/stdc++.h>
using namespace std;
#define SIZE 100
int Stack[SIZE], n = SIZE, top = -1;
void push(int val)
{
        if (top >= n - 1)
                cout << "Stack Overflow" << endl;
        else
        {
                top++;
                Stack[top] = val;
        }
}
void pop()
{
        if (top <= -1)
                cout << "Stack Underflow" << endl;
        else
        {
                cout << "The popped element is " << Stack[top] << endl;
                top--;
        }
}
void display()
{
        if (top >= 0)
        {
                cout << "Stack elements are:  ";
                for (int i = top; i >= 0; i--)
                        cout << Stack[i] << "  ";
                cout << endl;
        }
        else
                cout << "Stack is empty" << endl;
}
int main()
{
        int ch, val;

        do
        {
                cout << "1) Push in Stack" << endl;
                cout << "2) Pop from Stack" << endl;
                cout << "3) Display Stack" << endl;
                cout << "0) Exit" << endl;

                cout << "Enter choice: ";
                cin >> ch;

                switch (ch)
                {
                case 1:
                {
                        system("cls");
                        cout << "Enter value to be pushed: ";
                        cin >> val;
                        push(val);
                        break;
                }
                case 2:
                {
                        system("cls");
                        pop();
                        break;
                }
                case 3:
                {
                        system("cls");
                        display();
                        break;
                }
                default:
                {
                        if (ch == 0)
                        {
                                cout << "Terminating program. Please wait......" << endl;
                                _sleep(5000);
                                cout << "Program terminated" << endl;
                                exit(0);
                        }
                        else
                        {
                                cout << "Invalid input. Please try again..........." << endl;
                        }
                }
                }
        } while (ch != 0);
        return 0;
}