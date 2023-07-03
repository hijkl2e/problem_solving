#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ii>> A(13);
	for (int i = 1; i < 13; ++i) {
		for (int j = 1; j < i - j; ++j) {
			A[i].push_back({j, i - j});
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << "Pairs for " << N << ":";
		for (int i = 0; i < A[N].size(); ++i) {
			auto &[x, y] = A[N][i];
			cout << (i ? ", " : " ") << x << " " << y;
		}
		cout << "\n";
	}
	return 0;
}
