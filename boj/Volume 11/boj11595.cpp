#include <bits/stdc++.h>

using namespace std;

using is = pair<__int128, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<is> A(N);
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		A[i].second = s.substr(0, s.size() - 1);
		getline(cin, s);
		reverse(s.begin(), s.end());
		istringstream iss(s);
		iss >> s;
		for (int j = 0; j < 50; ++j) {
			int x = 1;
			if (iss >> s) {
				reverse(s.begin(), s.end());
				x = s == "upper" ? 0 : s == "middle" ? 1 : 2;
			}
			A[i].first = 3 * A[i].first + x;
		}
	}
	sort(A.begin(), A.end());
	for (auto &p : A) {
		cout << p.second << "\n";
	}
	return 0;
}
