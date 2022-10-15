/*
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N, m, d;
const int MOD = 1e9 + 7;
vector<vector<ll>> pow(vector<vector<ll>> building, int n);
vector<vector<ll>> mul(vector<vector<ll>> g1, vector<vector<ll>> g2);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> m;
    vector<vector<ll>> building(N, vector<ll>(N, 0));
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        building[a][b] = 1;
        building[b][a] = 1;
    }

    cin >> d;
    vector<vector<ll>> resultBuilding = pow(building, d);

    ll result = resultBuilding[0][0];
    cout << result % MOD;
    return 0;
}

vector<vector<ll>> pow(vector<vector<ll>> building, int n) {
    if(n == 1)
        return building;
    else {
        vector<vector<ll>> temp = pow(building, n / 2);
        if(n & 1)
            return mul(mul(temp, temp), building);
        else
            return mul(temp, temp);
    }
}

vector<vector<ll>> mul(vector<vector<ll>>g1, vector<vector<ll>> g2) {
    vector<vector<ll>> result(N, vector<ll>(N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                result[i][j] += (g1[i][k] % MOD * g2[k][j] % MOD % MOD);
            }
        }
    }

    return result;
}
*/
