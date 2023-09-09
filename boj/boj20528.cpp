#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	bool yes = true;
	for (int i = 0; i < N - 1; ++i) {
		yes &= A[i][0] == A[i + 1][0];
	}
	cout << yes << "\n";
	return 0;
}
