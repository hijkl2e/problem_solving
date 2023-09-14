#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		cout << "4\n";
		cout << "1 " << N << "\n";
		cout << N % 2 + 1 << " " << N << "\n";
		cout << "1 2\n1 2\n";
	}
	return 0;
}
