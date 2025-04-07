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
	vector<int> B(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		B[i] = i;
	}
	vector<int> C;
	while (B.size()) {
		for (int x : B) {
			if (A[x] > A[x + 1]) {
				swap(A[x], A[x + 1]);
				if (--K == 0) {
					ans = {A[x], A[x + 1]};
					C.clear();
					break;
				}
				if (x) {
					C.push_back(x - 1);
				}
			}
		}
		swap(B, C);
		C.clear();
	}
	if (ans.first == -1) {
		cout << "-1\n";
	} else {
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
