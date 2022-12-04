#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (cin >> S) {
		map<string, int> d2i, c2i;
		getline(cin, S);
		istringstream iss(S);
		while (iss >> S) {
			d2i.insert({S, d2i.size()});
		}
		cin >> S;
		getline(cin, S);
		iss = istringstream(S);
		while (iss >> S) {
			c2i.insert({S, c2i.size()});
		}
		vector<int> A(d2i.size());
		vector<int> B(c2i.size());
		int N{};
		cin >> N;
		while (N--) {
			string x, y, s;
			cin >> x >> s >> y;
			++A[d2i[x]];
			++B[c2i[y]];
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		if (A.back() > 1) {
			cout << "not a function\n";
		} else if (B.front() == B.back() && B.front() == 1) {
			cout << "bijective\n";
		} else if (B.front() >= 1) {
			cout << "surjective\n";
		} else if (B.back() <= 1) {
			cout << "injective\n";
		} else {
			cout << "neither injective nor surjective\n";
		}
	}
	return 0;
}
