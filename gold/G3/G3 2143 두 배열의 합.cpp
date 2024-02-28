/*
#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int B[1001];
vector<int> APrefixSum;
vector<int> BPrefixSum;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, sum;
    cin >> t >> n;

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }

    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = i; j < n; j++) {
            sum += A[j];
            APrefixSum.push_back(sum);
        }
    }

    for(int i = 0; i < m; i++) {
        sum = 0;
        for(int j = i; j < m; j++) {
            sum += B[j];
            BPrefixSum.push_back(sum);
        }
    }

    sort(BPrefixSum.begin(), BPrefixSum.end());
    long long count = 0;
    for(int i = 0; i < APrefixSum.size(); i++) {
        int low = lower_bound(BPrefixSum.begin(),  BPrefixSum.end(), t - APrefixSum[i]) - BPrefixSum.begin();
        int high = upper_bound(BPrefixSum.begin(),  BPrefixSum.end(), t - APrefixSum[i]) - BPrefixSum.begin();
        count += high - low;
    }

    cout << count;
    return 0;
}*/
