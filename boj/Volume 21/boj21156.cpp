#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i + 1;
	}
	while (M--) {
		char c{};
		int x{}, y{};
		cin >> c >> x >> c >> y;
		int xidx = find(A.begin(), A.end(), x) - A.begin();
		int yidx = find(A.begin(), A.end(), y) - A.begin();
		if (xidx > yidx) {
			rotate(A.begin() + yidx, A.begin() + yidx + 1, A.begin() + xidx + 1);
		}
	}
	for (int i = 0; i < A.size(); ++i) {
		cout << "T" << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
