// O(n*log(n))

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

    int k, s = 0, i = -1;
    int m[12] = {0};
    
    cin >> k;
    for (int i = 0; i < 12; ++i) cin >> m[i];
 
    sort(m, m + sizeof(m)/sizeof(m[0]), greater<int>());

    while (i < 11 && s < k) {
        s += m[++i];
    }

    cout << (s >= k ? i + 1 : -1);

    return 0;
}