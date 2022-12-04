#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, K{};
		cin >> N >> M >> K;
		vector<int> A(K);
		for (int i = 0; i < K; ++i) {
			cin >> A[i];
		}
		int idx = K;
		deque<bool> vst(K + 1);
		bool yes = true;
		for (int i = 0, j = K; i < K; ++i) {
			vst[A[i]] = true;
			while (vst[j]) {
				--j;
			}
			if ((i + 1) + (j - K) > N * M - 4) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "YA" : "TIDAK") << "\n";
	}
	return 0;
}
