#include <bits/stdc++.h>

using namespace std;

using ss = pair<string, string>;

string to_lower(string &s) {
	string ret = s;
	for (auto &c : ret) {
		c = tolower(c);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<ss> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].second;
			A[i].first = to_lower(A[i].second);
		}
		cout << min_element(A.begin(), A.end())->second << "\n";
	}
	return 0;
}
