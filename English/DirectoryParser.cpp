#include "DirectoryParser.h"
#include "Theory.h"
extern vector<Profile> users;

void DirectoryParser::parse() {
    string path = fs::current_path().string() + "\\Data",
        line, path_file, material;
    for (const auto& entry : filesystem::directory_iterator(path)) {		//iterating the files in directory
        path_file = entry.path().string();
        material = path_file.substr(path_file.rfind(char(92)) + 1, path_file.length());
        materials.push_back(material);
    }
}

void DirectoryParser::show_material_list(Profile& user) {
    int min = 0;
    access_level = user.level;
    int max = access_level > materials.size() ? materials.size() : access_level;
    size_t num = 0;
    bool input = true;
    string choice;
    // "[-1] Exit\n" << "[" << min << "-" << max - 1 << "]
    cout << "Choose lesson" << endl;
    while (num <= max) {
        cout << get_lesson_number(materials[num]) - 1 << " - " << get_lesson_name(materials[num]) << endl;
        num++;
    }

    do {
        cout << "Choice: ";
        input = true;
        cin >> choice;
        if (cin.fail() || stoi(choice) < -1 || stoi(choice) > max) {
            input = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please, try again.\n";
        }
    } while (!input);
    system("cls");
    if (choice == "-1") {
        update_file(std::filesystem::current_path().string() + "\\NEWDATA.dat", users);
        exit(1);
    }
    else {
        Theory lesson_instance(fs::current_path().string() + "\\Data\\" + materials[stoi(choice)]);
        lesson_instance.set_level(stoi(choice));
        lesson_instance.show_theory();
        lesson_instance.show_tests(user);
    }

}

int DirectoryParser::get_lesson_number(string filename) {
    int actual_num = 0;
    for (size_t i = 1; i < filename.length(); i++) {
        if (filename[i] == ']') break;
        actual_num *= 10;
        actual_num += filename[i] - 48;
    }
    return actual_num;
}

string DirectoryParser::get_lesson_name(string filename) {
    string actual_name;
    bool passed_bracket = false;
    for (size_t i = 0; i < filename.length(); i++) {
        if (filename[i] == '.') break;
        if (passed_bracket) actual_name += filename[i];
        if (filename[i] == ']') passed_bracket = true;
    }
    return actual_name;
}