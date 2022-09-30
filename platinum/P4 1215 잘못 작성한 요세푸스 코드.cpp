/*
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k;
    cin >> n >> k;

    long long r = k * n;
    long long length;
    long long firstNum;
    long long lastNum;

    for(int i = k; i >= 1;) {
        firstNum = k / (i + 1) + 1;
        lastNum = k / i;
        if(lastNum > n) {
            lastNum = n;
            length = lastNum - firstNum + 1;
            r -= i * (length * (firstNum + lastNum) / 2);
            break;
        }
        length = lastNum - firstNum + 1;

        r -= i * (length * (firstNum + lastNum) / 2);
        i = k / ((k / i) + 1);
    }

    cout << r;
    return 0;
}
*/
