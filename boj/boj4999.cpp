#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	cout << (s1.size() >= s2.size() ? "go" : "no") << "\n";
	return 0;
}
