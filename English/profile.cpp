#include "profile.h"

vector<Profile> read_users(string path)
{
	vector<Profile> users;
	ifstream fin;
	fin.open(path, ios::binary);

	if (!fin.is_open())
	{
		cout << "Unable to open the file!" << endl;
	}
	else
	{
		Profile temp;
		while (fin.read((char*)&temp, sizeof(Profile)))
		{
			users.push_back(temp);
		}
	}
	fin.close();
	return users;
}

void write_user(string path, vector<Profile>& users, Profile newProfile)
{
	ofstream fout;
	fout.open(path, ios::app | ios::binary);

	if (!fout.is_open())
	{
		cout << "Unable to open the file!" << endl;
	}
	else
	{
		fout.write((char*)&newProfile, sizeof(newProfile));
		users.push_back(newProfile);
	}
	fout.close();
}
