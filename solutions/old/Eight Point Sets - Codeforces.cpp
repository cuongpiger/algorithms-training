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
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://codeforces.com/contest/334/problem/B
/**
** Comment **
**/

struct COOR {
	int X, Y;

	bool operator < (const COOR& C) {
		if (X < C.X || (X == C.X && Y < C.Y)) {
			return true;
		}

		return false;
	}
};

int main() {
	FAST_IO;
	vector<COOR> a(8);

	for (int i = 0; i < 8; ++i) {
		cin >> a[i].X >> a[i].Y;
	}

	sort(a.begin(), a.end());

	int minX = a[0].X, maxX = a[7].X, midX = a[3].X;
	int minY = a[0].Y, maxY = a[7].Y, midY = a[1].Y;

	if (midX == minX || midX == maxX || midY == minY || midY == maxY) {
		cout << "ugly" << endl;
		return 0;
	}

	if (a[0].X != minX || a[0].Y != minY ||
		a[1].X != minX || a[1].Y != midY ||
		a[2].X != minX || a[2].Y != maxY ||
		a[3].X != midX || a[3].Y != minY ||
		a[4].X != midX || a[4].Y != maxY ||
		a[5].X != maxX || a[5].Y != minY ||
		a[6].X != maxX || a[6].Y != midY ||
		a[7].X != maxX || a[7].Y != maxY) {
		cout << "ugly" << endl;
		return 0;
	}

	cout << "respectable" << endl;
	return 0;
}