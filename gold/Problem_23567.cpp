#include <iostream>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int P[n + 1];
    int PCount[k + 1];
    fill_n(PCount, k + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
        PCount[P[i]]++;
    }


    if(n / 2 >= k) {
        int start = 1;
        int end = k;
        int PPrimeCount[k + 1];
        fill_n(PPrimeCount, k + 1, 0);
        for(int i = start; i <= end; i++) {
            PPrimeCount[P[i]]++;
        }

        int result = 100000001;
        bool right = true;
        while (end - start + 1 <= n / 2) {
            bool next = false;
            for(int j = 1; j <= k; j++) {
                if(PPrimeCount[j] == 0 || PPrimeCount[j] == PCount[j]) {
                    next = true;
                    break;
                }
            }

            if(next) {
                if(end == n && start == 1) {
                    break;
                }

                if(right) {
                    if(end != n) {
                        end++;
                        PPrimeCount[P[end]]++;
                        PPrimeCount[P[start]]--;
                        start++;
                    }

                    else {
                        right = false;
                        start--;
                        PPrimeCount[P[start]]++;
                    }
                }

                else {
                    if(start != 1) {
                        start--;
                        PPrimeCount[P[start]]++;
                        PPrimeCount[P[end]]--;
                        end--;
                    }

                    else {
                        right = true;
                        end++;
                        PPrimeCount[P[end]]++;
                    }
                }
            }

            else {
                result = end - start + 1;
                break;
            }
        }

        if(result != 100000001)
            printf("%d", result);

        else
            printf("0");
    }

    else
        printf("0");

    return 0;
}