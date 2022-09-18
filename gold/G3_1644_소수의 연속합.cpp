#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    bool prime[n + 1];
    for(int i = 0; i <= n; i++)
        prime[i] = true;

    for(int i = 2; i <= n / 2; i++) {
        for(int j = 2; i * j <= n; j++) {
            prime[i * j] = false;
        }
    }

    int count = 0;
    int start = 1;
    int end = 2;
    int sum = prime[start] + prime[end];
    while(end <= n || start < end) {
        if(prime[start] + prime[end] < n) {
            sum += prime[++end];
        }

        else if(prime[start] + prime[end] > n) {
            sum -= prime[start++];
        }

        else {
            sum -= prime[start++];
            count++;
        }
    }

    cout << count;
    return 0;
}