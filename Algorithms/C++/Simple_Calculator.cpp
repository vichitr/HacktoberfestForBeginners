//This program performs basic arithmetic operations
//Defining simple calculator
#include <iostream>

using namespace std;
//Defining function for arithmetic operations
float operation(float num1, float num2, char oper)
{
   while (true)
    {
	  if (oper == '+')   return num1 + num2;
      if (oper == '-') 	 return num1 - num2;
      if (oper == '*')   return num1 * num2;
      if (oper == '/')   return num1 / num2;
			cout << "!!wrong operator!!\nSelect one from the following (+,-,*,/) : ";
			cin >> oper;
	}
}

int main()
{
	float op1, op2, result;
	char oper;
	cout << "The program is calculator of basic calculations ";
	cout << "Enter '+' for Addition\n";
	cout << "Enter '-' for Subtraction\n";
	cout << "Enter '*' for Multiplication\n";
	cout << "Enter '/' for Division\n";
	
	cout << "\nEnter 1st Operand : ";
	cin >> op1;
	cout << "\nEnter 2nd Operand : ";
	cin >> op2;
	cout << "\nEnter operator : ";
	cin >> oper;
	result = operation(op1, op2, oper);

	cout << "This result of integer expression is : " << result << endl;
	system("pause");
	return 0;
}