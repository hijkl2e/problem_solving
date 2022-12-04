#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 0; cin >> N, N; ++tc) {
		if (tc) {
			cout << "\n";
		}
		vector<double> x1(N);
		vector<double> y1(N);
		vector<double> x2(N);
		vector<double> y2(N);
		vector<string> type(N);
		for (int i = 0; i < N; ++i) {
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> type[i];
		}
		int M{};
		cin >> M;
		while (M--) {
			double x{}, y{};
			string t;
			cin >> x >> y >> t;
			string ans = "floor";
			for (int i = 0; i < N; ++i) {
				if (x1[i] - EPS <= x && x <= x2[i] + EPS
						&& y1[i] - EPS <= y && y <= y2[i] + EPS) {
					ans = t == type[i] ? "correct" : type[i];
					break;
				}
			}
			cout << t << " " << ans << "\n";
		}
	}
	return 0;
}
