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
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> B(101);
		for (int i = 0; i < N; ++i) {
			++B[A[i]];
		}
		bool yes = true;
		for (int i = 1; i < B.size(); ++i) {
			if (B[i - 1] < B[i]) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
