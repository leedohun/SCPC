#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

int N, K;

unsigned long long bfs(unsigned long long F, int cnt, bool flag) {
    if (cnt == K)
        return F;

    unsigned long long ret = bfs(F * 2, cnt + 1, flag);

    if (F - 1 >= 6 && ((F - 1) / 3) % 2 == 1 && (F - 1) % 3 == 0) {
        if (flag)
            ret = min(ret, bfs((F - 1) / 3, cnt + 1, flag));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    rep(i, N) {
        cin >> K;

        cout << "Case #" << i + 1 << "\n";
        cout << bfs(1, 0, true) << " " << bfs(1, 0, false) << "\n";
    }
}
