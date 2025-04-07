#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		string S;
		int i{}, j{};
		cin >> S >> i >> j;
		cout << S.substr(0, i) << S.substr(j) << "\n";
	}
	return 0;
}
