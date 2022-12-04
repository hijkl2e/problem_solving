#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<unordered_set<string>> A(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			string s;
			cin >> s;
			A[i].insert(s);
		}
	}
	vector<string> B;
	for (auto &s : A[0]) {
		bool yes = true;
		for (int i = 0; i < N; ++i) {
			if (A[i].find(s) == A[i].end()) {
				yes = false;
				break;
			}
		}
		if (yes) {
			B.push_back(s);
		}
	}
	sort(B.begin(), B.end());
	cout << B.size() << "\n";
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
