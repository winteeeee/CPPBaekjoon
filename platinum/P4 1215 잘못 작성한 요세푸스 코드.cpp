/*
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int minusN = 0;
    long long r = 0;
    if(n > k) {
        r += (k * (n - k));    //같은 값만 나오는 부분 미리 계산
        minusN += n - k;
    }

    if(n >= k - minusN) {
        if (k & 1) { //등차수열로 나오는 부분 미리 계산
            long long maxN = k / 2;
            r += ((maxN * (maxN + 1) / 2));
            minusN += (maxN + 1);
        }

        else {
            long long maxN = k / 2 - 1;
            r += ((maxN * (maxN + 1) / 2));
            minusN += (maxN + 1);
        }
    }

    for(int i = 2; i <= n - minusN; i++)
        r += (k % i);

    cout << r;
    return 0;
}*/
