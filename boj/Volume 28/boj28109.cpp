#include <bits/stdc++.h>

using namespace std;

string solve(string &S, int K) {
	string ret = S;
	for (int i = 0; i < S.size(); ++i) {
		int x = S[i] - 'A';
		if (K <= x) {
			ret[i] = 'A' + K - 1;
			return ret;
		}
		K -= x;
	}
	if (K-- == 1) {
		return ret;
	}
	for (int i = S.size() - 1; i >= 0; --i) {
		int x = 'Z' - S[i];
		if (K <= x) {
			ret[i] += K;
			return ret;
		}
		K -= x;
	}
	return "-1";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	cin.ignore();
	string S;
	getline(cin, S);
	cout << solve(S, K) << "\n";
	return 0;
}
