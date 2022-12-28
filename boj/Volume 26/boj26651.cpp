#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{};
	cin >> X;
	string S = "Z";
	for (int i = 31623; i > 0; --i) {
		while (X >= i * i) {
			S += string(i, 'A');
			S += "BCDEFGHIJKLMNOPQRSTUVWXY";
			S += string(i, 'Z');
			X -= i * i;
		}
	}
	cout << S << "\n";
	return 0;
}
