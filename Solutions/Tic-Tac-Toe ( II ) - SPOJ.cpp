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

//==========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define sit set<int>::iterator
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
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvi;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef queue<pii> qpii;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//==========================================================================================================================

//https://www.spoj.com/problems/TOE2/
/**
** Comment **
**/
string brd;

inline void check(char chr, int i, bool& res) {
	if (brd[3 * i] == chr && brd[3 * i + 1] == chr && brd[3 * i + 2] == chr) {
		res = true;
	}
	else if (brd[i] == chr && brd[i + 3] == chr && brd[i + 6] == chr) {
		res = true;
	}
	else if (brd[0] == chr && brd[4] == chr && brd[8] == chr) {
		res = true;
	}
	else if (brd[2] == chr && brd[4] == chr && brd[6] == chr) {
		res = true;
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);

	while (cin >> brd && brd != "end") {
		int cntX = 0, cntO = 0;
		bool winX = false, winO = false;
		bool res = true;

		for (int i = 0; i < 9; ++i) {
			brd[i] == 'X' ? ++cntX : brd[i] == 'O' ? ++cntO : cntO += 0;
		}

		for (int i = 0; i < 3; ++i) {
			check('X', i, winX);
			check('O', i, winO);
		}

		if (cntX - cntO > 1) {
			res = false;
		}
		else if (cntO > cntX) {
			res = false;
		}
		else if (winX && (cntX - cntO) != 1) {
			res = false;
		}
		else if (winO && (cntX - cntO) != 0) {
			res = false;
		}
		else if (winX && winO) {
			res = false;
		}
		else if (!winX && !winO && cntX + cntO != 9) {
			res = false;
		}

		if (res) {
			cout << "valid" << endl;
		}
		else {
			cout << "invalid" << endl;
		}
	}

	return 0;
}