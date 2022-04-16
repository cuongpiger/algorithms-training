// O(n)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)


int main() {
    FAST_IO;
    // FILE_IO;

    int n, bars[1010] = {0}, unique = 0, highest = 0;
    cin >> n;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        unique += (bars[x] == 0);
        highest = max(highest, ++bars[x]);
    } 

    cout << highest << " " << unique;

    return 0;
}