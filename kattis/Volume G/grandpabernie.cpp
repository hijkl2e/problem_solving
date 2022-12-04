#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, vector<int>> A;
	while (N--) {
		string s;
		int y{};
		cin >> s >> y;
		A[s].push_back(y);
	}
	for (auto &[s, v] : A) {
		sort(v.begin(), v.end());
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		string s;
		int k{};
		cin >> s >> k;
		cout << A[s][k - 1] << "\n";
	}
	return 0;
}
