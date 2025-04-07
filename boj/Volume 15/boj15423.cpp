#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp1(A[N - 2] + A[N - 1], INF);
	vector<int> dp2(A[N - 2] + A[N - 1], INF);
	dp1[0] = dp2[0] = 0;
	for (int i = 1, j = 0; i < dp1.size(); ++i) {
		if (j + 1 < N && i == A[j + 1]) {
			++j;
		}
		dp1[i] = dp1[i - A[j]] + 1;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = A[i]; j < dp2.size(); ++j) {
			dp2[j] = min(dp2[j], dp2[j - A[i]] + 1);
		}
	}
	bool yes = true;
	for (int i = 0; i < dp1.size(); ++i) {
		if (dp1[i] > dp2[i]) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "" : "non-") << "canonical\n";
	return 0;
}
