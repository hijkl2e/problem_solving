#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "2000\n";
	for (int i = 0; i < 2000; ++i) {
		cout << (i < 1000 ? 1 : 1000) << (i == 1999 ? "\n" : " ");
	}
	return 0;
}
