#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int N{};
	cin >> N;
	cin.ignore();
	int cnt{};
	while (N--) {
		string T;
		getline(cin, T);
		if (S == T) {
			++cnt;
		}
	}
	cout << cnt << "\n";
	return 0;
}
