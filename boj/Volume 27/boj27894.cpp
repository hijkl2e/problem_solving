#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	bool yes = A == B;
	for (int i = 0; i < N - 2; ++i) {
		if ((B[i] < B[i + 1] && B[i + 1] < B[i + 2]) || (B[i] > B[i + 1] && B[i + 1] > B[i + 2])) {
			yes = true;
			break;
		}
	}
	cout << (yes ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
	return 0;
}
