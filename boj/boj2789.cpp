#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string cam = "CAMBRIDGE";
	string S;
	getline(cin, S);
	for (char c : S) {
		if (cam.find(c) == -1) {
			cout << c;
		}
	}
	cout << "\n";
	return 0;
}
