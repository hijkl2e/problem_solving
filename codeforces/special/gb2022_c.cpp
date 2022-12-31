#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> P{
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
	};
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		bool yes = true;
		for (int i = 1; i < N; ++i) {
			if (A[i] == A[i - 1]) {
				yes = false;
				break;
			}
		}
		vector<int> B(47);
		for (int p : P) {
			fill(B.begin(), B.end(), 0);
			for (int i = 0; i < N; ++i) {
				++B[A[i] % p];
			}
			if (*min_element(B.begin(), B.begin() + p) > 1) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
