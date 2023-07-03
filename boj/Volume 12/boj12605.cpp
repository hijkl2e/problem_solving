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
		istringstream iss(S);
		vector<string> A;
		while (iss >> S) {
			A.push_back(S);
		}
		reverse(A.begin(), A.end());
		cout << "Case #" << tc << ":";
		for (auto &s : A) {
			cout << " " << s;
		}
		cout << "\n";
	}
	return 0;
}
