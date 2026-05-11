#include <iostream>
#include "studentBST.h"

using namespace std;

bool validStudentId(int id)
{
    return id >= 1000; // minimum 4 digits
}

int main()
{
    StudentBST sbst;
    int choice;

    while (true)
    {
        cout << "\n===== STUDENT BST MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 0)
            break;

        // ---------------- ADD STUDENT ----------------
        if (choice == 1)
        {
            int id;
            string name, dept;

            while (true)
            {
                cout << "Enter ID (min 4 digits): ";
                cin >> id;

                if (!validStudentId(id))
                {
                    cout << "Invalid ID. Try again.\n";
                }
                else if (sbst.exists(id))
                {
                    cout << "Error: ID already exists.\n";
                }
                else
                {
                    break;
                }
            }

            cout << "Enter Name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter Dept: ";
            getline(cin, dept);

            sbst.insert(id, name, dept);
            cout << "Student added successfully.\n";
        }

        // ---------------- SEARCH STUDENT ----------------
        else if (choice == 2)
        {
            int id;
            cout << "Enter Student ID: ";
            cin >> id;

            if (!validStudentId(id))
            {
                cout << "Invalid ID.\n";
                continue;
            }

            sbst.search(id);
        }

        // ---------------- DISPLAY ALL ----------------
        else if (choice == 3)
        {
            sbst.display();
        }

        else
        {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Program ended.\n";
    return 0;
}
