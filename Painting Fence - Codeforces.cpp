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
#define x(a) (a.first)
#define y(a) (a.second)
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

/**
 ** Comment **
 **/

vector<int> fence;
int n;

/*How this function works: This function contains 3 parameters
+ The first and second parameters are the indexs of left and right of the 'fence' array
to be checked
+ The remaining parameter is the shortest plank height before calling recursion down

Step 1:
		- It only works when (l < r), so when (l >= r) there will be not any planks to check anymore 
Step 2:
		- Find the shortes plank in the current range and place it's index for the variable m
		- Calling recursion to work with the LEFT side of the array (from l to less than m) and then place the value for the shortest_left variable
		- Calling recursion to work with the RIGHT side of the array (from m + 1 to less than r) and then place the value for the shortest_right variable
Step 3: 
		- The answer of this funtion will be the minimum between (r - l) and ((fence[m] - shortest) + shortest_left + shortest_right)
		*** Note ***
		So why do we need to subtract 'shortest' variable from fence[m], because 'shortest' variable is the number of horizontal strokes
		of recursion before it
*/
int solve(int l, int r, int shortest){
	if (l >= r) return 0;

	int m = l; // find the first shortest plank in range from l to less than r
	for (int i = l; i < r; ++i){
		if (fence[m] > fence[i]){
			m = i;
		}
	}

	int shortest_left = solve(l, m, fence[m]);
	int shortest_right = solve(m + 1, r, fence[m]);

	/*the required maximum number of strokes is always less than or equal to (r - l)*/
	return min(r - l, (fence[m] - shortest) + shortest_left + shortest_right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	fence.resize(n);
	for (int i = 0; i < n; ++i){
		cin >> fence[i];
	}

	cout << solve(0, n, 0); /* In the first calling function, the 'shorstest' variable's value must be 0, because there 
							are no recursion calls before it*/

	return 0;
}