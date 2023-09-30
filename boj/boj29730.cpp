#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<int> A;
	vector<string> B;
	while (N--) {
		string s;
		getline(cin, s);
		if (s.size() > 7 && s.substr(0, 7) == "boj.kr/") {
			int x = stoi(s.substr(7));
			A.push_back(x);
		} else {
			B.push_back(s);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), [](string &s1, string &s2) {
		return s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2);
	});
	for (auto &s : B) {
		cout << s << "\n";
	}
	for (int x : A) {
		cout << "boj.kr/" << x << "\n";
	}
	return 0;
}
