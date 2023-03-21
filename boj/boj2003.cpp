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
	int p1{}, p2{}, sum{}, ans{};
	while (true) {
		if (sum < M) {
			if (p2 == N) {
				break;
			}
			sum += A[p2++];
		} else {
			if (sum == M) {
				++ans;
			}
			sum -= A[p1++];
		}
	}
	cout << ans << "\n";
	return 0;
}
