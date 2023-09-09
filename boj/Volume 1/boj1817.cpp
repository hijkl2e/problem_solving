#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{}, cnt = M;
	for (int i = 0; i < N; ++i) {
		if (cnt + A[i] > M) {
			cnt = A[i];
			++ans;
		} else {
			cnt += A[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
