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

//https://www.spoj.com/problems/MMASS/
/**
** Comment **
**/

inline int calcMass(char x) {
	if (x == 'C') {
		return 12;
	}

	if (x == 'H') {
		return 1;
	}

	return 16;
}

int main() {
	FAST_IO;
	string fml;
	stack<int> truck;
	int sum = 0;
	cin >> fml;

	for (int i = 0; i < fml.size(); ++i) {
		if (fml[i] == 'C' || fml[i] == 'H' || fml[i] == 'O') {
			truck.push(calcMass(fml[i]));
		}
		else if (fml[i] == '(') {
			truck.push(0);
		}
		else if ('0' <= fml[i] && fml[i] <= '9') {
			int top = truck.top();
			truck.pop();
			int reform = top * DEC(fml[i]);
			truck.push(reform);
		}
		else {
			int tmpSum = 0;

			while (truck.top()) {
				tmpSum += truck.top();
				truck.pop();
			}

			if (!truck.top()) {
				truck.pop();
			}

			truck.push(tmpSum);
		}
	}

	while (!truck.empty()) {
		sum += truck.top();
		truck.pop();
	}

	cout << sum << endl;

	return 0;
}