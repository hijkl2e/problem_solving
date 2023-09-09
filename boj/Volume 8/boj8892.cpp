#include <bits/stdc++.h>

using namespace std;

bool solve(string S) {
	string T = S;
	reverse(T.begin(), T.end());
	return S == T;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		string ans = "0";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j) {
					continue;
				}
				if (solve(A[i] + A[j])) {
					ans = A[i] + A[j];
					i = N;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
