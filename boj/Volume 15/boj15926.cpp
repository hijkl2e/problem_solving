#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A(N, -1);
	int cnt{}, ans{};
	for (int i = 0; i < N; ++i) {
		if (S[i] == '(') {
			if (A[cnt] == -1) {
				A[cnt] = i;
			}
			++cnt;
		} else {
			A[cnt] = -1;
			cnt = max(cnt - 1, 0);
			if (A[cnt] != -1) {
				ans = max(ans, i - A[cnt] + 1);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
