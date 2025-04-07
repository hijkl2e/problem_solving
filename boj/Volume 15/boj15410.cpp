#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	vector<int> C;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i] <= B[j]) {
				C.push_back(B[j] - A[i]);
			}
		}
	}
	sort(C.begin(), C.end());
	int maxv{}, ans{};
	int cnt = 1;
	for (int i = 1; i < C.size(); ++i) {
		if (C[i - 1] == C[i]) {
			++cnt;
		} else {
			if (maxv < cnt) {
				maxv = cnt;
				ans = C[i - 1];
			}
			cnt = 1;
		}
	}
	if (maxv < cnt && C.size()) {
		ans = C.back();
	}
	cout << ans << "\n";
	return 0;
}
