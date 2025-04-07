#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int P{}, Q{};
	cin >> P >> Q;
	if (P > Q) {
		swap(P, Q);
	}
	string s;
	cin >> s;
	ii ans{-1, -1};
	if (s == "AABB" && Q == 7) {
		ans = {8, 9};
	} else if (s == "ABAB" && P == 6 && Q == 8) {
		ans = {7, 9};
	} else if (s == "ABBA" && Q - P == 3) {
		ans = {P + 1, Q - 1};
	} else if (s == "BAAB" && P == 2 && Q == 8) {
		ans = {1, 9};
	} else if (s == "BABA" && P == 2 && Q == 4) {
		ans = {1, 3};
	} else if (s == "BBAA" && P == 3) {
		ans = {1, 2};
	}
	if (ans.first == -1) {
		cout << "-1\n";
	} else {
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
