#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string BS = "BRONZESILVER";
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A(26);
	for (char c : S) {
		++A[c - 'A'];
	}
	int ans{};
	while (true) {
		bool yes = true;
		for (char c : BS) {
			if (A[c - 'A']-- == 0) {
				yes = false;
				break;
			}
		}
		if (yes) {
			++ans;
		} else {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
