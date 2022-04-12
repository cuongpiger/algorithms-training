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

    int n, cards[1010], score[2] = {0};

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    int i = 0, j = n - 1, k = 0;
    while (i <= j) {
        if (cards[i] > cards[j]) {
            score[k] += cards[i++];
        } else {
            score[k] += cards[j--];
        }

        k = 1 - k;
    }

    cout << score[0] << " " << score[1];

    return 0;
}