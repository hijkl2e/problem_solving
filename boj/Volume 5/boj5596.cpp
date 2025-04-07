#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(4);
	vector<int> B(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> B[i];
	}
	int ans = max(accumulate(A.begin(), A.end(), 0), accumulate(B.begin(), B.end(), 0));
	cout << ans << "\n";
	return 0;
}
