#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	deque<bool> A(S.size());
	for (int i = 0; i < S.size(); ++i) {
		auto it1 = find(A.rbegin(), A.rend(), false);
		auto it2 = find(it1 + 1, A.rend(), true);
		int p = min_element(S.begin() + (it2.base() - A.begin()),
							S.begin() + (it1.base() - A.begin())) - S.begin();
		A[p] = true;
		string T;
		for (int j = 0; j < S.size(); ++j) {
			if (A[j]) {
				T += S[j];
			}
		}
		cout << T << "\n";
	}
	return 0;
}
