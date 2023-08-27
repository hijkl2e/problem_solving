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
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		vector<int> B(N);
		deque<int> L(N);
		deque<int> R(N);
		int ans{};
		for (int i = 0; i < N; ++i) {
			L.pop_front();
			L.push_back(0);
			R.pop_back();
			R.push_front(0);
			for (int j = 0; j < N; ++j) {
				B[j] ^= L[j] ^ R[j];
			}
			for (int j = 0; j < N; ++j) {
				if (A[i][j] ^ B[j] ^ '0') {
					B[j] ^= 1;
					L[j] ^= 1;
					R[j] ^= 1;
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
