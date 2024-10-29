#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	for (int tc = 1; tc <= T; ++tc) {
		string S;
		getline(cin, S);
		vector<int> A(26);
		for (char c : S) {
			if (isalpha(c)) {
				++A[tolower(c) - 'a'];
			}
		}
		int minv = *min_element(A.begin(), A.end());
		string res;
		if (minv == 0) {
			res = "Not a pangram";
		} else if (minv == 1) {
			res = "Pangram!";
		} else if (minv == 2) {
			res = "Double pangram!!";
		} else {
			res = "Triple pangram!!!";
		}
		cout << "Case " << tc << ": " << res << "\n";
	}
	return 0;
}
