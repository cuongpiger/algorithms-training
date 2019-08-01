#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

/**
** Comment **
**/

int hashTable[10000100];
int collisions = 0;

inline int sumDigits(int n) {
	int sum = 0;

	while (n) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

inline int hashFunction(int n) {
	int tmp = sumDigits(n) ^ n;
	collisions += (hashTable[tmp] != 0);
	++hashTable[tmp];
	return tmp;
}

int main() {
	_FAST;
	int _maxHashValue = 0;
	pii mostOccur = { 696969696, 0 };

	_cin(n);
	for (int i = 0; i < n; ++i) {
		_cin(x);
		int tmp = hashFunction(x);
		_maxHashValue = max(_maxHashValue, tmp);
		if (hashTable[tmp] > mostOccur.second) mostOccur = { tmp, hashTable[tmp] };
		else if (hashTable[tmp] == mostOccur.second) mostOccur.first = min(mostOccur.first, tmp);
	}
	
	if (!collisions) {
		cout << _maxHashValue << " 0" << endl;
	}
	else {
		cout << mostOccur.first << " " << collisions << endl;
	}
	
	return 0;
}