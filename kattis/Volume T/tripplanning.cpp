#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 1; i <= M; ++i) {
		int a{}, b{};
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		if (a + 1 == b) {
			A[a - 1] = i;
		}
		if (a == 1 && b == N) {
			A[N - 1] = i;
		}
	}
	if (count(A.begin(), A.end(), 0)) {
		cout << "impossible\n";
	} else {
		for (int x : A) {
			cout << x << "\n";
		}
	}
	return 0;
}
