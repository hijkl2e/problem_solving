#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{}, K{};
	cin >> N >> Q >> K;
	deque<int> A, B;
	set<int> S;
	bool f1{}, f2{};
	while (Q--) {
		int q{}, p{};
		cin >> q;
		if (q == 0) {
			cin >> p;
			if (f1) {
				B.push_back(p);
			} else {
				A.push_back(p);
			}
		} else if (q == 1) {
			S.insert(A.begin(), A.end());
			S.insert(B.begin(), B.end());
			A.clear();
			B.clear();
			f2 = false;
		} else {
			f1 ^= true;
			f2 ^= true;
		}
	}
	int ans{};
	while (K--) {
		if (f1) {
			if (B.size()) {
				ans = B.back(); B.pop_back();
			} else if (S.size()) {
				auto it = f2 ? --S.end() : S.begin();
				ans = *it;
				S.erase(it);
			} else {
				ans = A.front(); A.pop_front();
			}
		} else {
			if (A.size()) {
				ans = A.back(); A.pop_back();
			} else if (S.size()) {
				auto it = f2 ? --S.end() : S.begin();
				ans = *it;
				S.erase(it);
			} else {
				ans = B.front(); B.pop_front();
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
