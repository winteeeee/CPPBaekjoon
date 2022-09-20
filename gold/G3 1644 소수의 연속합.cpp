/*
#include <iostream>
#include <vector>
using namespace std;

bool prime[40000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if(n == 2)
        cout << 1;

    else {
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int i = 2; i <= n; i++) {
            for (int j = 2; i * j <= n; j++) {
                prime[i * j] = false;
            }
        }

        vector<int> primes;
        for (int i = 1; i <= n; i++) {
            if (prime[i])
                primes.push_back(i);
        }

        int count = 0;
        for (int i = 2; i < primes.size(); i++) {
            if (primes[i] == n)
                count++;

            else {
                int prefixSum = primes[i] + primes[i - 1];
                for (int j = i - 1; j >= 1;) {
                    if (prefixSum < n) {
                        prefixSum += primes[--j];
                    } else if (prefixSum > n) {
                        break;
                    } else {
                        count++;
                        break;
                    }
                }
            }
        }

        cout << count;
    }
    return 0;
}*/
