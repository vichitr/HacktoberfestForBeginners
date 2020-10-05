#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

//int a[100000];

int main(){

	string F, M, S;
	cin >> F >> M >> S;

	string answer = "?";

	if (F == "paper" && M == "rock" && S == "rock") {
		answer = "F";
	}
	if (F == "rock" && M == "scissors" && S == "scissors") {
		answer = "F";
	}
	if (F == "scissors" && M == "paper" && S == "paper") {
		answer = "F";
	}

	if (M == "paper" && F == "rock" && S == "rock") {
		answer = "M";
	}
	if (M == "rock" && F == "scissors" && S == "scissors") {
		answer = "M";
	}
	if (M == "scissors" && F == "paper" && S == "paper") {
		answer = "M";
	}

	if (S == "paper" && M == "rock" && F == "rock") {
		answer = "S";
	}
	if (S == "rock" && M == "scissors" && F == "scissors") {
		answer = "S";
	}
	if (S == "scissors" && M == "paper" && F == "paper") {
		answer = "S";
	}

	cout << answer << endl;
	return 0;
}
