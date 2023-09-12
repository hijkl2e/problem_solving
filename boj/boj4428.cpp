#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(101);
	vector<int> B(101);
	vector<vector<int>> C(101, vector<int>(10));
	deque<bool> D(101);
	int c{}, p{}, t{};
	char l{};
	while (cin >> c >> p >> t >> l) {
		D[c] = true;
		if (l == 'R' || l == 'U' || l == 'E' || C[c][p] == -1) {
			continue;
		}
		if (l == 'C') {
			++A[c];
			B[c] += t + C[c][p];
			C[c][p] = -1;
		} else {
			C[c][p] += 20;
		}
	}
	vector<iii> E;
	for (int i = 1; i < 101; ++i) {
		if (D[i]) {
			E.push_back({-A[i], B[i], i});
		}
	}
	sort(E.begin(), E.end());
	for (auto &[a, b, c] : E) {
		cout << c << " " << -a << " " << b << "\n";
	}
	return 0;
}
