#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	map<string, int> F;
	while (N--) {
		string S;
		getline(cin, S);
		vector<int> A(26, -1);
		int x{};
		for (auto &c : S) {
			if (A[c - 'a'] == -1) {
				A[c - 'a'] = 'a' + x++;
			}
			c = A[c - 'a'];
		}
		++F[S];
	}
	int ans{};
	for (auto &[s, f] : F) {
		ans += f * (f - 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}
