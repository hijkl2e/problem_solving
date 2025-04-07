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
	int u{}, d{};
	cin >> u >> d;
	vector<int> B(4);
	for (int i = 0; i < N; ++i) {
		++B[A[i]];
	}
	if (u < B[1] || d < B[2]) {
		cout << "NO\n";
		return 0;
	}
	u -= B[1];
	cout << "YES\n";
	for (int i = 0; i < N; ++i) {
		char c = A[i] == 1 || (A[i] == 3 && u-- > 0) ? 'U' : 'D';
		cout << c;
	}
	cout << "\n";
	return 0;
}
