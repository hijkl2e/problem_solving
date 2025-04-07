#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	string ans = A[0];
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 1; j < N; ++j) {
			if (ans[i] != A[j][i]) {
				ans[i] = '?';
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
