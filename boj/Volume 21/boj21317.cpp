#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 1; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	int K{};
	cin >> K;
	vector<int> dp1(N + 3, INF);
	vector<int> dp2(N + 3, INF);
	dp1[1] = 0;
	for (int i = 1; i < N; ++i) {
		dp1[i + 1] = min(dp1[i + 1], dp1[i] + A[i]);
		dp2[i + 1] = min(dp2[i + 1], dp2[i] + A[i]);
		dp1[i + 2] = min(dp1[i + 2], dp1[i] + B[i]);
		dp2[i + 2] = min(dp2[i + 2], dp2[i] + B[i]);
		dp2[i + 3] = min(dp2[i + 3], dp1[i] + K);
	}
	cout << min(dp1[N], dp2[N]) << "\n";
	return 0;
}
