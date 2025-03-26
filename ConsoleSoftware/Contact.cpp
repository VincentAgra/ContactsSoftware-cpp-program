#include "Contact.h"

// Constructor for the Contact class
Contact::Contact(std::string *name, int age): m_name { name }, m_age { age } { }

// Takes a pointer to a Contact object (newFriend) and adds it to m_friends vector
void Contact::addFriend(Contact* newFriend) {
    m_friends.push_back(newFriend);
    std::cout << *m_name << " is now friends with " << *newFriend->m_name << "\n";
}

// Removes a friend from the m_friends vector
void Contact::removeFriend(std::string_view friendName) {
    int preSize = m_friends.size();
    m_friends.erase(std::remove_if(m_friends.begin(),
                                   m_friends.end(),
                                   [&friendName](Contact* c) { return *c->m_name == friendName; }),
                    m_friends.end());

    if (preSize == m_friends.size())
        std::cout << *m_name << ": Friend not found\n";
    else
        std::cout << *m_name << ": Friend removed.\n";
}
