#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{};
	cin >> K >> N;
	vector<int> A(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	int maxv = *max_element(A.begin(), A.end());
	vector<string> B(N, to_string(maxv));
	for (int i = 0; i < K; ++i) {
		B[i] = to_string(A[i]);
	}
	sort(B.begin(), B.end(), [](string &s1, string &s2) {
		return s1 + s2 > s2 + s1;
	});
	string ans = accumulate(B.begin(), B.end(), string(""));
	cout << ans << "\n";
	return 0;
}
