#include <iostream>
#include <string>
using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    float gpa;
};


string standing(float gpa) {
    if (gpa >= 90) return "Excellent";
    else if (gpa >= 80) return "Very Good";
    else if (gpa >= 70) return "Good";
    else if (gpa >= 60) return "Passing";
    else return "Failed";
}

bool existingID(student s[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (s[i].studentID == id) {
            return true;
        }
    }
    return false;
}


int main() {
    char choice;

    do {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        student s[100];

        for (int i = 0; i < n; i++) {
            cout << "\nStudent " << i + 1 << ":\n";

            int id;
            while (true) {
                cout << "Enter Student ID (numbers only): ";
                cin >> id;

                if (existingID(s, i, id)) {
                    cout << "ID already exists!\n";
                } else {
                    s[i].studentID = id;
                    break;
                }
            }
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, s[i].name);

            cout << "Enter Course: ";
            getline(cin, s[i].course);


            do {
                cout << "Enter GPA (0-100): ";
                cin >> s[i].gpa;

                if (s[i].gpa < 0 || s[i].gpa > 100) {
                    cout << "Invalid GPA (input 0-100)\n";
                }

            } while (s[i].gpa < 0 || s[i].gpa > 100);
        }

        cout << "\n\nStudent ID\t\tName\t\tCourse\t\tGPA\tAcademic Standing\n";
        cout << "----------------------------------------------------------------------------------\n";

        for (int i = 0; i < n; i++) {
            cout << s[i].studentID << "\t\t"
                 << s[i].name << "\t\t"
                 << s[i].course << "\t\t"
                 << s[i].gpa << "\t"
                 << standing(s[i].gpa) << endl;
        }

        cout << "\nRun the program again?[Y/N]: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
