#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		sort(S.begin(), S.end());
		do {
			cout << S << "\n";
		} while (next_permutation(S.begin(), S.end()));
	}
	return 0;
}
