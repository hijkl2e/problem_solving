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
		cin.ignore();
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		int a{}, b{};
		for (int i = 0; i < N; ++i) {
			if (s1[i] == s2[i]) {
				continue;
			} else if (s1[i] == 'W') {
				++a;
			} else {
				++b;
			}
		}
		cout << max(a, b) << "\n";
	}
	return 0;
}
