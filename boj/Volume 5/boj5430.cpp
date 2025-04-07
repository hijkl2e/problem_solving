#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string P;
		getline(cin, P);
		int N{};
		cin >> N;
		cin.ignore();
		string S;
		getline(cin, S);
		istringstream iss(S);
		deque<int> dq(N);
		for (int i = 0; i < N; ++i) {
			char c{};
			iss >> c >> dq[i];
		}
		bool rev{}, err{};
		for (char c : P) {
			if (c == 'R') {
				rev ^= true;
				continue;
			}
			if (dq.empty()) {
				err = true;
				break;
			}
			if (rev) {
				dq.pop_back();
			} else {
				dq.pop_front();
			}
		}
		if (rev) {
			reverse(dq.begin(), dq.end());
		}
		if (err) {
			cout << "error\n";
		} else {
			cout << "[";
			for (int i = 0; i < dq.size(); ++i) {
				cout << dq[i] << (i == dq.size() - 1 ? "" : ",");
			}
			cout << "]\n";
		}
	}
	return 0;
}
