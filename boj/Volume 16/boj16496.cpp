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
	sort(A.begin(), A.end(), [](string &s1, string &s2) {
		return s1 + s2 > s2 + s1;
	});
	string S = accumulate(A.begin(), A.end(), string(""));
	if (S[0] == '0') {
		cout << "0\n";
	} else {
		cout << S << "\n";
	}
	return 0;
}
