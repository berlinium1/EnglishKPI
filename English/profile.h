#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Profile
{
	char nickname[100]; // for nickname
	float score; // points
	int level;

	void print()
	{
		cout << "nickname = " << nickname << endl;
		cout << "score = " << score << endl;
		cout << "level = " << level << endl;
		cout << "======================================\n";
	}
};

vector<Profile> read_users(string path); // read all users at the beginning
void write_user(string path, vector<Profile>&, Profile); // write one new user
