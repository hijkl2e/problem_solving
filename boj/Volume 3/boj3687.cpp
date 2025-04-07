#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

string solve1(int N) {
	static vector<ii> A{
		{0, 6}, {1, 2}, {2, 5}, {4, 4}, {6, 6}, {7, 3}, {8, 7}
	};
	string ret((N - 1) / 7 + 1, 'x');
	for (int i = 0, j = ret.size() - 1; i < ret.size(); ++i, --j) {
		for (auto &[u, v] : A) {
			if (i == 0 && u == 0) {
				continue;
			}
			if (2 * j <= N - v && N - v <= 7 * j) {
				ret[i] = u + '0';
				N -= v;
				break;
			}
		}
	}
	return ret;
}

string solve2(int N) {
	return (N % 2 ? "7" : "1") + string(N / 2 - 1, '1');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << solve1(N) << " " << solve2(N) << "\n";
	}
	return 0;
}
