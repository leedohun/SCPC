#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

int T;
string S;

bool IsMatch(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '{' && b == '}') return true;
    if (a == '[' && b == ']') return true;
    return false;
}

void solved() {
	int answer = 0;

	stack<int> st;

	int start_ind = -1;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(' || S[i] == '[' || S[i] == '{') {
			st.push(i);

			if (start_ind == -1)
				start_ind = i;
		}
		else {
			if (!st.empty() && IsMatch(S[st.top()], S[i])) {
				st.pop();
				if (st.empty())
					answer = max(answer, i - start_ind + 1);
				else
					answer = max(answer, i - st.top());
			}
			else {
				st = stack<int>();
				start_ind = -1;
			}
		}
	}
	cout << answer << "\n";
}

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(i, T) {
        cin >> S;

        cout << "Case #" << i + 1 << "\n";
        solved();
    }
}
