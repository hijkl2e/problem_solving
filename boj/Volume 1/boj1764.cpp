#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	set<string> A, B;
	while (N--) {
		string s;
		getline(cin, s);
		A.insert(s);
	}
	while (M--) {
		string s;
		getline(cin, s);
		if (A.count(s)) {
			B.insert(s);
		}
	}
	cout << B.size() << "\n";
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
