#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &A) {
	if (A.empty()) {
		cout << "None\n";
		return;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> D(N + 1);
	vector<int> A, B;
	deque<int> dq;
	while (N--) {
		int q{}, a{}, b{};
		cin >> q >> a;
		if (q == 1) {
			cin >> b;
			D[a] = b;
			dq.push_back(a);
		} else {
			int x = dq.front();
			dq.pop_front();
			if (D[x] == a) {
				A.push_back(x);
			} else {
				B.push_back(x);
			}
		}
	}
	vector<int> C(dq.begin(), dq.end());
	print(A);
	print(B);
	print(C);
	return 0;
}
