#include <bits/stdc++.h>

using namespace std;

map<string, int> B;

int read(string val) {
	return isdigit(val.back()) ? stoi(val) : B[val];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, vector<string>> A;
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);
		int label{};
		string cmd;
		iss >> label >> cmd;
		auto &v = A[label];
		v.push_back(cmd);
		if (cmd == "LET" || cmd == "IF") {
			while (iss >> s) {
				v.push_back(s);
			}
		} else {
			getline(iss, s);
			v.push_back(s.substr(1));
		}
	}
	map<string, function<int(int, int)>> op1{
		{"+", plus()}, {"-", minus()}, {"*", multiplies()}, {"/", divides()}
	};
	map<string, function<bool(int, int)>> op2{
		{"=", equal_to()}, {">", greater()}, {"<", less()},
		{"<>", not_equal_to()}, {"<=", less_equal()}, {">=", greater_equal()}
	};
	auto it = A.begin();
	while (it != A.end()) {
		auto &v = it->second;
		if (v[0] == "LET") {
			auto &x = B[v[1]];
			int y = read(v[3]);
			if (v.size() > 4) {
				int z = read(v[5]);
				y = op1[v[4]](y, z);
			}
			x = y;
			++it;
		} else if (v[0] == "IF") {
			int x = read(v[1]);
			int y = read(v[3]);
			if (op2[v[2]](x, y)) {
				it = A.find(stoi(v[6]));
			} else {
				++it;
			}
		} else {
			if (v[1][0] == '"') {
				cout << v[1].substr(1, v[1].size() - 2);
			} else {
				cout << B[v[1]];
			}
			if (v[0] == "PRINTLN") {
				cout << "\n";
			}
			++it;
		}
	}
	return 0;
}
