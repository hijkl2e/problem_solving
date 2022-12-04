#include <bits/stdc++.h>

using namespace std;

string bottle(int x) {
	return to_string(x) + " bottle" + (x == 1 ? "" : "s");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	string B;
	cin >> N >> B;
	for (int i = N; i > 0; --i) {
		cout << bottle(i) << " of " << B << " on the wall, ";
		cout << bottle(i) << " of " << B << ".\n";
		if (i > 1) {
			cout << "Take one down, pass it around, ";
			cout << bottle(i - 1) << " of " << B << " on the wall.\n\n";
		} else {
			cout << "Take it down, pass it around, ";
			cout << "no more bottles of " << B << ".\n";
		}
	}
	return 0;
}
