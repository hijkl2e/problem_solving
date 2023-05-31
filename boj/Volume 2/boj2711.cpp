#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int p{};
		string S;
		cin >> p >> S;
		S.erase(S.begin() + p - 1);
		cout << S << "\n";
	}
	return 0;
}
