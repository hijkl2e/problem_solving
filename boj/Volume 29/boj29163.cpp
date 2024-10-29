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
	int cnt{};
	for (int i = 0; i < N; ++i) {
		cnt += A[i] % 2 ? -1 : 1;
	}
	cout << (cnt > 0 ? "Happy" : "Sad") << "\n";
	return 0;
}
