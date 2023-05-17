#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A;
	for (int i = 1; i < 6; ++i) {
		string S;
		getline(cin, S);
		if (S.find("FBI") != -1) {
			A.push_back(i);
		}
	}
	if (A.size()) {
		for (int i = 0; i < A.size(); ++i) {
			cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
		}
	} else {
		cout << "HE GOT AWAY!\n";
	}
	return 0;
}
