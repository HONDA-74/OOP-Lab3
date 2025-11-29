#include <iostream>
#include <array>
#include <conio.h>
using namespace std;

int main() {
    //task1
    array<string, 4> arr = {"New", "Display", "Display All", "Exit"};
    int highlight = 0;
    int key;

    while (true) {
        system("cls");
        cout << "Use up and down to move, and Enter to select:\n\n";

        for (int i = 0; i < arr.size(); i++) {
            if (i == highlight) {
                cout << "\033[1;31m> " << arr[i] << "\033[0m" << endl;
            } else {
                cout << "  " << arr[i] << endl;
            }
        }

        key = getch();

        if (key == 224) {
            key = getch();
            if (key == 72) {// up
                highlight--;
                if (highlight < 0) highlight = arr.size() - 1;
            } else if (key == 80) {//down
                highlight++;
                if (highlight >= arr.size()) highlight = 0;
            }
        } else if (key == 13) {//enter
            system("cls");
            cout << "You selected: " << arr[highlight] << endl;
            if (arr[highlight] == "Exit")
                break;
            key = getch();
            if(key == 27){
                continue;
            }
        }
        else if (key == 27) {//esc
            system("cls");
            cout << "Exiting menu...\n";
            break;
        }
    }



    //task2
    struct Subject {
        string name;
        double grade;
    };

    struct Student {
        string name;
        array<Subject, 3> subjects;
    };

    array<Student, 3> students;
    array<double, 3> totalPerSubject = {0};

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter student " << (i + 1) << " name: ";
        cin >> students[i].name;
        for (int j = 1; j <= 3; j++) {
            if (j == 1) students[i].subjects[0].name = "cs";
            else if (j == 2) students[i].subjects[1].name = "it";
            else if (j == 3) students[i].subjects[2].name = "is";
        cout << "Enter grade for " << students[i].subjects[j - 1].name << ": ";
        cin >> students[i].subjects[j - 1].grade;
        }
    }

    cout << "\nStudent Grades:\n";
    cout << "-------------------------------------\n";
    cout << "Name\tcs\tit\tis\tSum\n";
    for (auto student : students) {
        double sum = 0;
        cout << student.name << "\t";
        for (int j = 0; j < 3; j++) {
            cout << student.subjects[j].grade << "\t";
            sum += student.subjects[j].grade;
            totalPerSubject[j] += student.subjects[j].grade;
        }
        cout << sum << "\n";
    }
    cout << "Average\t";
    for (int j = 0; j < 3; j++) {
        double avg = totalPerSubject[j] / 3;
        cout << avg << "\t";
    }
    cout << "\n";



    //task3
    struct Employee {
        int id;
        string name;
        int age;
        double salary;
    };

    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    system("cls");
    array<Employee, 10> employees;
    int counter = 0 ;
    for (int i = 0; i < n; i++) {
        if(i) counter+=4 ;
        cout << "\033[1;20H" << "Epmloyee " << (i+1) <<" : \n" ;
        cout << "\033["<<2 + counter<<";20H" << "ID   : \n";
        cout << "\033["<<3 + counter<<";20H" << "Name : \n" ;
        cout << "\033["<<2 + counter<<";40H" << "Age  : \n";
        cout << "\033["<<3 + counter<<";40H" << "Salary: \n";

        cout << "\033["<<2 + counter<<";28H";
        cin >> employees[i].id;

        cout << "\033["<<3 + counter<<";28H";
        cin >> employees[i].name;

        cout << "\033["<<2 + counter<<";48H";
        cin >> employees[i].age;

        cout << "\033["<<3 + counter<<";48H";
        cin >> employees[i].salary;
    }

    cout << "\n\n" ;
    cout << "--- Employee List ---\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << employees[i].id
            << " | Name: " << employees[i].name
            << " | Age: " << employees[i].age
            << " | Salary: " << employees[i].salary << endl;
    }

    return 0;
}
