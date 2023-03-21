#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<string> A(S.size());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = S.substr(i);
	}
	sort(A.begin(), A.end());
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
