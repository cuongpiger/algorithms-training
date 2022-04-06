#include <iostream>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int main() {
    FAST_IO;
    // FILE_IO;

    int noBtn, btn, no1 = 0;

    cin >> noBtn;
    for (int i = 0; i < noBtn; ++i) {
        cin >> btn;
        no1 += btn;
    }

    if (noBtn == 1) {
        noBtn = 2;
    }

    if (noBtn - no1 == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}