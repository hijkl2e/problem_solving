#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{};
		cin >> N;
		cin.ignore();
		string S;
		getline(cin, S);
		for (char c : S) {
			N += c == 'c' ? 1 : -1;
		}
		if (tc > 1) {
			cout << "\n";
		}
		cout << "Data Set " << tc << ":\n";
		cout << N << "\n";
	}
	return 0;
}
