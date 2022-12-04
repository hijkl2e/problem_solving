#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S)) {
		istringstream iss(S);
		vector<string> A;
		while (iss >> S) {
			A.push_back(S);
		}
		double sum{};
		int cnt{};
		for (auto &s : A) {
			if (isdigit(s[0])) {
				sum += stod(s);
				++cnt;
			}
		}
		double avg = sum / cnt;
		cout << fixed << setprecision(10) << avg;
		for (auto &s : A) {
			if (isalpha(s[0])) {
				cout << " " << s;
			}
		}
		cout << "\n";
	}
	return 0;
}
