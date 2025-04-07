#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	cin.ignore();
	vector<string> A(M);
	vector<deque<bool>> G(26, deque<bool>(26));
	for (int i = 0; i < M; ++i) {
		getline(cin, A[i]);
	}
	for (auto &s : A) {
		G[s.front() - 'a'][s.back() - 'a'] = true;
	}
	vector<int> B(26, -1);
	for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i) {
			if (B[i] != -1) {
				continue;
			}
			int cnt1{}, cnt2{};
			bool flag{};
			for (int j = 0; j < 26; ++j) {
				if (G[i][j]) {
					++cnt1;
					if (B[j] == 1) {
						++cnt2;
					} else if (B[j] == 0) {
						flag = true;
					}
				}
			}
			B[i] = flag ? 1 : cnt1 == cnt2 ? 0 : -1;
		}
	}
	vector<string> C;
	for (auto &s : A) {
		if (B[s.back() - 'a'] == 0) {
			C.push_back(s);
		}
	}
	sort(C.begin(), C.end());
	cout << C.size() << "\n";
	for (auto &s : C) {
		cout << s << "\n";
	}
	return 0;
}
