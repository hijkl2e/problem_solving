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
	int ans{};
	while (true) {
		for (int i = 0; i < N; ++i) {
			if (A[i] % 2) {
				--A[i];
				++ans;
			}
		}
		if (count(A.begin(), A.end(), 0) == N) {
			break;
		}
		for (int i = 0; i < N; ++i) {
			A[i] /= 2;
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
