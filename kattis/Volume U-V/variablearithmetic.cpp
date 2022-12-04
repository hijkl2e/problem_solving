#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> A;
	string S;
	while (getline(cin, S), S != "0") {
		istringstream iss(S);
		vector<string> B;
		while (iss >> S) {
			B.push_back(S);
		}
		if (B.size() > 1 && B[1] == "=") {
			A[B[0]] = stoi(B[2]);
			continue;
		}
		vector<string> C;
		int sum{};
		for (int i = 0; i < B.size(); i += 2) {
			if (isdigit(B[i][0])) {
				sum += stoi(B[i]);
				continue;
			}
			auto it = A.find(B[i]);
			if (it == A.end()) {
				C.push_back(B[i]);
			} else {
				sum += it->second;
			}
		}
		if (sum || C.empty()) {
			C.insert(C.begin(), to_string(sum));
		}
		for (int i = 0; i < C.size(); ++i) {
			cout << C[i] << (i == C.size() - 1 ? "\n" : " + ");
		}
	}
	return 0;
}
