#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <bitset>
#include <queue>
#include <map>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

int T, M;

ll gcd(ll x, ll y) {
    if (x < y)
        swap(x, y);

    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(Case, T) {
        cin >> M;

        vector <ll> b(M);
        rep(i, M) cin >> b[i];

        int zero_cnt = 0;
        vector <ll> tmp;
        for (int i = 0; i < M - 1; i++) {
            tmp.push_back(b[i + 1] - b[i]);

            if (tmp[i] == 0)
                zero_cnt++;
        }

        cout << "Case #" << Case + 1 << "\n";

        if (zero_cnt == M - 1)
            cout << 1 << "\n";
        else if (zero_cnt != 0)
            cout << 0 << "\n";
        else {
            ll ttmp = tmp[0];
            for (int i = 1; i < M - 1; i++) {
                ttmp = gcd(ttmp, tmp[i]);
            }

            int cnt = 0;
            for (ll i = 1; i <= ttmp; i++) {
                if (ttmp % i == 0)
                    cnt++;
            }

            cout << cnt << "\n";
        }
    }
}
