#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		deque<bool> B(N);
		for (int i = 0; i < 2 * N - 1; ++i) {
			int x{};
			char c{};
			cin >> x >> c;
			B[x - 1] ^= true;
		}
		int p = find(B.begin(), B.end(), true) - B.begin();
		cout << tc << " " << A[p] << "\n";
	}
	return 0;
}
