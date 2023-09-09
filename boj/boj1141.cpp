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
	sort(A.begin(), A.end());
	int ans = 1;
	for (int i = 0; i < N - 1; ++i) {
		if (A[i].size() > A[i + 1].size() || A[i] != A[i + 1].substr(0, A[i].size())) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
