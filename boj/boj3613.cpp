#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A;
	bool f{};
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '_') {
			A.push_back(i);
		} else if (isupper(S[i])) {
			f = true;
		}
	}
	bool err = !islower(S.front()) || S.back() == '_' || (A.size() && f);
	for (int i = 1; i < A.size(); ++i) {
		err |= A[i] - A[i - 1] == 1;
	}
	if (err) {
		cout << "Error!\n";
		return 0;
	}
	if (A.size()) {
		reverse(A.begin(), A.end());
		for (int x : A) {
			S.erase(S.begin() + x);
			S[x] = toupper(S[x]);
		}
	} else {
		for (int i = 0; i < S.size(); ++i) {
			if (isupper(S[i])) {
				S[i] = tolower(S[i]);
				S.insert(S.begin() + i, '_');
			}
		}
	}
	cout << S << "\n";
	return 0;
}
