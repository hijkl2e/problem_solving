#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, H{};
	cin >> N >> H;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(H + 1);
	vector<int> C(H + 1);
	for (int i = 0; i < N; ++i) {
		if (i % 2) {
			++C[H - A[i] + 1];
		} else {
			++B[A[i]];
		}
	}
	for (int i = H - 1; i > 0; --i) {
		B[i] += B[i + 1];
	}
	for (int i = 2; i <= H; ++i) {
		C[i] += C[i - 1];
	}
	vector<int> D(H + 1);
	for (int i = 1; i <= H; ++i) {
		D[i] = B[i] + C[i];
	}
	int ans = *min_element(D.begin() + 1, D.end());
	int cnt = count(D.begin() + 1, D.end(), ans);
	cout << ans << " " << cnt << "\n";
	return 0;
}
