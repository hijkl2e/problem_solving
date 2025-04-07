#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		vector<string> A;
		while (iss >> s) {
			A.push_back(s);
		}
		set<string> S;
		while (getline(cin, s), s != "what does the fox say?") {
			iss = istringstream(s);
			iss >> s >> s >> s;
			S.insert(s);
		}
		vector<string> B;
		for (auto &s : A) {
			if (S.find(s) == S.end()) {
				B.push_back(s);
			}
		}
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
