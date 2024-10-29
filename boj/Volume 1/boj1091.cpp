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
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C(A.begin(), A.end());
	vector<int> D(N);
	int ans{};
	while (true) {
		bool flag = true;
		for (int i = 0; i < N; ++i) {
			if (C[i] % 3 != i % 3) {
				flag = false;
				break;
			}
		}
		if (flag) {
			break;
		} else if (ans && A == C) {
			ans = -1;
			break;
		}
		for (int i = 0; i < N; ++i) {
			D[B[i]] = C[i];
		}
		swap(C, D);
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
