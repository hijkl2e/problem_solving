#include <bits/stdc++.h>

using namespace std;

deque<string> readline() {
	deque<string> ret;
	string S;
	getline(cin, S);
	istringstream iss(S);
	while (iss >> S) {
		ret.push_back(S);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<deque<string>> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = readline();
	}
	deque<string> B = readline();
	while (B.size()) {
		bool flag = false;
		for (int i = 0; i < N; ++i) {
			if (A[i].size() && A[i].front() == B.front()) {
				A[i].pop_front();
				B.pop_front();
				flag = true;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	bool flag = B.empty();
	for (int i = 0; i < N; ++i) {
		flag &= A[i].empty();
	}
	cout << (flag ? "Possible" : "Impossible") << "\n";
	return 0;
}
