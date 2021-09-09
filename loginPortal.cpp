#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
class File
{
    string username, password;

public:
    void setData();
    void getData();
    bool checkData();
    void frdData();
};
void File::getData()
{
    ifstream in("login_control.txt"); //reading files
    in >> username;
    in >> password;
    
}
bool File::checkData()
{
    getData();
    if(username == "" && password == ""){
        cout << "please set your login redential first\nThank You\n";
        return false;
    }
    string u_name, pass;
    cout << "USERNAME as saved earlier: ";
    cin.ignore();
    cin >> u_name;
    cout << "Password as saved earlier: ";
    cin.ignore();
    cin >> pass;
    if (u_name == username && pass == password)
    {
        return true;
    }
    return false;
}
void File::frdData()
{
    ofstream out("login_control.txt"); //Writing files
    string u_name, pass;
    cout << "Give username without any space and press enter after done: ";
    cin.ignore();
    cin >> u_name;
    cout << "Give password without any space and press enter after done: ";
    cin.ignore();
    cin >> pass;
    out << u_name;
    out << '\n';
    out << pass;
    cout << "Credentials saved successfully\n";
}
void File::setData()
{
    getData();
    ofstream out("login_control.txt"); //Writing files
    if (username == "" && password == "")
    {
        cout << "This is your first time welcome to our login portal\n";
        frdData();
    }
    else if(checkData()){
        cout << "You can change your credential as your old credentials match\n";
        frdData();
    }
    else{
        cout << "Sorry you are not verified old credentials are not matching\n";
    }
}
int main()
{
    File fe;
    cout <<"Menus:\n1:Set or update credentials\n2:login\n3:exit\n";
    while(true){
        int n;cout <<"Enter your choice: ";cin >> n;
        if(n == 1){
            fe.setData();
        }
        if(n == 2){
            if(fe.checkData()){
                cout <<"LOGIN SUCCESSFULLY\n";
            }
            else{
                cout <<"CHECK YOUR CREDENTIALS TRY AGAIN\n";
            }
        }
        if(n == 3)
            exit(1);
    }
    return 0;
}
