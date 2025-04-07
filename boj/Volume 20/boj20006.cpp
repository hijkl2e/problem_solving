#include <bits/stdc++.h>

using namespace std;

using si = pair<string, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int P{}, M{};
	cin >> P >> M;
	vector<vector<si>> A;
	while (P--) {
		int L{};
		string N;
		cin >> L >> N;
		bool flag = false;
		for (auto &v : A) {
			if (v.size() < M && v[0].second - 10 <= L && L <= v[0].second + 10) {
				v.push_back({N, L});
				flag = true;
				break;
			}
		}
		if (!flag) {
			A.push_back({{N, L}});
		}
	}
	for (auto &v : A) {
		cout << (v.size() == M ? "Started!" : "Waiting!") << "\n";
		sort(v.begin(), v.end());
		for (auto &p : v) {
			cout << p.second << " " << p.first << "\n";
		}
	}
	return 0;
}
