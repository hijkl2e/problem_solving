#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	vector<string> A;
	while (cin >> s2) {
		A.push_back(s2);
	}
	if (s1.size() != A.size()) {
		cout << "False\n";
		return 0;
	}
	vector<string> B(128);
	map<string, char> C;
	for (int i = 0; i < s1.size(); ++i) {
		B[s1[i]] = A[i];
		C[A[i]] = s1[i];
	}
	bool yes = true;
	for (int i = 0; i < s1.size(); ++i) {
		yes &= B[s1[i]] == A[i] && C[A[i]] == s1[i];
	}
	cout << (yes ? "True" : "False") << "\n";
	return 0;
}
