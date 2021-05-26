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



void Profile::setUserData(string nickname, string password){
    for (int i = 0; i <= nickname.size(); i++) this->nickname[i] = nickname[i];
    for (int i = 0; i <= password.size(); i++) this->password[i] = password[i];
}

void Profile::getUserData(string& nickname, string& password)
{
    int i = 0;
    while (this->nickname[i] != '\0')
    {
        nickname.push_back(this->nickname[i]);
        i++;
    }
    i = 0;

    while (this->password[i] != '\0')
    {
        password.push_back(this->password[i]);
        i++;
    }
}

void Profile::setScore(float score){
    this->score += score;
    if (score) (this->level)++;
}

float Profile::getScore(){
    return score;
}


void Teacher::getUserProfile(int index){
    cout << "\n=== Profile № "<<index<<" ===\n";
    users[index].print();
}
void Teacher::seeAllProfiles(){
    int choice;
    cout << "\n=== Profiles ===\n";
    for (int i = 0; i < users.size(); i++) {
        cout << "User[" << i + 1 << "] " << users[i].nickname << endl;
    }
    do {
        cout << "Choose one to show(№ in list): "; cin >> choice;
        if (choice >= 1 && choice <= users.size()) {
            getUserProfile(choice-1);
        }
        else if (choice != 0) cout << "There is no user beneath the №" << choice << endl;
        
    } while (choice != 0);
}

// в поле аргументов можно убрать путь, т.к. мы всё равно с стд::филэсустем
void Teacher::createLesson(string path){
    bool flag = 0;
    vector<char> rightAnswers;
    string title, paragraph, task, variant;
    int numberOfExercises, numberOfVariants;
    char variants[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    cout << "\nHey! Welcome to The Lesson Master\nEnter a title: \n"; getline(cin, title);
    ofstream newLesson(path + "/" + title + ".txt"); // тут путь можно поменять(я для теста оставил)
    newLesson << "%" << title << endl;
    cout << "\nWell! Let's fill the main part. Write in the paragraph, then press \"Enter\" to write another paragraph.\nP.S. if you want to leave The Lesson Master, you must enter the 'stop'\n";
    do {
        getline(cin, paragraph);
        if (paragraph != "stop") {
            newLesson << paragraph << endl;
        }
    } while (paragraph != "stop");
    cout << "Well! Let's create a test. Enter a number of exsercises: "; cin >> numberOfExercises;
    newLesson << "#TEST" << endl;
    for (int i = 0; i < numberOfExercises; i++) {
        cout << "Enter a task: \n"; getline(cin.ignore(), task);
        newLesson << "#" << to_string(i+1) << ". " << task << endl;
        do {
            cout << "Enter a number of variants(maximum 6): "; cin >> numberOfVariants;
        } while (numberOfVariants > 6);
        for (int j = 0; j < numberOfVariants; j++) {
            cout << "Enter a variant " << variants[j] << "): "; getline(cin.ignore(), variant);
            newLesson << variants[j] << ") " << variant << endl;
        }
        cout << "Give the right answer: "; char ch; cin >> ch; rightAnswers.push_back(ch);
    }
    newLesson << "#RIGHT ANSWERS\n";
    for (int i = 0; i < rightAnswers.size(); i++) {
        newLesson << rightAnswers[i];
    }
    newLesson.close();
    
}


Teacher::Teacher(){
    users = read_users(std::__fs::filesystem::current_path().string() + "\\NEWDATA.dat");
}

void Teacher::teacherInterface(){
    char choice;
    do{
        cout << "\nChoose what to do:\n0. Exit\n1. See user profiles\n2. Add new material to the system\nYour coice: "; cin >> choice;
        switch (choice) {
            case '1':
                if (users.size() == 0) cout << "Empty. There's no user\n";
                else seeAllProfiles();
                break;
            case '2':{
                string path; char ch;
                do {
                    createLesson(path); // с путём нужно разобраться
                    cout << "\nDo you want to add another one lesson?\nNo - 0\nYes - 1\nYour choice: "; cin >> ch;
                } while (ch = '1');
            }
            default:
                break;
        }
    }while(choice != '0');
}
