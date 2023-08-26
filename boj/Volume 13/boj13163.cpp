#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		iss >> s;
		cout << "god";
		while (iss >> s) {
			cout << s;
		}
		cout << "\n";
	}
	return 0;
}
