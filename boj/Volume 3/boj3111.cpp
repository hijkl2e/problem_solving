#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, T;
	getline(cin, A);
	getline(cin, T);
	deque<char> dq;
	for (char c : T) {
		dq.push_back(c);
	}
	string B = A, S;
	reverse(B.begin(), B.end());
	T = S;
	while (true) {
		while (dq.size() || T.size()) {
			if (dq.size()) {
				S += dq.front(); dq.pop_front();
			} else {
				S += T.back(); T.pop_back();
			}
			if (S.size() >= A.size() && S.substr(S.size() - A.size()) == A) {
				S.erase(S.end() - A.size(), S.end());
				break;
			}
		}
		if (dq.empty() && T.empty()) {
			break;
		}
		while (dq.size() || S.size()) {
			if (dq.size()) {
				T += dq.back(); dq.pop_back();
			} else {
				T += S.back(); S.pop_back();
			}
			if (T.size() >= B.size() && T.substr(T.size() - B.size()) == B) {
				T.erase(T.end() - B.size(), T.end());
				break;
			}
		}
	}
	cout << S << "\n";
	return 0;
}
