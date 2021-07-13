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

int T, N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    rep(Case, T) {
        cin >> N;

        if (N == 1) {
            cout << "Case #" << Case + 1 << "\n";
            cout << 2 << "\n";
            continue;
        }
        if (N == 2) {
            cout << "Case #" << Case + 1 << "\n";
            cout << 3 << "\n";
            continue;
        }
        
        int ans = 0;
        for (int i = 2; i <= sqrt(N) * 410; i++) {
            int ttmp = N;

            int tmp = ttmp % i; ttmp /= i;
            while (ttmp) {
                if (ans == 0 && tmp != ttmp % i)
                    break;
                if (ttmp < i && ttmp == tmp)
                    ans = i;

                ttmp /= i;
            }
            if (ans != 0)
                break;
        }

        cout << "Case #" << Case + 1 << "\n";
        if (ans != 0)
            cout << ans << "\n";
        else
            cout << N - 1 << "\n";
    }
}
