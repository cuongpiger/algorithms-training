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
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define x first
#define y second
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================

//https://codeforces.com/problemset/problem/886/C
/**
 ** Comment **
 **/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, tmp, room = 1; cin >> n;
	vector<int> minutes(n + 1, -1);
	minutes[0] = 1; // Petya is in room 1 at minute 0

	for (int i = 1; i <= n; ++i){
		cin >> tmp;

		if (minutes[tmp] == -1){ // if no room is visited at the minute equal to tmp
			room += 1;
			minutes[i] = room;
		}
		else { // if this room has visited
			minutes[i] = minutes[tmp];
			minutes[tmp] = -1;
		}
	}

	cout << room << endl;

	return 0;
}
