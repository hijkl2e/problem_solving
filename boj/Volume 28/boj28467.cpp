#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans{};
	while (A.size() > 1) {
		int p = 1;
		for (int i = 1; i < A.size(); ++i) {
			if (max(A[p - 1], A[p]) > max(A[i - 1], A[i])) {
				p = i;
			}
		}
		ans += A[p - 1] + A[p];
		A.erase(A.begin() + p - (A[p - 1] < A[p]));
	}
	cout << ans << "\n";
	return 0;
}
