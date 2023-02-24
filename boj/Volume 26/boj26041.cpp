#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	istringstream iss(s);
	vector<string> A;
	while (iss >> s) {
		A.push_back(s);
	}
	getline(cin, s);
	int ans{};
	for (int i = 0; i < A.size(); ++i) {
		if (A[i].size() > s.size() && A[i].substr(0, s.size()) == s) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
