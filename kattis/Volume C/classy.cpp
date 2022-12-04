#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<is> A(N);
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			A[i].second = s.substr(0, s.size() - 1);
			cin >> s;
			reverse(s.begin(), s.end());
			istringstream iss(s);
			for (int j = 0; j < 10; ++j) {
				int x = 1;
				if (getline(iss, s, '-')) {
					reverse(s.begin(), s.end());
					x = s == "upper" ? 0 : s == "middle" ? 1 : 2;
				}
				A[i].first = 4 * A[i].first + x;
			}
			cin >> s;
		}
		sort(A.begin(), A.end());
		for (auto &p : A) {
			cout << p.second << "\n";
		}
		cout << string(30, '=') << "\n";
	}
	return 0;
}
