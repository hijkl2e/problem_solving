#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	bool yes = true;
	for (int i = 1; i <= N; ++i) {
		string s;
		cin >> s;
		if (s == "mumble") {
			continue;
		}
		int x = stoi(s);
		yes &= x == i;
	}
	cout << (yes ? "makes sense" : "something is fishy") << "\n";
	return 0;
}
