#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int maxi{};
		double maxv{};
		for (int i = 1; i <= N; ++i) {
			int a{}, b{}, c{};
			cin >> a >> b >> c;
			double val = b * b / (4.0 * a) + c;
			if (maxv < val) {
				maxi = i;
				maxv = val;
			}
		}
		cout << maxi << "\n";
	}
	return 0;
}
