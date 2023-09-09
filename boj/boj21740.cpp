#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (auto &s : A) {
		reverse(s.begin(), s.end());
		for (auto &c : s) {
			if (c == '6') {
				c = '9';
			} else if (c == '9') {
				c = '6';
			}
		}
	}
	sort(A.begin(), A.end(), [](string &s1, string &s2) {
		return s1 + s2 > s2 + s1;
	});
	int p{};
	for (int i = 0; i < N; ++i) {
		if (A[p].size() < A[i].size()) {
			p = i;
		}
	}
	A.insert(A.begin() + p, A[p]);
	string ans;
	for (auto &s : A) {
		ans += s;
	}
	reverse(ans.begin(), ans.end());
	for (auto &c : ans) {
		if (c == '6') {
			c = '9';
		} else if (c == '9') {
			c = '6';
		}
	}
	cout << ans << "\n";
	return 0;
}
