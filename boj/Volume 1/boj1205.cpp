#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, P{};
	cin >> N >> M >> P;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	if (N == P && M <= A.back()) {
		cout << "-1\n";
		return 0;
	}
	int p{};
	while (p < N && A[p] > M) {
		++p;
	}
	cout << p + 1 << "\n";
	return 0;
}
