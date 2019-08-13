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
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a %b); }
inline double _distance(const pii &a, const pii &b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

//https://practice.geeksforgeeks.org/problems/palindromic-series/0
/**
** Comment **
**/

inline int sumDigits(string &s) {
	int sum = 0;
	for (int i = 0; i < s.length(); ++i) sum += (s[i] - '0');
	return sum;
}

inline bool isPalindrome(string s) {
	string tmp = s;
	int r = sumDigits(s);
	int l = 0;

	while (tmp.length() < r) {
		tmp += s;
	}

	r--;
	while (l <= r) {
		if (tmp[l] != tmp[r]) return false;
		++l;
		--r;
	}
	
	return true;
}
																								
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	_cin(tc);
	while (tc--) {
		string s;
		cin >> s;
		cout << (isPalindrome(s) ? "YES" : "NO") << endl;;
	}

	return 0;
}
