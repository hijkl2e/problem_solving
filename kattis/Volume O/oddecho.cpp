#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		if (i % 2 == 0) {
			cout << s << "\n";
		}
	}
	return 0;
}
