#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char userType;


int addStudents()
{
    int studentNo;
    string studentName;

    studentNo = 0;

    cout << "How many students do you want to add? ";
    cin >> studentNo;

    for (int i = 1; i <= studentNo; i++) {
        string studentName;

        cout << "NAME STUDENT NO. " << i << ": ";
        cin >> studentName;
    }

    return 0;
}

int viewStudents()
{
    cout << "view students";
    return 0;
}

int addPortfolio()
{
    int portfolioNo;
    string portfolioName;

    portfolioNo = 0;

    cout << "How many portfolios do you want to add? ";
    cin >> portfolioNo;

    for (int i = 1; i <= portfolioNo; i++) {
        string portfolioName;

        cout << "NAME PORTFOLIO NO. " << i << ": ";
        cin >> portfolioName;
    }

    return 0;
}

int viewFolio()
{
    cout << "YEHEYY";
    return 0;
}

int teacher()
{
    string firstName, lastName, idNumber;

    if (userType == 'T' || userType == 't')
    {
        cout << "\nWhat is your ID Number? [NNNNN-YYYY]: ";
        cin >> idNumber;
        while (idNumber.length() != 10 || idNumber.substr(6, 9) != "2023" || idNumber[5] != '-' || !isdigit(idNumber[0]) || !isdigit(idNumber[1]) || !isdigit(idNumber[2]) || !isdigit(idNumber[3]) || !isdigit(idNumber[4]))
        {
            cout << "Invalid ID Number" << endl;
            cout << "Enter ID Number again [NNNNN-YYYY]: ";
            cin >> idNumber;
        }
    }

    int teacherChoice;
choiceTeach:
    cout << "\nENTER NUMBER OF YOUR CHOICE" << endl;
    cout << "[1] ADD STUDENTS\t[2] VIEW STUDENTS" << endl;
    cin >> teacherChoice;

    if (teacherChoice == 1)
    {
        addStudents();
    }
    else if (teacherChoice == 2)
    {
        viewStudents();
    }
    else
    {
        cout << "Invalid input. Enter 1 or 2: ";
        goto choiceTeach;
    }

    return 0;
}

int student() {
    string firstName, lastName, idNumber;


    cout << "\nWhat is your ID Number? [YYYY-NNNNN]: ";
    cin >> idNumber;
    while (idNumber.length() != 10 || idNumber.substr(0, 4) != "2023" || idNumber[4] != '-' || !isdigit(idNumber[5]) || !isdigit(idNumber[6]) || !isdigit(idNumber[7]) || !isdigit(idNumber[8]) || !isdigit(idNumber[9]))
    {
        cout << "Invalid ID Number" << endl;
        cout << "Enter ID Number again [YYYY-NNNNN]: ";
        cin >> idNumber;
    }

    int studentChoice;
choiceStud:
    cout << "\nENTER NUMBER OF YOUR CHOICE" << endl;
    cout << "[1] ADD PORTFOLIO\t[2] VIEW SAVED PORTFOLIOS" << endl;
    cin >> studentChoice;

    if (studentChoice == 1)
    {
        addPortfolio();
    }
    else if (studentChoice == 2)
    {
        viewFolio();
    }
    else
    {
        cout << "Invalid input. Enter 1 or 2: ";
        goto choiceStud;
    }


    return 0;
}

void userInfo()
{
    string firstName, lastName, idNumber;

    cout << "Hi! Thank you for using Edufolio, what is your name?" << endl;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;

    cout << "\n*****************************************************************" << endl;
    cout << "\t\t   Welcome to Edufolio " << firstName << " " << lastName << endl;
}

void userID()
{

    cout << "\t      Are you a student [S] or a teacher [T]?" << endl;
    cout << "*****************************************************************" << endl;

    cout << "\nEnter User Type [S,T]: ";
    cin >> userType;

    // Validate the input
    while (userType != 'T' && userType != 't' && userType != 'S' && userType != 's')
    {
        cout << "Invalid input. Enter T or S: ";
        cin >> userType;
    }
    switch (userType)
    {
    case 'T':
    case 't':
        teacher();
        break;
    case 'S':
    case 's':
        student();
        break;
    }
}

int main()
{
    userInfo();
    userID();

    return 0;
}
