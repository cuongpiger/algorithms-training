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
#define vit vector<int>::iterator
#define dqit deque<int>::iterator
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define sortRev greater<int>()
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<double, int> pdi;
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
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvint;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvint;
typedef vector<vector<vector<long long>>> vvvll;
typedef deque<int> dq;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//=========================================================================================================================

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1842
/**
** Comment **
**/

#define timeArr first
#define index second

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int tc;
	string br = "";
	cin >> tc;

	while (tc--) {
		int n, t, m, tArrive;
		queue<pii> cars[2];
		vint res;
		string side;

		cin >> n >> t >> m;
		res = vint(m);
		for (int i = 0; i < m; ++i) {
			cin >> tArrive >> side;
			side[0] == 'l' ? cars[0].push({ tArrive, i }) : cars[1].push({ tArrive, i });
		}
		cars[0].push({ 1e9, -1 });
		cars[1].push({ 1e9, -1 });

		int sideFerry = 0; // at left
		int go = 0;
		int cntCars = 0;

		while (cars[0].size() > 1 || cars[1].size() > 1) {
			cntCars = 0;

			while (cntCars < n && cars[sideFerry].front().timeArr <= go) {
				res[cars[sideFerry].front().index] = go + t;
				cars[sideFerry].pop();
				++cntCars;
			}

			if (cntCars) {
				go += t;
				sideFerry = 1 - sideFerry;
			}
			else {
				int minn = min(cars[sideFerry].front().timeArr, cars[1 - sideFerry].front().timeArr);
				go = max(go, minn);

				if (cars[sideFerry].front().timeArr != minn) {
					go += t;
					sideFerry = 1 - sideFerry;
				}
			}
		}

		cout << br; br = "\n";
		for (int i = 0; i < m; ++i) {
			cout << res[i] << "\n";
		}
	}

	return 0;
}