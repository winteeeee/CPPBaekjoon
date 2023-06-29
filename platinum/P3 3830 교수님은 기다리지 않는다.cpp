/*
#include <iostream>
using namespace std;

int n, m;
int arr[100001];
long long weight[100001];
//weight[a] -> a와 a의 부모를 잇는 간선의 가중치

int parentFind(int a) {
    if (arr[a] == a) {
        return a;
    }

    int parent = parentFind(arr[a]);
    weight[a] += weight[arr[a]];
    //경로 압축으로 나의 부모를 생략할테니 부모만큼의 가중치 갱신
    return arr[a] = parent;
}

void setUnion(int a, int b, int w) {
    int aParent = parentFind(a);
    int bParent = parentFind(b);

    if (aParent != bParent) {
        arr[bParent] = aParent;
        weight[bParent] = -weight[b] + w + weight[a];
        //두 집합이 합쳐지면 b의 부모의 상대 무게가 갱신됨
        //-weight[b](b와의 간선을 타서 b와 같은 무게가 되고)
        //+w (a와 b 사이의 간선을 타서 a와 같은 무게가 된 다음)
        //+weight[a] (a와 a 부모의 간선을 타서 결론적으로 b 부모가 a 부모와의 상대 무게를 나타내도록 함
    }
}

void query(int a, int b) {
    if (parentFind(a) != parentFind(b)) {
        cout << "UNKNOWN" << '\n';
    } else {
        cout << weight[b] - weight[a] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char determination;
    int a, b, c;
    n = 1;
    do {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            arr[i] = i;
            weight[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            cin >> determination;

            if (determination == '!') {
                cin >> a >> b >> c;
                setUnion(a, b, c);
            } else {
                cin >> a >> b;
                query(a, b);
            }
        }
    } while (n != 0 && m != 0);

    return 0;
}*/
