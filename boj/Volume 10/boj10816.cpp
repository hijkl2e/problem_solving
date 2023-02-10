#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int M{};
	cin >> M;
	while (M--) {
		int x{};
		cin >> x;
		auto [it1, it2] = equal_range(A.begin(), A.end(), x);
		cout << it2 - it1 << (M ? " " : "\n");
	}
	return 0;
}
