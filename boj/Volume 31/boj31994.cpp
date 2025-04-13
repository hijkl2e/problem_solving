#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	int cnt{};
	for (int i = 0; i < 7; ++i) {
		string s;
		int k{};
		cin >> s >> k;
		if (cnt < k) {
			S = s;
			cnt = k;
		}
	}
	cout << S << "\n";
	return 0;
}
