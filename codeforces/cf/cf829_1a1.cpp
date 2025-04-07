#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		if (N % 2) {
			cout << "-1\n";
			continue;
		}
		vector<ii> B;
		for (int i = 1; i <= N; i += 2) {
			if (A[i] == A[i + 1]) {
				B.push_back({i, i + 1});
			} else {
				B.push_back({i, i});
				B.push_back({i + 1, i + 1});
			}
		}
		cout << B.size() << "\n";
		for (auto &p : B) {
			cout << p.first << " " << p.second << "\n";
		}
	}
	return 0;
}
