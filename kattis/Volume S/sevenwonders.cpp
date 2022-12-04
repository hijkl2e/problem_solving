#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(3);
	for (char c : S) {
		++A[c % 3];
	}
	int ans{};
	for (int i = 0; i < 3; ++i) {
		ans += A[i] * A[i];
	}
	ans += 7 * min(min(A[0], A[1]), A[2]);
	cout << ans << "\n";
	return 0;
}
