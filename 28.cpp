// O(t*n) with t is number of test cases and n is number of cars

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int main() {
    FAST_IO;
    // FILE_IO;

    int n, cars[1010];
    while (true) {
        cin >> n; if (!n) break;
        for (int i = 0; i < n; ++i) cin >> cars[i];

        stack<int> alley;
        int nxt = 1;

        for (int i = 0; i < n; ++i) {
            alley.push(cars[i]);
            
            while (!alley.empty() && alley.top() == nxt) {
                nxt += 1;
                alley.pop();
            }
        }

        cout << (alley.empty() ? "yes" : "no") << endl;
    }

    return 0;
}