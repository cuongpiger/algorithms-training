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
#include <unordered_set>
#include <unordered_map>
using namespace std;
 
//=============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define _i(X) (int)(X)
const double pi = 3.14159265359;
typedef uint64_t uit;
typedef long long ll;
typedef unsigned long long ull;
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
 
int main() {
	_FAST;
	string s, b;
	int k;
	const int bse = 29;
	unordered_set<uit> goodStr;
 
	cin >> s >> b >> k;
 
	for (int i = 0; i < s.length(); ++i) {
		uit hashValue = 0;
		for (int j = i, noBad = 0; j >= 0; --j) {
			hashValue = hashValue * bse + (s[j] - 'a' + 1); // Add 1 to reduce the risk of collisions
			//example: hash("aaaabcd") = hash("bcd") from 'a' - 'a' = 0
			noBad += (b[s[j] - 'a'] == '0');
 
			if (noBad <= k)
				goodStr.insert(hashValue);
			else
				break;
		}
	}
	
	cout << goodStr.size() << endl;
 
	return 0;
}