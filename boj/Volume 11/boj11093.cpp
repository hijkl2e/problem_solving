#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int K = 1 + sqrt(S.size() - 1) + EPS;
		for (int i = 0; i < K; ++i) {
			for (int j = K * (K - 1); j >= 0; j -= K) {
				if (i + j < S.size()) {
					cout << S[i + j];
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
