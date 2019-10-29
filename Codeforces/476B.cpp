// Codeforces 2019
// Vinicius Rodrigues 15.10.2019
// Dreamoon and WiFi : Problem 476B

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

double pfat(int n, int k)
{
	if(n == 0 or n == k) return 1;
	
	double factor = 1.0f;
	for(int i = k+1; i <= n; i++)
		factor *= i;

	return factor;
}

double comb(int n, int r)
{
	if(n < r) return 0;
	return pfat(n, max(r, n - r)) / pfat(min(r, n - r), 0);
}

double calcScore(string str)
{
	return count(str.begin(), str.end(), '+') - count(str.begin(), str.end(), '-');
}

double calcSpace(string str)
{
	return count(str.begin(), str.end(), '?');
}

double calcPositives(float score, int spaces)
{
	return (score + spaces) / 2;
}

int main()
{
	string send, reach;
	cin >> send >> reach;
	
	double deltaScore = calcScore(send) - calcScore(reach);
	double spaces = calcSpace(reach);
	double positives = calcPositives(deltaScore, spaces);
	double prob;

	if(spaces > 0 and abs(deltaScore) <= spaces and round(positives) == positives)
		prob = comb(spaces, positives) * pow(0.5, positives) * pow(0.5, spaces - positives);
	else
		prob = !deltaScore ? 1.0f : 0.0f;


	printf("%.12f\n", prob);
	return 0;
}
