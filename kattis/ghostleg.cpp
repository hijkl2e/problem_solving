#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i + 1;
	}
	while (M--) {
		int x{};
		cin >> x;
		swap(A[x - 1], A[x]);
	}
	for (int x : A) {
		cout << x << "\n";
	}
	return 0;
}
