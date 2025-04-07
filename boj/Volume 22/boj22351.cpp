#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int a{}, b{};
	for (int i = 1; i < 4; ++i) {
		a = stoi(S.substr(0, i));
		b = a;
		int j = i;
		bool flag = true;
		while (j < S.size()) {
			string s = to_string(++b);
			if (S.find(s, j) == j) {
				j += s.size();
			} else {
				flag = false;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	cout << a << " " << b << "\n";
	return 0;
}
