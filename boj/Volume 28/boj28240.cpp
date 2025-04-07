#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i];
		--A[i];
	}
	for (int i = 0; i < N; ++i) {
		int y = i == A[0] || i == A[1] ? 1 : i == A[2] || i == A[3] ? -1 : 0;
		if (i == N - 1) {
			y = y == -1 ? -INF : INF;
		}
		cout << i << " " << y << "\n";
	}
	return 0;
}
