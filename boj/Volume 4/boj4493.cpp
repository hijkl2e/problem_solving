#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int cnt{};
		while (N--) {
			char c1{}, c2{};
			cin >> c1 >> c2;
			cnt += c1 == c2 ? 0 : (c2 == (c1 == 'R' ? 'S' : c1 == 'P' ? 'R' : 'P') ? 1 : -1);
		}
		cout << (cnt > 0 ? "Player 1" : cnt < 0 ? "Player 2" : "TIE") << "\n";
	}
	return 0;
}
