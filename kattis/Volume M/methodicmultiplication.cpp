#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	cin >> A >> B;
	int x = (A.size() - 1) / 3;
	int y = (B.size() - 1) / 3;
	int xy = x * y;
	for (int i = 0; i < xy; ++i) {
		cout << "S(";
	}
	cout << "0";
	for (int i = 0; i < xy; ++i) {
		cout << ")";
	}
	cout << "\n";
	return 0;
}
