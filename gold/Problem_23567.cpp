#include <iostream>
using namespace std;

bool isRainbow(int arr[], int k) {
    for(int i = 1; i <= k; i++) {
        if(!arr[i])
            return false;
    }

    return true;
}

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
        for(int i = start; i < end; i++) {
            PPrimeCount[P[i]]++;
            PCount[P[i]]--;
        }

        int result = 100000001;
        while (start < n / 2) {
            for(int i = end; i < n && (end - start) + 1 <= n / 2; i++) {
                if (!(isRainbow(PPrimeCount, k) && isRainbow(PCount, k))) {
                    end++;
                    PPrimeCount[P[end]]++;
                    PCount[P[end]]--;
                    continue;
                }

                else {
                    if (result > end - start)
                        result = end - start + 1;

                    break;
                }
            }

            PPrimeCount[P[start]]--;
            PCount[P[start]]++;
            start++;
            while(end != k + start - 1) {
                PPrimeCount[P[end]]--;
                PCount[P[end]]++;
                end--;
            }
        }

        if(result != 100000001)
            printf("%d", result);

        else
            printf("0");
    }

    else
        printf("0");
}