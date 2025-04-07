#include <bits/stdc++.h>

using namespace std;

bool solve(int s, int e, int x) {
	return s < x && x < e;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<vector<int>> A(26);
	for (int i = 0; i < S.size(); ++i) {
		int x = S[i] - 'A';
		A[x].push_back(i);
	}
	int ans{};
	for (int i = 0; i < 26; ++i) {
		for (int j = i + 1; j < 26; ++j) {
			if (solve(A[i][0], A[i][1], A[j][0]) ^ solve(A[i][0], A[i][1], A[j][1])) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
