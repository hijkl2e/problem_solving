#include <bits/stdc++.h>

using namespace std;

bool solve(deque<char> &dq, bool L, string &P) {
	if (dq.size() < P.size()) {
		return false;
	}
	int p = L ? dq.size() - P.size() : 0;
	for (int i = 0; i < P.size(); ++i) {
		if (dq[p + i] != P[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string P, T;
	getline(cin, P);
	getline(cin, T);
	deque<char> dqL, dqM, dqR;
	for (char c : T) {
		dqM.push_back(c);
	}
	int N{};
	cin >> N;
	while (N--) {
		char c{};
		cin >> c;
		if (c == 'L') {
			while (!solve(dqL, true, P) && (dqM.size() || dqR.size())) {
				auto &dqX = dqM.size() ? dqM : dqR;
				dqL.push_back(dqX.front());
				dqX.pop_front();
			}
			if (solve(dqL, true, P)) {
				dqL.erase(dqL.begin() + dqL.size() - P.size(), dqL.end());
			} else {
				break;
			}
		} else {
			while (!solve(dqR, false, P) && (dqM.size() || dqL.size())) {
				auto &dqX = dqM.size() ? dqM : dqL;
				dqR.push_front(dqX.back());
				dqX.pop_back();
			}
			if (solve(dqR, false, P)) {
				dqR.erase(dqR.begin(), dqR.begin() + P.size());
			} else {
				break;
			}
		}
	}
	string S;
	for (auto &dqX : {dqL, dqM, dqR}) {
		for (char c : dqX) {
			S += c;
		}
	}
	cout << (T.size() - S.size()) / P.size() << "\n";
	cout << S << "\n";
	cout << (S.find(P) == -1 ? "Perfect!" : "You Lose!") << "\n";
	return 0;
}
