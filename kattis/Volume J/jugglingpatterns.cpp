#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S)) {
		cout << S << ": ";
		int sum{};
		for (char c : S) {
			sum += c - '0';
		}
		if (sum % S.size()) {
			cout << "invalid # of balls\n";
			continue;
		}
		deque<bool> A(S.size());
		for (int i = 0; i < S.size(); ++i) {
			A[(i + S[i] - '0') % S.size()] = true;
		}
		bool valid = accumulate(A.begin(), A.end(), 0) == S.size();
		if (valid) {
			cout << "valid with " << (sum / S.size()) << " balls\n";
		} else {
			cout << "invalid pattern\n";
		}
	}
	return 0;
}
