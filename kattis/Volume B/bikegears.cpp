#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using rec = tuple<ld, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int F{}, B{};
	cin >> F >> B;
	vector<int> fs(F);
	vector<int> bs(B);
	for (int i = 0; i < F; ++i) {
		cin >> fs[i];
	}
	for (int i = 0; i < B; ++i) {
		cin >> bs[i];
	}
	vector<rec> S;
	for (int i = 0; i < F; ++i) {
		for (int j = 0; j < B; ++j) {
			S.push_back({fs[i] * 1.0L / bs[j], fs[i], bs[j]});
		}
	}
	sort(S.begin(), S.end());
	for (auto &[r, f, b] : S) {
		cout << "(" << f << "," << b << ")\n";
	}
	return 0;
}
