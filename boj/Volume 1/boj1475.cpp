#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(10);
	for (char c : S) {
		++A[(c == '9' ? '6' : c) - '0'];
	}
	A[6] = (A[6] + 1) / 2;
	int ans = *max_element(A.begin(), A.end());
	cout << ans << "\n";
	return 0;
}
