#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A, B;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		if (s[0] == '0') {
			B.push_back(s);
		} else {
			A.push_back(s);
		}
	}
	string ans = "INVALID";
	for (int i = 0; i < A.size(); ++i) {
		vector<string> C(A.begin(), A.end());
		swap(C[0], C[i]);
		copy(B.begin(), B.end(), back_inserter(C));
		sort(C.begin() + 1, C.end(), [](string &s1, string &s2) {
			return s1 + s2 < s2 + s1;
		});
		ans = min(ans, accumulate(C.begin(), C.end(), string("")));
	}
	cout << ans << "\n";
	return 0;
}
