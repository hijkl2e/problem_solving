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
		int maxi = -1;
		bool yes{};
		for (int i = 0; i < N; ++i) {
			if (maxi == -1 || A[maxi] < A[i]) {
				maxi = i;
				yes = true;
			} else if (A[maxi] == A[i]) {
				yes = false;
			}
		}
		if (yes) {
			int sum = accumulate(A.begin(), A.end(), 0);
			cout << (A[maxi] > sum / 2 ? "majority" : "minority") << " winner " << maxi + 1 << "\n";
		} else {
			cout << "no winner\n";
		}
	}
	return 0;
}
