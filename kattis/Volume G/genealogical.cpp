#include <bits/stdc++.h>

using namespace std;

vector<string> name(250);
vector<string> birth(250);
vector<string> death(250);
vector<vector<int>> anc(250);
vector<vector<int>> des(250);

void print(int x, int space) {
	cout << string(space, ' ') << name[x];
	if (birth[x].size()) {
		cout << " " << birth[x] << " -";
	}
	if (death[x].size()) {
		cout << " " << death[x];
	}
	cout << "\n";
}

void ancestor(int x, int space) {
	sort(anc[x].begin(), anc[x].end(), [](int a, int b) {
		return name[a] < name[b];
	});
	for (int y : anc[x]) {
		print(y, space);
		ancestor(y, space + 2);
	}
}

void descendant(int x, int space) {
	sort(des[x].begin(), des[x].end(), [](int a, int b) {
		return name[a] < name[b];
	});
	for (int y : des[x]) {
		print(y, space);
		descendant(y, space + 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> n2i;
	string cmd;
	bool newline{};
	while (cin >> cmd, cmd != "QUIT") {
		cin.ignore();
		string S;
		getline(cin, S);
		if (cmd == "BIRTH") {
			istringstream iss(S);
			string child, date, mother, father;
			getline(iss, child, ':');
			getline(iss, date, ':');
			getline(iss, mother, ':');
			getline(iss, father);
			child = child.substr(0, child.size() - 1);
			date = date.substr(1, date.size() - 2);
			mother = mother.substr(1, mother.size() - 2);
			father = father.substr(1);
			int cidx = n2i.insert({child, n2i.size()}).first->second;
			int midx = n2i.insert({mother, n2i.size()}).first->second;
			int fidx = n2i.insert({father, n2i.size()}).first->second;
			name[cidx] = child;
			name[midx] = mother;
			name[fidx] = father;
			birth[cidx] = date;
			anc[cidx].push_back(midx);
			anc[cidx].push_back(fidx);
			des[midx].push_back(cidx);
			des[fidx].push_back(cidx);
		} else if (cmd == "DEATH") {
			istringstream iss(S);
			string pers, date;
			getline(iss, pers, ':');
			getline(iss, date);
			pers = pers.substr(0, pers.size() - 1);
			date = date.substr(1);
			death[n2i[pers]] = date;
		} else {
			string pers = S;
			if (newline) {
				cout << "\n";
			}
			newline = true;
			if (cmd == "ANCESTORS") {
				cout << "ANCESTORS of " << pers << "\n";
				ancestor(n2i[pers], 2);
			} else {
				cout << "DESCENDANTS of " << pers << "\n";
				descendant(n2i[pers], 2);
			}
		}
	}
	return 0;
}
