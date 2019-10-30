#include<iostream>
#include<ctime>
using namespace std;

bool ifsorted(int* tab, int size)
{
	bool sorted = false;
	for (int i = 1; i < size; i++)
	{
		if (tab[i - 1] <= tab[i]) sorted = true;
		else return false;
	}
	return sorted;
}
 
int main() // bozo sort 
{
	srand(time(NULL));
	bool sorted = false;
	int size = 0;
	//long long int counter = 0;
	cin >> size;

	int* tab = new int[size];
	
	for (int i = 0; i < size; i++)
		cin >> tab[i];
	
	cout << endl;
	while (!sorted)
	{
		int x = rand() % size;
		int y = rand() % size;
		int temp = tab[x];
		tab[x] = tab[y];
		tab[y] = temp;
		sorted = ifsorted(tab, size);
		//counter++;
	}
	//for (int i = 0; i < size; i++)
	//	cout << tab[i] << endl;
	//cout << endl << endl << counter;
}