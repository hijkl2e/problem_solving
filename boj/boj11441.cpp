#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int M{};
	cin >> M;
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		cout << A[b] - A[a - 1] << "\n";
	}
	return 0;
}
