#include <bits/stdc++.h>

using namespace std;

int solve(string &s1, string &s2) {
	vector<int> A(4);
	for (int k = 0; k < 2; ++k) {
		for (char c : (k ? s2 : s1)) {
			if (c == 'L') {
				++A[0];
			} else if (c == 'O') {
				++A[1];
			} else if (c == 'V') {
				++A[2];
			} else if (c == 'E') {
				++A[3];
			}
		}
	}
	int ret = 1;
	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			ret = ret * (A[i] + A[j]) % 100;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	cin >> S;
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	string ans;
	int maxv = -1;
	for (int i = 0; i < N; ++i) {
		int res = solve(S, A[i]);
		if (maxv < res) {
			maxv = res;
			ans = A[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
