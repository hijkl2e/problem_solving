#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (true) {
		string s = to_string(N);
		bool yes = true;
		for (char c : s) {
			if (c != '4' && c != '7') {
				yes = false;
				break;
			}
		}
		if (yes) {
			break;
		}
		--N;
	}
	cout << N << "\n";
	return 0;
}
