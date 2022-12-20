#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(1e6 + 1);
	for (int i = 1; i < A.size(); ++i) {
		A[i] = A[i - 1];
		string s = to_string(i);
		if (count(s.begin(), s.end(), '0') == s.size() - 1) {
			++A[i];
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << A[N] << "\n";
	}
	return 0;
}
