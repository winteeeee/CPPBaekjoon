#include <iostream>
using namespace std;

int main() {
    int n, k;
    scanf("%d, %d", &n, &k);

    int P[n];
    int count[k + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
        count[P[i]]++;
    }

    int start = 0;
    int end = k;

    while(end < n) {

    }
}

/*
 * 처음 크기를 k로 잡고 모든 색이 있는지 확인
 * 없으면 end를 늘림 있으면 start를 줄이고 모든 색이 있는지 확인
 * 있으면 start를 줄임(최소 크기까지) 없으면 end를 늘림
 * 이걸 끝까지 반복하여 최소 크기를 출력
 */
