#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = filesystem;

class DirectoryParser {
private:
	int access_level;
	vector<string> materials;
	
	void parse();
	int get_lesson_number(string);
	string get_lesson_name(string);
	void choose_lesson();
public:
	DirectoryParser(int lvl) : access_level(lvl) {
		parse();
	}

	void show_material_list();
};