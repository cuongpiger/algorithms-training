//https://textsaver.flap.tv/lists/2rtv
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <fstream>
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

//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/aish-and-xor-2/
/*
- Mảng xorAtIndex dùng để lưu kết quả khi xor các giá trị trước index hiện tại (index - 1) với giá trị tại index hiện tại
- Mảng countZeroAtIndex dùng để đếm số lượng số 0 tới index hiện tại
- xorAtIndex[r] - xorAtIndex[l - 1] để tính kết quả khi xor toàn bộ các giá trị trong khoảng từ [l, r] là bao nhiêu để giá trị tại xorAtIndex[r] bằng như vậy
*/

int xorAtIndex[(int)1e5 + 5], countZeroAtIndex[(int)1e5 + 5];

int main() {
	int n, x, q, l, r;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> x;
		xorAtIndex[i] = xorAtIndex[i - 1] ^ x;
		countZeroAtIndex[i] = countZeroAtIndex[i - 1];

		if (!x) ++countZeroAtIndex[i];
	}

	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << (xorAtIndex[r] ^ xorAtIndex[l - 1]) << " " << (countZeroAtIndex[r] - countZeroAtIndex[l - 1]) << endl;
	}
	
	return 0;
}
