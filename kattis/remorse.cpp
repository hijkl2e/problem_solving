#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		1, 3, 3, 5, 5, 5, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11
	};
	string S;
	getline(cin, S);
	vector<int> B(26);
	for (char c : S) {
		if (isalpha(c)) {
			++B[toupper(c) - 'A'];
		}
	}
	sort(B.rbegin(), B.rend());
	int ans = 3 * (accumulate(B.begin(), B.end(), 0) - 1);
	for (int i = 0; i < 26; ++i) {
		ans += A[i] * B[i];
	}
	cout << ans << "\n";
	return 0;
}
