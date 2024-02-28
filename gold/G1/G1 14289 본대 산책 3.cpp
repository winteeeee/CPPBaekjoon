/*
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, d;
const ll MOD = 1e9 + 7;
vector<vector<ll>> pow(vector<vector<ll>> building, int num);
vector<vector<ll>> mul(vector<vector<ll>> g1, vector<vector<ll>> g2);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<ll>> building(n, vector<ll>(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        building[a][b] = building[b][a] = 1;
    }

    cin >> d;
    vector<vector<ll>> resultBuilding = pow(building, d);

    ll result = resultBuilding[0][0];
    cout << result;
    return 0;
}

vector<vector<ll>> pow(vector<vector<ll>> building, int num) {
    if(num == 1)
        return building;
    else {
        vector<vector<ll>> temp = pow(building, num / 2);
        if(num & 1)
            return mul(mul(temp, temp), building);
        else
            return mul(temp, temp);
    }
}

vector<vector<ll>> mul(vector<vector<ll>>g1, vector<vector<ll>> g2) {
    vector<vector<ll>> result(n, vector<ll>(n, 0));

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += (g1[i][k] * g2[k][j]);
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}*/
