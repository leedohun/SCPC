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

bool mir[1005][1005] = { false, };

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int T, N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    rep(Case, T) {
        string room[1005];

        cin >> N;

        for (int i = 0; i < N; i++ ) {
            for (int j = 0; j < N; j++) {
                mir[i][j] = false;
            }
        }
        

        rep(i, N) {
            cin >> room[i];
        }

        int y = 0, x = -1, dir = 1;
        while (1) {
            if (y + dy[dir] < 0 || x + dx[dir] < 0 || N <= y + dy[dir] || N <= x + dx[dir]) break;

            y += dy[dir];
            x += dx[dir];

            if (room[y][x] == '0')
                continue;
            else if (room[y][x] == '1') {
                mir[y][x] = true;

                if (dir == 0)
                    dir = 1;
                else if (dir == 1)
                    dir = 0;
                else if (dir == 2)
                    dir = 3;
                else if (dir == 3)
                    dir = 2;
            }
            else if (room[y][x] == '2') {
                mir[y][x] = true;

                if (dir == 0)
                    dir = 3;
                else if (dir == 1)
                    dir = 2;
                else if (dir == 2)
                    dir = 1;
                else if (dir == 3)
                    dir = 0;
            }
        }

        int ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mir[i][j])
                    ret++;
            }
        }

        cout << "Case #" << Case + 1 << "\n";
        cout << ret << "\n";
    }
}

/*시뮬레이션*/
