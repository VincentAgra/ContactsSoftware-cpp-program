<!DOCTYPE html>
<html>
<body>
  <h1>C++ Contacts Manager</h1>
  
  <p>A simple yet powerful contacts management program built in C++ that provides all the essential features of a phone contacts application.</p>
  
  <h2>Features</h2>
  <ul>
    <li><strong>Add Contacts</strong> - Store names, phone numbers, email addresses, and additional notes</li>
    <li><strong>View Contacts</strong> - Browse through your complete contact list</li>
    <li><strong>Search</strong> - Quickly find contacts by name, number, or other details</li>
    <li><strong>Edit Contacts</strong> - Update information for existing contacts</li>
    <li><strong>Delete Contacts</strong> - Remove contacts you no longer need</li>
    <li><strong>Persistent Storage</strong> - Your contacts are saved automatically</li>
    <li><strong>Categories</strong> - Organize contacts into groups (family, friends, work, etc.)</li>
  </ul>
  
  <h2>Installation</h2>
  <pre>
    
    # Clone the repository
    git clone https://github.com/yourusername/cpp-contacts-manager.git
    
    # Navigate to the project directory
    cd cpp-contacts-manager
    
    # Compile the source code
    g++ -o contacts main.cpp contact.cpp filehandler.cpp ui.cpp
    
    # Run the program
    ./contacts
  </pre>
  
  <h2>Requirements</h2>
  <ul>
    <li>C++11 or higher</li>
    <li>g++ compiler</li>
    <li>Standard C++ libraries</li>
  </ul>
  
  <h2>Usage</h2>
  <p>After launching the program, you'll be presented with a menu of options:</p>
  <pre>
    1. View All Contacts
    2. Add New Contact
    3. Search Contacts
    4. Edit Contact
    5. Delete Contact
    6. Exit
  </pre>
  
  <p>Follow the on-screen prompts to navigate through the application and manage your contacts.</p>
  
  <h2>Project Structure</h2>
  <ul>
    <li><strong>main.cpp</strong> - Program entry point and menu logic</li>
    <li><strong>contact.h/cpp</strong> - Contact class definition and methods</li>
    <li><strong>filehandler.h/cpp</strong> - File operations for saving/loading contacts</li>
    <li><strong>ui.h/cpp</strong> - User interface functions</li>
    <li><strong>contacts.dat</strong> - Data file where contacts are stored</li>
  </ul>
  
  <h2>License</h2>
  <p>This project is licensed under the MIT License - see the LICENSE file for details.</p>
  
  <h2>Contact</h2>
  <p>Your Name - <a href="mailto:your.email@example.com">your.email@example.com</a></p>
  <p>Project Link: <a href="https://github.com/yourusername/cpp-contacts-manager">https://github.com/yourusername/cpp-contacts-manager</a></p>
</body>
</html>
