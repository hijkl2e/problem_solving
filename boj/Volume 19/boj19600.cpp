#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> B(5001);
vector<vector<int>> T(5001);

int binary_search(int l, int r, int val) {
	int mid = (l + r) / 2;
	if (mid == val) {
		return 0;
	} else if (val < mid) {
		return B[mid - l][val - l + 1] + 1;
	} else {
		return B[r - mid][val - mid] + 1;
	}
}

int ternary_search(int l, int r, int val) {
	int lt = l + (r - l) / 3;
	int rt = r - (r - l) / 3;
	if (lt == val) {
		return 0;
	} else if (rt == val) {
		return 1;
	} else if (val < lt) {
		return T[lt - l][val - l + 1] + 2;
	} else if (val < rt) {
		return T[rt - lt - 1][val - lt] + 2;
	} else {
		return T[r - rt][val - rt] + 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1; i < B.size(); ++i) {
		B[i].resize(i + 1);
		for (int j = 1; j <= i; ++j) {
			B[i][j] = binary_search(1, i, j);
		}
	}
	for (int i = 1; i < T.size(); ++i) {
		T[i].resize(i + 1);
		for (int j = 1; j <= i; ++j) {
			T[i][j] = ternary_search(1, i, j);
		}
	}
	for (int i = 1; i < T.size(); ++i) {
		for (int j = 1; j <= i; ++j) {
			T[i][j] += T[i][j - 1] - B[i][j];
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int n{}, s{}, e{};
		cin >> n >> s >> e;
		int ans = T[n][e + 1] - T[n][s];
		cout << ans << "\n";
	}
	return 0;
}
