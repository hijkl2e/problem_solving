#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 0; cin >> N, N; ++tc) {
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		stable_sort(A.begin(), A.end(), [](const string &s1, const string &s2) {
			return s1.substr(0, 2) < s2.substr(0, 2);
		});
		if (tc) {
			cout << "\n";
		}
		for (auto &s : A) {
			cout << s << "\n";
		}
	}
	return 0;
}
