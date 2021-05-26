#include "Material.h"
#include "profile.h"
#include <filesystem>
extern vector<Profile> users;

void Material::show_material()
{
	int choice;
    bool input;

	system("cls");
	cout << text << endl;
    cout << "[0] - exit\n[1] - start the test" << endl;

    do
    {
        cout << "Choice: ";

        input = true;
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 1)
        {
            input = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please, try again.\n";
        }
    } while (!input);

    if (choice == 0) {
        update_file(std::filesystem::current_path().string() + "\\NEWDATA.dat", users);
        exit(0);
    }
    else {
        test.show();
    }
}