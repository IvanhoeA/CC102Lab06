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

void input(student s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";

        int id;
        bool duplicate;

        do {
            duplicate = false;
            cout << "Enter Student ID: ";
            cin >> id;

            for (int j = 0; j < i; j++) {
                if (s[j].studentID == id) {
                    cout << "ID already exists!\n";
                    duplicate = true;
                }
            }
        } while (duplicate);

        s[i].studentID = id;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, s[i].name);

        cout << "Enter Course: ";
        getline(cin, s[i].course);

        do {
            cout << "Enter GPA (0-100): ";
            cin >> s[i].gpa;

            if (s[i].gpa < 0 || s[i].gpa > 100) {
                cout << "Invalid GPA!\n";
            }

        } while (s[i].gpa < 0 || s[i].gpa > 100);
    }
}

void display(student s[], int n) {
    cout << "\n\nStudent ID\tName\t\tCourse\t\tGPA\tAcademic Standing\n";
    cout << "--------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << s[i].studentID << "\t\t"
             << s[i].name << "\t\t"
             << s[i].course << "\t\t"
             << s[i].gpa << "\t"
             << standing(s[i].gpa) << endl;
    }
}

int main() {
    char choice;

    do {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        student obj[100];

        input(obj, n);
        display(obj, n);

        cout << "\nRun again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
