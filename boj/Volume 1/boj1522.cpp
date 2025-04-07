#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int cnt = count(S.begin(), S.end(), 'a');
	S = "#" + S + S;
	vector<int> A(S.size());
	for (int i = 1; i < S.size(); ++i) {
		A[i] = A[i - 1] + (S[i] == 'b');
	}
	int ans = 1e9;
	for (int i = cnt; i < S.size(); ++i) {
		ans = min(ans, A[i] - A[i - cnt]);
	}
	cout << ans << "\n";
	return 0;
}
