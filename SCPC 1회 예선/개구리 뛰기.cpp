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

int T, N, K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    for(int Case = 1; Case <= T; Case++) {
        cin >> N;

        vector <int> v; v.push_back(0);
        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            v.push_back(tmp);
        }
        cin >> K;

        bool check = true;
        int tmp = 0, ans = 0;
        
        for (int i = 1; i <= N; i++) {
            if (!check)
                break;

            if (v[i] <= tmp + K) {
                continue;
            }
            else {
                if (tmp == v[i - 1])
                    check = false;
                else {
                    tmp = v[i - 1];
                    ans++; i--;
                }
            }
        }
        cout << "Case #" << Case << "\n";
        if (check)
            cout << ans + 1 << "\n";
        else
            cout << -1 << "\n";
    }
}
