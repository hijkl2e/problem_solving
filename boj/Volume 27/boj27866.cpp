#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int x{};
	cin >> x;
	cout << S[x - 1] << "\n";
	return 0;
}
