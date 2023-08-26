#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		if (x == 1) {
			A.push_back(i);
		}
	}
	int ans = INF;
	for (int i = K - 1; i < A.size(); ++i) {
		ans = min(ans, A[i] - A[i - K + 1] + 1);
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
