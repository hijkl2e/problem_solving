#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
	}
	int x{};
	cin >> x;
	int cnt = count(A.begin(), A.end(), 1);
	ii ans{-1, -1};
	for (int i = 0; i + x <= N; ++i) {
		if (A[i] == 0 || A[i] == 2 || A[i + x] == 0) {
			continue;
		}
		cnt -= A[i] == 1;
		cnt -= A[i + x] == 1;
		if (cnt == 0) {
			ans = {i, i + x};
			break;
		}
		cnt += A[i] == 1;
		cnt += A[i + x] == 1;
	}
	if (ans.first == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
