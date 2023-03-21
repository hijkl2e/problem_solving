#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{}, x{};
	for (int i = 0; i < N; ++i) {
		x += A[i];
		if (i - L >= 0) {
			x -= A[i - L];
		}
		if (129 <= x && x <= 138) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
