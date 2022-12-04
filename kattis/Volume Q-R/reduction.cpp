#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{}, M{}, L{};
		cin >> N >> M >> L;
		cin.ignore();
		vector<is> C(L);
		for (int i = 0; i < L; ++i) {
			string s;
			getline(cin, s);
			istringstream iss(s);
			getline(iss, C[i].second, ':');
			getline(iss, s, ',');
			int A = stoi(s);
			getline(iss, s);
			int B = stoi(s);
			auto &ans = C[i].first;
			for (int j = N; j > M;) {
				if (j / 2 >= M) {
					ans += min(B, (j - j / 2) * A);
					j /= 2;
				} else {
					ans += A;
					--j;
				}
			}
		}
		sort(C.begin(), C.end());
		cout << "Case " << tc << "\n";
		for (auto &p : C) {
			cout << p.second << " " << p.first << "\n";
		}
	}
	return 0;
}
