/*
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll count1(ll a);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    cout << count1(b) - count1(a - 1);

    return 0;
}
ll count1(ll a) {
    if(a == 0)
        return 0;

    a++;
    int aMSB = log2(a);

    ll count = 0;
    for(int i = 0; i <= aMSB; i++) {
        ll temp = pow(2, i + 1);
        count += ((a / temp) * temp / 2);

        if(a % temp >= temp / 2) {
            count += (a % temp - temp / 2);
        }
    }

    return count;
}*/
