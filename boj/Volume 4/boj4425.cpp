#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> A;

bool solve(vector<string> &B, int n, vector<int> &_tab, vector<int> &_rtab) {
	if (n == B.size()) {
		return true;
	}
	string &s1 = B[n];
	for (auto &s2 : A[B[n].size()]) {
		bool flag{};
		for (int i = 0; i < s1.size(); ++i) {
			if (!((_tab[s1[i]] == '*' || _tab[s1[i]] == s2[i])
					&& (_rtab[s2[i]] == '*' || _rtab[s2[i]] == s1[i]))) {
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}
		vector<int> tab = _tab;
		vector<int> rtab = _rtab;
		flag = true;
		for (int i = 0; i < s1.size(); ++i) {
			if (!((tab[s1[i]] == '*' || tab[s1[i]] == s2[i])
					&& (rtab[s2[i]] == '*' || rtab[s2[i]] == s1[i]))) {
				flag = false;
				break;
			}
			tab[s1[i]] = s2[i];
			rtab[s2[i]] = s1[i];
		}
		if (flag && solve(B, n + 1, tab, rtab)) {
			_tab = tab;
			_rtab = tab;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	A.resize(17);
	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s);
		A[s.size()].push_back(s);
	}
	for (int i = 1; i < 17; ++i) {
		auto &v = A[i];
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		vector<string> nv;
		for (int j = 0; j < 2; ++j) {
			for (int k = j; k < v.size(); k += 2) {
				nv.push_back(v[k]);
			}
		}
		swap(v, nv);
	}
	string S;
	while (getline(cin, S)) {
		istringstream iss(S);
		vector<string> B;
		while (iss >> S) {
			B.push_back(S);
		}
		vector<int> tab(123, '*');
		vector<int> rtab(123, '*');
		tab[' '] = rtab[' '] = ' ';
		vector<string> C(B.begin(), B.end());
		sort(C.begin(), C.end(), [](string &s1, string &s2) {
			return s1.size() > s2.size();
		});
		solve(C, 0, tab, rtab);
		for (int i = 0; i < B.size(); ++i) {
			for (char c : B[i]) {
				c = tab[c];
				cout << c;
			}
			cout << (i == B.size() - 1 ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}
