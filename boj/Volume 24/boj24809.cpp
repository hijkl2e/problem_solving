#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(2);
	while (N--) {
		string s;
		cin >> s;
		for (int i = 0; i < 4; ++i) {
			A[i / 2] += '1' - s[i];
		}
	}
	int ans = min(A[0], A[1]) / 2;
	A[0] -= 2 * ans;
	A[1] -= 2 * ans;
	cout << ans << " " << A[0] << " " << A[1] << "\n";
	return 0;
}
