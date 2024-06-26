#include <iostream>
#include <string>
#include <vector> // I'm actually new to these. I was gonna use classes or structs
using namespace std;

vector<string> Names;
vector<string> Phones;

void addContact();
void searchByID();
void searchByName();
void searchByPhone();
void showAllContacts();


int main()
{
    int selection = 0;

    while(true)
    {
        cout << "My Agenda++\n\n";

        cout << "Choose a number to execute an option \n\n"
        << "1: New Contact\n"
        << "2: Locate By ID\n"
        << "3: Located By Number\n"
        << "4: Exit"
        << endl;

        cout << "Your choice?: ";
        cin >> selection;

        if(selection < 1 || selection > 5)
        {
            cout << "It seems you selected an invalid option, try again" << endl;
            main();
        }
        switch(selection)
        {
            case 1: cout << "you've chosen to add a contact\n";
                addContact();
                break;
            case 2: searchByName();
                break;
            case 3: searchByPhone();
                break;
            case 4: searchByID();
                break;
            case 5: cout << "Goodbye...\n";
                return 0;
        }
    }
}

void addContact()
{
    string name;
    string phone;
    cout << "Enter new contact name: " << endl;
    cin >> name;
    cout << "Enter new contact number: " << endl;
    cin >> phone;

    cout << "you've added " << name << "'s contacts\n"
    << "Their ID is " << Names.size() <<endl;

    Names.push_back(name);
    Phones.push_back(phone);
}

void searchByID()
{
    int index;

    cout << "Enter the ID of the contact you want to find" << endl;
    cin >> index;

    if(index >= Names.size())
    {
        cout << "This number does exist, please start over";
        return;
    }

    cout << "Contact: " << index << ":"
    << "\nName: " << Names[index] << "\tPhone: " << Phones[index] << endl;
}

void searchByName()
{
    string name_given;
    string name_found;

    cout << "Enter the name of the contact you want to find" << endl;
    cin >> name_given;

    for(int i = 0; i < Names.size(); i++)
    {
        if(Names[i] == name_given)
            name_found = Names[i];
        cout << name_given << "; ID = " << i << " phone: " << Phones[i] << endl;
        return;
    }

    cout << "name_not_found" << endl;


}

void searchByPhone()
{
    string phone_given;
    string phone_found;

    cout << "Enter the phone of the contact you want to find" << endl;
    cin >> phone_given;

    for(int i = 0; i < Names.size(); i++)
    {
        if(Phones[i] == phone_given)
            phone_found = Phones[i];
        cout << phone_given << "; ID = " << i << " name: " << Names[i] << endl;
        return;
    }

    cout << "phone_not_found" << endl;


}

void showAllContacts()
{
    cout
    << "ID\t" << "Name\t" << "Phone\t" << endl;
    cout << "______________________________________________" << endl;

    for( int i = 0; i < Names.size(); i++)
    {
        cout
        << i << "\t" << Names[i] << "\t" << Phones[i] << "\t" << endl;
    }
}


