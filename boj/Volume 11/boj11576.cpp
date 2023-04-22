#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	int N{}, M{};
	cin >> M;
	while (M--) {
		int x{};
		cin >> x;
		N = a * N + x;
	}
	vector<int> A;
	while (N) {
		A.push_back(N % b);
		N /= b;
	}
	reverse(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
