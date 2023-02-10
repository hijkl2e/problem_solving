#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> psum(N + 1);
	partial_sum(A.begin(), A.end(), psum.begin());
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		cout << psum[b] - psum[a - 1] << "\n";
	}
	return 0;
}
