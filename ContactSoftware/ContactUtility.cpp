#include "ContactUtility.h"

// Takes Contact pointers and sorts them based on m_name attribute
// This uses a lambda function to compare Contacts
void ContactUtility::sortContacts(std::vector<Contact*>& contacts) {

    std::sort(contacts.begin(),
              contacts.end(),
              [] (Contact *a, Contact *b) { return *a->m_name < *b->m_name; });
}

// Creates new contact for the vector
void ContactUtility::addContact(std::vector<Contact*>& contacts) {

    std::string name;
    int age;
    std::cout << "\n**Adding Contact**\n";
    std::cout << "Contact name: ";
    std::cin >> name;
    std::cout << "Contact age: ";
    std::cin >> age;

    contacts.push_back(new Contact {new std::string(name) , age});
}

// Calls sortContacts function
// Properly formats the contacts by name and age
void ContactUtility::printContacts(std::vector<Contact*>& contacts) {

    sortContacts(contacts);

    std::cout << "\n**Printing Sorted Contacts**\n";
    for (const auto& contact : contacts) {
        std::cout << "Name: " << *contact->m_name << ", Age: " << contact->m_age << "\n";
    }
}

// Asks users for the Contact that wants to add another Contact
// Asks user which Contacts they would like to add
void ContactUtility::addFriend(std::vector<Contact*>& contacts) {

    std::cout << "Contact that wants to add: ";
    Contact* conAPtr { findContact(contacts) };
    if (!conAPtr) return;

    std::cout << "Who would " << *conAPtr->m_name << " like to add?: ";
    Contact* conFPtr { findContact(contacts) };
    if (!conFPtr) return;

    conAPtr->addFriend(conFPtr);
}

// conCPtr declares a pointer to an object of type Contact
// Prompts the user to input the name of a contact
// And then prints the list of friends for that contact
void ContactUtility::printFriends(std::vector<Contact*>& contacts) {

    std::cout << "Enter the name of the contact whose friend list you want to view: ";
    Contact* conCPtr { findContact(contacts) };
    if (!conCPtr) return;

    if (conCPtr->m_friends.empty())
        std::cout << *conCPtr->m_name << " has no friends.\n";
    else {
        std::cout << "\n**Friends of " << *conCPtr->m_name << "**\n";
        for (const auto& friendContact : conCPtr->m_friends) {
            std::cout << "   - " << *friendContact->m_name << "\n";
        }
    }
}

// Removes the contact from the friend lists of all other contacts
// Deletes the contact from the contacts vector, and cleans up the memory
void ContactUtility::deleteContact(std::vector<Contact*>& contacts) {

    std::cout << "Which contact would you like to delete?: ";
    Contact* conDPtr { findContact(contacts) };
    if (!conDPtr) return;

    std::cout << "Removing from friend lists...\n";
    std::for_each(contacts.begin(),
                  contacts.end(),
                  [&conDPtr](Contact *c){
        c->removeFriend(*conDPtr->m_name);
    });

    std::cout << "Removing from Contacts...\n";
    contacts.erase(std::remove_if(contacts.begin(),
                                  contacts.end(),
                                   [&conDPtr](Contact* c) { return c == conDPtr; }),
                   contacts.end());

    // Memory clean up.
    delete conDPtr->m_name;
    conDPtr->m_name = nullptr;
    delete conDPtr;
    conDPtr = nullptr;

    std::cout << "Contact deleted.\n";
}

Contact* ContactUtility::findContact(std::vector<Contact*>& contacts) {

    // Helper function to find contacts
    std::string conCheck;
    std::cin >> conCheck;
    auto it = std::find_if(contacts.begin(),
                           contacts.end(),
                           [&conCheck] (Contact *c) { return *c->m_name == conCheck;});

    if (it != std::end(contacts))
        return contacts.at(std::distance(contacts.begin(), it));

    std::cout << "Contact not found. Returning to main menu...\n";
    return nullptr;
}
