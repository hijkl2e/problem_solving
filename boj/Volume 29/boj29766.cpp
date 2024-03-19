#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int cnt{};
	for (int i = 0; i < S.size(); ++i) {
		if (S.substr(i, 4) == "DKSH") {
			++cnt;
		}
	}
	cout << cnt << "\n";
	return 0;
}
