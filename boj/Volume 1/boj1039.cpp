#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string N;
	int K{};
	cin >> N >> K;
	vector<vector<string>> A(2);
	A[1].push_back(N);
	while (K--) {
		swap(A[0], A[1]);
		A[1].clear();
		for (auto &s : A[0]) {
			for (int i = 0; i < s.size(); ++i) {
				for (int j = i + 1; j < s.size(); ++j) {
					if (i == 0 && s[j] == '0') {
						continue;
					}
					swap(s[i], s[j]);
					A[1].push_back(s);
					swap(s[i], s[j]);
				}
			}
		}
		sort(A[1].begin(), A[1].end());
		A[1].resize(unique(A[1].begin(), A[1].end()) - A[1].begin());
	}
	cout << (A[1].size() ? stoi(A[1].back()) : -1) << "\n";
	return 0;
}
