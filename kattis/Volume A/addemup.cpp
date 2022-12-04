#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int turn(int x) {
	string s = to_string(x);
	reverse(s.begin(), s.end());
	for (auto &c : s) {
		if (c == '3' || c == '4' || c == '7') {
			return x;
		} else if (c == '6') {
			c = '9';
		} else if (c == '9') {
			c = '6';
		}
	}
	return stoi(s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{};
	cin >> N >> S;
	vector<ii> A;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		int y = turn(x);
		A.push_back({x, i});
		if (x != y) {
			A.push_back({y, i});
		}
	}
	sort(A.begin(), A.end());
	bool yes = false;
	int L = 0, R = A.size() - 1;
	while (L < R) {
		int sum = A[L].first + A[R].first;
		if (sum < S) {
			++L;
		} else if (sum > S) {
			--R;
		} else {
			if (A[L].second == A[R].second) {
				++L;
			} else {
				yes = true;
				break;
			}
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
