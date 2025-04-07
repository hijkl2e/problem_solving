#include <bits/stdc++.h>
#include "NB.h"

using namespace std;

using ii = pair<int, int>;

vector<string> A;
map<vector<ii>, vector<string>> B;

ii solve(string &s1, string &s2) {
	int S{}, B{};
	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j]) {
				if (i == j) {
					++S;
				} else {
					++B;
				}
			}
		}
	}
	return {S, B};
}

void init(int T, int N) {
	if (N == 3) {
		A = {"984", "971", "452", "397", "605", "926", "823"};
	} else {
		A = {"2680", "6470", "8047", "7123", "9631", "1549", "0153"};
	}
	for (int i = N == 3 ? 987 : 9876; i > 0; --i) {
		string s = to_string(i);
		while (s.size() < N) {
			s = "0" + s;
		}
		bool flag = true;
		for (int j = 0; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				if (s[j] == s[k]) {
					flag = false;
				}
			}
		}
		vector<ii> C(7);
		for (int j = 0; j < 7; ++j) {
			C[j] = solve(A[j], s);
		}
		B[C].push_back(s);
	}
}

void game() {
	vector<ii> C(7);
	for (int i = 0; i < 7; ++i) {
		C[i] = guess(A[i]);
		if (C[i].first == A[i].size()) {
			return;
		}
	}
	auto &v = B[C];
	if (v.size() == 3) {
		auto [x, y] = guess(v[0]);
		if (x == 1) {
			guess(v[1]);
		} else if (x == 0) {
			guess(v[2]);
		}
	} else {
		if (guess(v[0]).first < v[0].size()) {
			guess(v[1]);
		}
	}
}
