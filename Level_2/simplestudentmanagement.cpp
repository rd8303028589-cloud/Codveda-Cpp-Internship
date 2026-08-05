#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student
{
    int id;
    char name[50];
    float grade;
};

const int MAX = 100;
Student students[MAX];
int total = 0;

// Load data from file
void loadFromFile()
{
    ifstream file("students.dat", ios::binary);

    if (!file)
        return;

    while (file.read((char *)&students[total], sizeof(Student)))
    {
        total++;
    }

    file.close();
}

// Save data to file
void saveToFile()
{
    ofstream file("students.dat", ios::binary);

    for (int i = 0; i < total; i++)
    {
        file.write((char *)&students[i], sizeof(Student));
    }

    file.close();
}

// Add Student
void addStudent()
{
    if (total >= MAX)
    {
        cout << "\nMemory Full!\n";
        return;
    }

    Student *ptr = &students[total];

    cout << "\nEnter Student ID: ";
    cin >> ptr->id;

    cin.ignore();

    cout << "Enter Student Name: ";
    cin.getline(ptr->name, 50);

    cout << "Enter Student Grade: ";
    cin >> ptr->grade;

    total++;

    saveToFile();

    cout << "\nStudent Added Successfully.\n";
}

// Display Students
void displayStudents()
{
    if (total == 0)
    {
        cout << "\nNo Record Found.\n";
        return;
    }

    cout << "\n----- Student Records -----\n";

    for (int i = 0; i < total; i++)
    {
        Student *ptr = &students[i];

        cout << "\nID    : " << ptr->id;
        cout << "\nName  : " << ptr->name;
        cout << "\nGrade : " << ptr->grade;
        cout << "\n-------------------------";
    }
}

// Search Student
void searchStudent()
{
    int id;
    cout << "\nEnter Student ID: ";
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        Student *ptr = &students[i];

        if (ptr->id == id)
        {
            cout << "\nRecord Found\n";

            cout << "ID    : " << ptr->id << endl;
            cout << "Name  : " << ptr->name << endl;
            cout << "Grade : " << ptr->grade << endl;

            return;
        }
    }

    cout << "\nStudent Not Found.\n";
}

// Update Student
void updateStudent()
{
    int id;

    cout << "\nEnter Student ID: ";
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        Student *ptr = &students[i];

        if (ptr->id == id)
        {
            cin.ignore();

            cout << "Enter New Name: ";
            cin.getline(ptr->name, 50);

            cout << "Enter New Grade: ";
            cin >> ptr->grade;

            saveToFile();

            cout << "\nRecord Updated Successfully.\n";
            return;
        }
    }

    cout << "\nStudent Not Found.\n";
}

// Delete Student
void deleteStudent()
{
    int id;

    cout << "\nEnter Student ID: ";
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if (students[i].id == id)
        {
            for (int j = i; j < total - 1; j++)
            {
                students[j] = students[j + 1];
            }

            total--;

            saveToFile();

            cout << "\nRecord Deleted Successfully.\n";
            return;
        }
    }

    cout << "\nStudent Not Found.\n";
}

int main()
{
    loadFromFile();

    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n Student Management System";
        cout << "\n==============================";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}