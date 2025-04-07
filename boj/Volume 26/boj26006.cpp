#include <bits/stdc++.h>

using namespace std;

const int dx[9]{0, -1, -1, -1, 0, 1, 1, 1, 0};
const int dy[9]{0, -1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int x{}, y{};
	cin >> x >> y;
	set<int> R, C, D1, D2;
	while (K--) {
		int r{}, c{};
		cin >> r >> c;
		R.insert(r);
		C.insert(c);
		D1.insert(r + c);
		D2.insert(r - c);
	}
	vector<int> A(9);
	for (int i = 0; i < 9; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == 0 || nx == N + 1 || ny == 0 || ny == N + 1
				|| R.count(nx) || C.count(ny) || D1.count(nx + ny) || D2.count(nx - ny)) {
			A[i] = 1;
		}
	}
	string ans;
	int cnt = accumulate(A.begin(), A.end(), 0);
	if (A[0] == 1 && cnt < 9) {
		ans = "CHECK";
	} else if (cnt == 9) {
		ans = "CHECKMATE";
	} else if (A[0] == 0 && cnt == 8) {
		ans = "STALEMATE";
	} else {
		ans = "NONE";
	}
	cout << ans << "\n";
	return 0;
}
