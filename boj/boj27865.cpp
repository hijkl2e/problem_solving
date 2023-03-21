#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (true) {
		cout << "? " << N << endl;
		char c{};
		cin >> c;
		if (c == 'Y') {
			break;
		}
	}
	cout << "! " << N << endl;
	return 0;
}
