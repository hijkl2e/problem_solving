#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	if (S.substr(0, 2) == "::") {
		S.erase(S.begin());
	}
	istringstream iss(S);
	vector<string> A;
	while (getline(iss, S, ':')) {
		A.push_back(S);
	}
	while (A.size() < 8) {
		A.insert(find(A.begin(), A.end(), ""), "");
	}
	for (int i = 0; i < 8; ++i) {
		cout << setfill('0') << setw(4) << A[i] << (i == 7 ? "\n" : ":");
	}
	return 0;
}
