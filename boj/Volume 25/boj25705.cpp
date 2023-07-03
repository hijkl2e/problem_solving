#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string P;
	getline(cin, P);
	int M{};
	cin >> M;
	cin.ignore();
	string S;
	getline(cin, S);
	int ans{};
	for (char c : S) {
		int p = P.find(c);
		if (p == -1) {
			ans = -1;
			break;
		}
		ans += p + 1;
		rotate(P.begin(), P.begin() + p + 1, P.end());
	}
	cout << ans << "\n";
	return 0;
}
