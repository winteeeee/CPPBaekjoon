#include <iostream>
typedef long long ll;
using namespace std;

ll cal(ll a, ll b);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;
    cin >> a >> b;
    cout << cal(a, b);

    return 0;
}
ll cal(ll a, ll b) {
    return (a + b) * (a - b);
}