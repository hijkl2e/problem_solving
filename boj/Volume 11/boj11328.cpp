#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		vector<int> A(26);
		for (char c : s1) {
			++A[c - 'a'];
		}
		for (char c : s2) {
			--A[c - 'a'];
		}
		bool yes = count(A.begin(), A.end(), 0) == 26;
		cout << (yes ? "Possible" : "Impossible") << "\n";
	}
	return 0;
}
