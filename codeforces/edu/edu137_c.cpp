#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		string S;
		getline(cin, S);
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0, j = -1; i < N; ++i) {
			if (S[i] == '0') {
				j = i;
			} else if (j >= 0 && A[i] < A[j]) {
				swap(S[i], S[j]);
				j = i;
			}
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			if (S[i] == '1') {
				ans += A[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
