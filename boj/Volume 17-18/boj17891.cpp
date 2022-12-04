#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(2 * N);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	stack<int> st1;
	for (int i = A.size() - 1; i >= 0; --i) {
		st1.push(A[i]);
	}
	stack<int> st2;
	while (st1.size()) {
		if (st2.size() && st1.top() == st2.top()) {
			st2.pop();
		} else {
			st2.push(st1.top());
		}
		st1.pop();
	}
	if (st2.empty()) {
		cout << 2 * N << "\n";
	} else {
		cout << "impossible\n";
	}
	return 0;
}
