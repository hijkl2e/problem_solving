#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	vector<stack<int>> B(M);
	for (int i = 0; i < M; ++i) {
		int k{};
		cin >> k;
		while (k--) {
			int x{};
			cin >> x;
			A[x] = i;
			B[i].push(x);
		}
	}
	bool yes = true;
	for (int i = 1; i <= N; ++i) {
		if (B[A[i]].top() == i) {
			B[A[i]].pop();
		} else {
			yes = false;
			break;
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
