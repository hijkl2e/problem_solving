#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using is = pair<int, string>;

const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

ii solve(vector<string> &A) {
	int x{}, y{}, dir{};
	for (auto &s : A) {
		if (s == "Left") {
			dir = (dir + 3) % 4;
		} else if (s == "Right") {
			dir = (dir + 1) % 4;
		} else {
			x += dx[dir];
			y += dy[dir];
		}
	}
	return {x, y};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{}, N{};
	cin >> x >> y >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	is ans;
	vector<string> B(A.begin(), A.end());
	for (int i = 0; i < B.size() && !ans.first; ++i) {
		for (auto &s : {"Left", "Forward", "Right"}) {
			B[i] = s;
			if (solve(B) == make_pair(x, y)) {
				ans = {i + 1, s};
				break;
			}
		}
		B[i] = A[i];
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
