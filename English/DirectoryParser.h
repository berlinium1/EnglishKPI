#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include "profile.h"

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
	DirectoryParser(Profile& user) : access_level(user.level) {

		parse();
	}

	void show_material_list(Profile& user);
};