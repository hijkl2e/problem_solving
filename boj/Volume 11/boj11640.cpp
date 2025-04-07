#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int R{}, P{}, D{};
		cin >> R >> P >> D;
		vector<string> name(R);
		vector<double> pct(R);
		double main_wgt{};
		for (int i = 0; i < R; ++i) {
			double x{};
			cin >> name[i] >> x >> pct[i];
			if (pct[i] == 100) {
				main_wgt = x;
			}
		}
		cout << "Recipe # " << tc << "\n";
		cout << fixed << setprecision(1);
		for (int i = 0; i < R; ++i) {
			double x = main_wgt * pct[i] / 100 * D / P;
			cout << name[i] << " " << x << "\n";
		}
		cout << string(40, '-') << "\n";
	}
	return 0;
}
