#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

ii solve(string &s1, string &s2) {
	int S{}, B{};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (s1[i] == s2[j]) {
				if (i == j) {
					++S;
				} else {
					++B;
				}
			}
		}
	}
	return {S, B};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	vector<int> S(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> S[i] >> B[i];
	}
	int ans{};
	for (int i = 100; i < 1000; ++i) {
		string s = to_string(i);
		if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0] || s.find('0') != -1) {
			continue;
		}
		bool yes = true;
		for (int j = 0; j < N; ++j) {
			auto [x, y] = solve(s, A[j]);
			if (x != S[j] || y != B[j]) {
				yes = false;
				break;
			}
		}
		if (yes) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
