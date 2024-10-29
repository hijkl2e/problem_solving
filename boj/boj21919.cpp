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
	ll ans = 1;
	for (int i = 0; i < N; ++i) {
		bool flag = true;
		for (int j = 2; j * j <= A[i]; ++j) {
			if (A[i] % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = lcm(ans, A[i]);
		}
	}
	cout << (ans == 1 ? -1 : ans) << "\n";
	return 0;
}
