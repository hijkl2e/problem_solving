#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, T{}, N{};
	cin >> S >> T >> N;
	vector<int> D(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> D[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}
	int t = S;
	for (int i = 0; i < N; ++i) {
		t += D[i];
		t += (C[i] - (t % C[i])) % C[i];
		t += B[i];
	}
	t += D[N];
	cout << (t <= T ? "yes" : "no") << "\n";
	return 0;
}
