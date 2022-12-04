#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int tc = 0;; ++tc) {
		vector<string> A;
		string S;
		while (getline(cin, S), S.size()) {
			reverse(S.begin(), S.end());
			A.push_back(S);
		}
		if (A.empty()) {
			break;
		}
		sort(A.begin(), A.end());
		int maxlen{};
		for (auto &s : A) {
			maxlen = max<int>(maxlen, s.size());
			reverse(s.begin(), s.end());
		}
		if (tc) {
			cout << "\n";
		}
		for (auto &s : A) {
			cout << setw(maxlen) << s << "\n";
		}
	}
	return 0;
}
