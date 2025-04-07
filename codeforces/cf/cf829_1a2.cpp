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
		int cnt{};
		for (int i = 1; i <= N; ++i) {
			if (A[i]) {
				++cnt;
			}
		}
		if (cnt % 2) {
			cout << "-1\n";
			continue;
		}
		vector<ii> B;
		for (int i = 1; i <= N; ++i) {
			if (A[i] == 0) {
				B.push_back({i, i});
				continue;
			}
			int j = i + 1;
			while (A[j] == 0) {
				++j;
			}
			if ((A[i] == A[j]) ^ ((j - i) % 2)) {
				B.push_back({i, i});
				B.push_back({i + 1, j});
			} else {
				B.push_back({i, j});
			}
			i = j;
		}
		cout << B.size() << "\n";
		for (auto &p : B) {
			cout << p.first << " " << p.second << "\n";
		}
	}
	return 0;
}
