#include <bits/stdc++.h>

using namespace std;

void bottle(int x, bool f) {
	if (x) {
		cout << x << " bottle" << (x > 1 ? "s" : "");
	} else {
		cout << (f ? "N" : "n") << "o more bottles";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = N; i >= 0; --i) {
		bottle(i, true);
		cout << " of beer on the wall, ";
		bottle(i, false);
		cout << " of beer.\n";
		if (i) {
			cout << "Take one down and pass it around, ";
			bottle(i - 1, false);
			cout << " of beer on the wall.\n\n";
		} else {
			cout << "Go to the store and buy some more, ";
			bottle(N, false);
			cout << " of beer on the wall.\n";
		}
	}
	return 0;
}
