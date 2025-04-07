#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<is> A(N);
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		if (isdigit(s[0])) {
			A[i].first = stoi(s);
			cin >> A[i].second;
		} else {
			A[i].second = s;
			cin >> A[i].first;
			A[i].first *= 2;
		}
	}
	sort(A.begin(), A.end());
	for (auto &p : A) {
		cout << p.second << "\n";
	}
	return 0;
}
