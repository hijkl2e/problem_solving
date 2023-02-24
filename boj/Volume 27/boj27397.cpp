#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	int N{};
	cin >> S >> N;
	vector<char> A(123);
	for (int i = 'A'; i <= 'z'; ++i) {
		A[i] = i;
	}
	while (N--) {
		int q{};
		cin >> q;
		if (q == 2) {
			int ans{}, cnt{};
			char p{};
			for (char c : S) {
				if (p == A[c]) {
					++cnt;
				} else {
					ans = max(ans, cnt);
					p = A[c];
					cnt = 1;
				}
			}
			ans = max(ans, cnt);
			cout << ans << "\n";
			continue;
		}
		char c1{}, c2{};
		cin >> c1 >> c2;
		for (int i = 'A'; i <= 'z'; ++i) {
			if (A[i] == c1) {
				A[i] = c2;
			}
		}
	}
	return 0;
}
