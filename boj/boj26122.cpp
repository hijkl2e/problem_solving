#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A;
	int cnt = 1;
	for (int i = 1; i < S.size(); ++i) {
		if (S[i] == S[i - 1]) {
			++cnt;
		} else {
			A.push_back(cnt);
			cnt = 1;
		}
	}
	A.push_back(cnt);
	int ans{};
	for (int i = 1; i < A.size(); ++i) {
		ans = max(ans, 2 * min(A[i - 1], A[i]));
	}
	cout << ans << "\n";
	return 0;
}
