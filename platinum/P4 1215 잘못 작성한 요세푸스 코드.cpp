/*
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k;
    cin >> n >> k;
    if(n == 1)
        cout << "0";

    else {
 */
/*       if (k > n)
            swap(k, n);*//*


        long long r = k * n;
        long long prev = k;
        long long cur;
        for (int i = 2; i <= log2(k); i++) {
            cur = k / i;
            long long length = prev - cur;
            r -= (i - 1) * ((length) * (prev - length + 1 + prev) / 2);
            prev = cur;
        }

        for (int i = 1; i <= prev; i++) {
            r -= i * (k / i);
        }

        long long temp = 0;
        for(int i = 1; i <= n; i++) {
            temp += (k % i);
        }

        cout << temp << "\n";
        cout << r;
    }
    return 0;
}*/
