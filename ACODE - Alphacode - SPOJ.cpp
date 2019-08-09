#pragma warning(disable:4996)
#include <iostream>
#include <cstdint>
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
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef pair<ll, string> plls;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

/**
** Comment **
- Suppose, the number 25114 is numbered from 0 to 4. So when we check the number 1 at index 3th, we will check the index
(i - 1)th if the values in these 2 indexs will create a character which it's worth <= 26 or not?
+ If <= 26, we only add this character at index (i - 2)th, ie after the number 5 at index 1th, so the number of ways to add this
character will equal to the number of ways at index (i - 2)th
+ If > 26, that means that only the character at index ith which is valid, and if this character is different from '0', so the
number of ways to add this character will equal to the number of ways at index (i - 1)th
**/

int main() {
	_FAST;
	string s;

	while (cin >> s && s[0] != '0') {
		int len = s.size();
		vll dp(len + 1, 0);
		dp[0] = dp[1] = 1;

		for (int i = 2; i <= len; ++i) {
			int ch1 = s[i - 1] - '0', ch2 = s[i - 2] - '0';

			if (ch2 == 1 || (ch2 == 2 && ch1 <= 6)) dp[i] += dp[i - 2]; // check the characters has 2 digits
			if (ch1 != 0) dp[i] += dp[i - 1]; // check the character has only one digit
		}

		cout << dp[len] << endl;
	}

	return 0;
}