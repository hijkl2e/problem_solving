#include <bits/stdc++.h>

using namespace std;

int find(const string &S, const string &T) {
	int ret{}, p = -1;
	while ((p = S.find(T, p + 1)) != -1) {
		++ret;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	cout << find(S, "JOI") << "\n";
	cout << find(S, "IOI") << "\n";
	return 0;
}
