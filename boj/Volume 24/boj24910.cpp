#include <bits/stdc++.h>

using namespace std;

using ll = __int128;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(11);
	vector<map<ll, vector<int>>> B(11);
	while (K--) {
		for (int i = 0; i < 11; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < 11; ++i) {
			ll x{};
			for (int j = 0; j < 11; ++j) {
				if (i == j) {
					continue;
				}
				x = N * x + (A[j] - 1);
			}
			B[i][x].push_back(A[i]);
		}
	}
	for (int i = 0; i < 11; ++i) {
		ll ans = 1;
		for (int j = 0; j < 10; ++j) {
			ans *= N;
		}
		ans -= B[i].size();
		for (auto &[u, v] : B[i]) {
			sort(v.begin(), v.end());
			if (v.front() > 2) {
				++ans;
			}
			if (v.back() < N - 1) {
				++ans;
			}
			for (int j = 0; j < v.size() - 1; ++j) {
				if (v[j] + 2 < v[j + 1]) {
					++ans;
				}
			}
		}
		if (N == 1 || ans == 0) {
			cout << "0\n";
			continue;
		}
		string s;
		while (ans) {
			s += to_string(static_cast<int>(ans % 10));
			ans /= 10;
		}
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
	return 0;
}
