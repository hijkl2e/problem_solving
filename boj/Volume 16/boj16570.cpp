#include <bits/stdc++.h>

using namespace std;

vector<int> get_pi(vector<int> &s) {
	vector<int> pi(s.size());
	for (int i = 1; i < pi.size(); ++i) {
		int j = pi[i - 1];
		while (j && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	reverse(A.begin(), A.end());
	vector<int> pi = get_pi(A);
	int maxv = *max_element(pi.begin(), pi.end());
	int cnt = count(pi.begin(), pi.end(), maxv);
	if (maxv) {
		cout << maxv << " " << cnt << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
