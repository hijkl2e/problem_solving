#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(2 * N);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	deque<bool> B(2 * N);
	deque<int> C;
	int ans{};
	while (K > 0) {
		rotate(A.begin(), A.end() - 1, A.end());
		rotate(B.begin(), B.end() - 1, B.end());
		for (int &x : C) {
			++x;
		}
		if (C.size() && C[0] == N - 1) {
			C.pop_front();
			B[N - 1] = false;
		}
		for (int &x : C) {
			int y = x + 1;
			if (B[y] || A[y] == 0) {
				continue;
			}
			B[x] = false;
			B[y] = true;
			if (--A[y] == 0) {
				--K;
			}
			x = y;
		}
		if (C.size() && C[0] == N - 1) {
			C.pop_front();
			B[N - 1] = false;
		}
		if (A[0]) {
			C.push_back(0);
			B[0] = true;
			if (--A[0] == 0) {
				--K;
			}
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
