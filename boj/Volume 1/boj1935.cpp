#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<double> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	stack<double> st;
	for (char c : S) {
		if (isupper(c)) {
			st.push(A[c - 'A']);
			continue;
		}
		double y = st.top(); st.pop();
		double x = st.top(); st.pop();
		double z{};
		if (c == '+') {
			z = x + y;
		} else if (c == '-') {
			z = x - y;
		} else if (c == '*') {
			z = x * y;
		} else {
			z = x / y;
		}
		st.push(z);
	}
	cout << fixed << setprecision(2);
	cout << st.top() << "\n";
	return 0;
}
