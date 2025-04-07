#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int mktime(int Y, int M, int D, int h, int m) {
	int d = (Y - 2013) * 365 + (M - 1) * 30 + (D - 1);
	if (M > 2) {
		--d;
		if (Y % 4) {
			--d;
		}
	}
	while (--M) {
		if ((M > 7) ^ (M % 2)) {
			++d;
		}
	}
	return (d * 24 + h) * 60 + m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int B{}, C{};
		cin >> B >> C;
		vector<ii> A;
		A.reserve(2 * B);
		for (int i = 0; i < B; ++i) {
			string s;
			int Y{}, M{}, D{}, h{}, m{};
			char c{};
			cin >> s >> Y >> c >> M >> c >> D >> h >> c >> m;
			A.push_back({mktime(Y, M, D, h, m), 1});
			cin >> Y >> c >> M >> c >> D >> h >> c >> m;
			A.push_back({mktime(Y, M, D, h, m + C), -1});
		}
		sort(A.begin(), A.end());
		int sum{}, ans{};
		for (auto &p : A) {
			sum += p.second;
			ans = max(ans, sum);
		}
		cout << ans << "\n";
	}
	return 0;
}
