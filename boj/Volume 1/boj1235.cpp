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
	int ans = A[0].size();
	while (true) {
		for (int i = 0; i < N; ++i) {
			A[i].erase(A[i].begin());
		}
		sort(A.begin(), A.end());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		if (A.size() < N) {
			break;
		}
		--ans;
	}
	cout << ans << "\n";
	return 0;
}
