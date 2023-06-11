#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(S.size());
	stack<int> st;
	int cnt{};
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '(') {
			st.push(i);
			A[i] = cnt++;
		} else if (S[i] == ')') {
			A[i] = A[st.top()];
			st.pop();
		}
	}
	vector<string> B((1 << cnt) - 1);
	for (int i = 0; i < B.size(); ++i) {
		for (int j = 0; j < S.size(); ++j) {
			if ((S[j] != '(' && S[j] != ')') || (i >> A[j]) & 1) {
				B[i] += S[j];
			}
		}
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
