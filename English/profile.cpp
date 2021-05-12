//
//  profile.cpp
//  English
//
//  Created by Берлинский Ярослав Владленович on 12.05.2021.
//

#include "Profile.h"

void Profile::print()
{
    cout << "nickname = " << nickname << endl;
    cout << "score = " << score << endl;
    cout << "level = " << level << endl;
    cout << "======================================\n";
}

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
        fout.write((char*)&newProfile, sizeof(Profile));
        users.push_back(newProfile);
    }
    fout.close();
}

void update_file(string path, vector<Profile>& users)
{
    ofstream fout;
    fout.open(path, ios::binary);

    if (!fout.is_open())
    {
        cout << "Unable to open the file!" << endl;
    }
    else
    {
        for (int i = 0; i < users.size(); i++)
        {
            fout.write((char*)&users[0], sizeof(Profile));
        }
    }
    fout.close();
}
