#include <iostream>
#include "Human.h"
#include "Phonebook.h"
using namespace std;

int main()
{
    int size = 3;
    Person* persons = new Person[size];
    persons[0] = Person("Anlie Jams", "+380964356464", "+120723765170", "+380564521234", "Additional Info");

    PhoneBook db(persons, size);

    int choice = 0;
    while (true)
    {
    userChoice:
        cout << "What do you want to do?" << "\n";
        cout << "-------------------------------------" << "\n";
        cout << "1. See all persons" << "\n";
        cout << "2. Add person" << "\n";
        cout << "3. Delete person" << "\n";
        cout << "4. Search person by name" << "\n";
        cout << "5. Exit" << "\n";
        cout << "-------------------------------------" << "\n";

        cout << ">>> ";
        cin >> choice;

        cout << "\n";

        if (choice == 1)
        {
            char symb;
            cout << "All persons:" << "\n";
            db.Print();
            cout << "To return enter \"r\": ";
            do {
                cin >> symb;
            } while (symb != 'r');
            goto userChoice;
        }

        else if (choice == 2)
        {
            while (true) {
            userChoiceAdd:
                cout << "Select:" << "\n";
                cout << "----------------------------" << "\n";
                cout << "1. Add a new person" << "\n";
                cout << "2. Return" << "\n";
                cout << "----------------------------" << "\n";

                int ch = 0;

                cout << ">>> ";
                cin >> ch;

                if (ch == 1)
                {
                    db.AddPersonData();
                    goto userChoiceAdd;
                }
                else if (ch == 2) break;
                else goto userChoiceAdd;
            }
            goto userChoice;
        }

        else if (choice == 3)
        {
            while (true)
            {
            userChoiceDelete:
                cout << "Select person to delete:" << "\n";
                cout << "------------------------" << "\n";
                db.PrintNames();
                cout << db.GetSize() + 1 << ". Return" << "\n";
                cout << "------------------------" << "\n";

                int ch = 0;

                cout << ">>> ";
                cin >> ch;

                if (ch > 0 && ch < db.GetSize() + 1)
                {
                    db.DeletePerson(ch - 1);
                }
                else if (ch == db.GetSize() + 1)
                {
                    break;
                }
                else
                {
                    goto userChoiceDelete;
                }
            }
            goto userChoice;
        }

        else if (choice == 4)
        {
            char symb;
            char buff[200];
            cout << "Enter a name to search:" << "\n";
            cin.ignore();
            cout << ">>> ";
            cin.getline(buff, 200);


            cout << "Results for \"" << buff << "\": " << "\n";
            db.Search(buff);

            cout << "To return enter \"r\": ";
            do
            {
                cin >> symb;
            } while (symb != 'r');
            goto userChoice;
        }

        else if (choice == 5) break;
        else goto userChoice;
    }
    delete[] persons;
}