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
		cin.ignore();
		string A, B;
		getline(cin, A);
		getline(cin, B);
		vector<ii> ans;
		for (int i = 0; i < N; ++i) {
			if (B[i] == '1') {
				A[i] ^= 1;
				ans.push_back({i + 1, i + 1});
			}
		}
		if (ans.size() % 2) {
			ans.push_back({1, 1});
			ans.push_back({2, N});
			ans.push_back({1, N});
		}
		int cnt = count(A.begin(), A.end(), '0');
		if (cnt % N) {
			cout << "NO\n";
			continue;
		}
		if (cnt == 0) {
			ans.push_back({1, N});
		}
		cout << "YES\n";
		cout << ans.size() << "\n";
		for (auto &p : ans) {
			cout << p.first << " " << p.second << "\n";
		}
	}
	return 0;
}
