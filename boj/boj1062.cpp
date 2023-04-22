#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	if (K < 5) {
		cout << "0\n";
		return 0;
	}
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (auto &s : A) {
		s = s.substr(4, s.size() - 8);
		auto it = s.begin();
		while (it != s.end()) {
			if (*it == 'a' || *it == 'c' || *it == 'i' || *it == 'n' || *it == 't') {
				it = s.erase(it);
			} else {
				++it;
			}
		}
	}
	deque<bool> B(26);
	for (auto &s : A) {
		for (char c : s) {
			B[c - 'a'] = true;
		}
	}
	vector<int> C(26);
	for (int i = 1; i < 26; ++i) {
		C[i] = C[i - 1] + B[i];
	}
	for (auto &s : A) {
		for (auto &c : s) {
			c = C[c - 'a'] + 'a' - 1;
		}
	}
	K = min(K - 5, C[25]);
	int ans{};
	for (int i = 0; i < (1 << C[25]); ++i) {
		if (__builtin_popcount(i) != K) {
			continue;
		}
		int cnt{};
		for (auto &s : A) {
			bool flag = true;
			for (char c : s) {
				if ((i & (1 << (c - 'a'))) == 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				++cnt;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
