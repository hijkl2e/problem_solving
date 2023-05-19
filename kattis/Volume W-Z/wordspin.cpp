#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> A(s1.size());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = s1[i] - s2[i];
	}
	int ans = abs(A[0]);
	for (int i = 1; i < A.size(); ++i) {
		ans += max(abs(A[i]) - (A[i] * A[i - 1] > 0 ? abs(A[i - 1]) : 0), 0);
	}
	cout << ans << "\n";
	return 0;
}
