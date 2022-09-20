/*
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

ll bfs(ll a, ll b);

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);

    printf("%d", bfs(a, b) + 1);
    return 0;
}

ll bfs(ll a, ll b) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({a, 0});

    while(!q.empty()) {
        pair<ll, ll> cur = q.top(); q.pop();
        if(cur.first == b) {
            return cur.second;
        }

        if(cur.first > b)
            break;

        q.push({2 * cur.first, cur.second + 1});
        q.push({10 * cur.first + 1, cur.second + 1});
    }

    return -2;
}
*/
