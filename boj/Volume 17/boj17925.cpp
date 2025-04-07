#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	map<string, vector<int>> B;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		int W{};
		cin >> W;
		while (W--) {
			string s;
			cin >> s;
			B[s].push_back(i);
		}
	}
	vector<int> C(N);
	string s;
	while (cin >> s) {
		auto it = B.find(s);
		if (it == B.end()) {
			continue;
		}
		for (int x : it->second) {
			++C[x];
		}
	}
	int maxv = *max_element(C.begin(), C.end());
	vector<string> D;
	for (int i = 0; i < N; ++i) {
		if (C[i] == maxv) {
			D.push_back(A[i]);
		}
	}
	sort(D.begin(), D.end());
	for (auto &s : D) {
		cout << s << "\n";
	}
	return 0;
}
