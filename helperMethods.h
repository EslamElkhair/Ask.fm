#ifndef HELPERMETHODS_H_
#define HELPERMETHODS_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<vector>
#include<string>
#include<map>
using namespace std;

//Login Logout Helper methods
int read_menu_choice(int low, int high) {

	cout << "\nEnter choice in range (" << low << " - " << high << ") : ";
	int choice;
	cin >> choice;

	if (cin.fail())
		return 0;

	if (low <= choice && choice <= high)
		return choice;

	cout << "\nERROR: Invalid choice. Try again\n";

	return read_menu_choice(low, high);
}
int show_menu_choices(vector<string> menu_choices) {

	cout << "\nMenu Choices :\n";
	for (int i = 0; i < (int) menu_choices.size(); ++i) {
		cout << "\n\t" << i + 1 << "- " << menu_choices[i] << "\n";
	}

	return read_menu_choice(1, menu_choices.size());
}
bool compare_confirmed_password(string &p1, string &p2) {
	return p1 == p2;
}

//Database (File reading/writing) helper methods
vector<string> read_file_lines(string path) {
	vector<string> lines;

	fstream file_handler(path.c_str());

	if (file_handler.fail()) {
		cout << "\nERROR: can't open the file\n";
		return lines;
	}
	string line;

	while (getline(file_handler, line)) {

		if (line.size() == 0)
			continue;

		lines.push_back(line);
	}

	file_handler.close();
	return lines;
}
void write_file_lines(string path, vector<string> lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// overwrite

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}
	for (auto line : lines)
		file_handler << line << "\n";

	file_handler.close();

}

vector<string> SplitString(string s, string delimiter = ",") {
	vector<string> strs;

	int pos = 0;
	string substr;
	while ((pos = (int) s.find(delimiter)) != -1) {
		substr = s.substr(0, pos);
		strs.push_back(substr);
		s.erase(0, pos + delimiter.length());
	}
	strs.push_back(s);
	return strs;
}

int inFile_str_to_int(string str) {
	istringstream iss(str);

	int num;
	iss >> num;

	return num;
}
int inFile_str_to_char(string str) {
	istringstream iss(str);

	char status;
	iss >> status;

	return status;
}


#endif




