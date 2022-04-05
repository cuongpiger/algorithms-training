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

//=========================================================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define _i(X) (int)(X)
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
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
//=========================================================================================================================

//http://lightoj.com/volume_showproblem.php?problem=1013
/**
 ** Comment **
https://imgur.com/gallery/oFvsLW6
- Let dp[i][j] -> The length of the shortest string that contains a[1…i] and b[1….j] as subsequence
- Let dp2[i][j] -> Total number of unique shortest strings which contain a[1…i] and b[1….j] as subsequence
 **/

const int MAX = 35;
ll dp[MAX][MAX], dp2[MAX][MAX];
int lena, lenb;

int main() {
	_FAST;
	
	_cin(tc);
	for (int cs = 1; cs <= tc; ++cs) {
		string a = " ", b = " ", tmp;
		cin >> tmp; a += tmp;
		cin >> tmp; b += tmp;

		for (int i = 0; i < MAX; i++) {
			dp[0][i] = dp[i][0] = i;
			dp2[i][0] = dp2[0][i] = 1;
		}
		lena = a.size() - 1, lenb = b.size() - 1;

		for (int i = 1; a[i]; i++) {
			for (int j = 1; b[j]; j++) {
				if (a[i] == b[j]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];  
					dp2[i][j] = dp2[i - 1][j - 1];
				}
				else {
					dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
					if (dp[i][j - 1] == dp[i - 1][j]) 
						dp2[i][j] = dp2[i][j - 1] + dp2[i - 1][j];
					else 
						dp2[i][j] = ((dp[i][j - 1] < dp[i - 1][j]) ? dp2[i][j - 1] : dp2[i - 1][j]);
				}
			}
		}
		cout << "Case " << cs << ": " << dp[lena][lenb] << " " << dp2[lena][lenb] << endl;
	}

	return 0;
}
