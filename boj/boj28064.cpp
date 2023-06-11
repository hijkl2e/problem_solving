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
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			bool yes{};
			for (int k = 0; k < A[i].size() && k < A[j].size(); ++k) {
				if (A[i].substr(0, k + 1) == A[j].substr(A[j].size() - k - 1)
						|| A[j].substr(0, k + 1) == A[i].substr(A[i].size() - k - 1)) {
					yes = true;
					break;
				}
			}
			if (yes) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
