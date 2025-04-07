#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ii ans{-1, -1};
	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				if (--K == 0) {
					ans = {A[j], A[j + 1]};
					i = -1;
					break;
				}
			}
		}
	}
	if (ans.first == -1) {
		cout << "-1\n";
	} else {
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
