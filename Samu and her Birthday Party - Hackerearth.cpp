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
#include <sstream>
using namespace std;

//=============================================================================================
const double pi = 3.14159265359;
#define p(a) ((a) * (a))
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================

/**
 ** Comment **
Can learn more about counting the number of bits 1 in an integer here:
https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
 **/

inline int countSetBits(int &x) {
	int c = 0;

	while (x) {
		c += x & 1;
		x >>= 1;
	}

	return c;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int tc, n, k; cin >> tc;
	string order;

	while (tc--) {
		cin >> n >> k;
		vector<int> orderCodes(n); 
		vector<int> acceptedCodes;

		/*Create an array named 'orderCodes' to store Samu's order codes of friends after converting
		them to integer*/
		for (int i = 0; i < n; ++i) {
			cin >> order;
			orderCodes[i] = stoi(order, nullptr, 2);
		}

		/*- The number of binary strings to order for menu will be between 1 and less than (1 << k)
		  - The line of 'for j' was used to check if the code 'i' can be used for all codes that
		  Samu's friends require. If it's possible, add it to the array 'acceptedCodes'*/
		for (int i = 1; i < (1 << k); ++i) {
			bool flag = 0;

			for (int j = 0; j < n; ++j) {
				if (!(i & orderCodes[j])) {
					flag = 1; 
					break;
				}
			}

			if (!flag) acceptedCodes.push_back(i);
		}

		/*The variable 'minDishes' is the answer of this problem, just count number of bits 1 in 
		each elements of the array 'acceptedCodes' and get the smallest value*/
		int minDishes = 69;

		for (int i = 0; i < acceptedCodes.size(); ++i) {
			minDishes = min(minDishes ,countSetBits(acceptedCodes[i]));
		}

		cout << minDishes << endl;
	}

	return 0;
}
