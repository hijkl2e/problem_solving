#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(10);
	for (char c : S) {
		++A[c - '0'];
	}
	string ans;
	for (int i = 1; ans.empty(); ++i) {
		if (A[0] < i - 1) {
			ans = "1" + string(i - 1, '0');
			break;
		}
		for (int j = 1; j < 10; ++j) {
			if (A[j] < i) {
				char c = '0' + j;
				ans = string(i, c);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
