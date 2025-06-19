#include <iostream>
#include <fstream>
#include <string>
using namespace std;    

class Login_Page {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signup();
    void forgotPassword();
};
int main() {
    char choice;
    cout << "\n1- Log-In";
    cout << "\n2- Sin-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\n Enter your Choice: :-> ";
    cin >> choice;
    cin.ignore(); // To ignore the newline character left in the input buffer

    switch (choice) {
        case '1': {
            Login_Page loginPage;
            loginPage.login();
            break;
        }
        case '2': {
            Login_Page loginPage;
            loginPage.signup();
            break;
        }
        case '3': {
            Login_Page loginPage;
            loginPage.forgotPassword();
            break;
        }
        case '4': {
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        }
        default:
            cout << "Invalid input" << endl << "Please Enter a valid Input";
            break;
    }
}
void Login_Page::signup() {
    cout << "\nEnter Your User Name::--> ";
    getline(cin, userName);
    cout << "Enter Your Email Address::--> ";
    getline(cin, Email);
    cout << "Enter Your Password::--> ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}
void Login_Page::login() {
    cout << "-------------LOGIN---------------" << endl;
    cout << "Enter Your User Name ::" << endl;
    getline(cin, searchName);
    cout << "Enter Your Password :: " << endl;
    getline(cin, searchPass);
    
    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');

    while (!file.eof()) {
        if (userName == searchName) {
            if (password == searchPass) {
                cout << "\nAccount login Successfully.....!" << endl;
                cout << "\nusername ::  " << userName << endl;
                cout << "\nEmail :: " << Email << endl;
                file.close();
                return; // Exit after successful login
            } else {
                cout << "Password is incorrect..............!" << endl;
                file.close();
                return; // Exit after failed login
            }
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    file.close();
}

void Login_Page::forgotPassword() {
    cout << "-------------FORGOT PASSWORD---------------" << endl;
    cout << "Enter Your User Name ::" << endl;
    getline(cin, searchName);
    cout << "Enter Your Email Address :: " << endl;
    getline(cin, searchEmail);
    
    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');

    while (!file.eof()) {
        if (userName == searchName && Email == searchEmail) {
            cout << "\nYour Password is: " << password << endl;
            file.close();
            return; // Exit after successful password retrieval
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    cout << "User not found or email does not match." << endl;
    file.close();
    // Exit after failed password retrieval
}
// The code implements a simple login system with options for login, signup, and password retrieval.