#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i] >> C[i];
	}
	int ans = INF;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < C[i]; ++j) {
			if (T <= A[i] + j * B[i]) {
				ans = min(ans, A[i] + j * B[i]);
				break;
			}
		}
	}
	ans = ans == INF ? -1 : (ans - T);
	cout << ans << "\n";
	return 0;
}
