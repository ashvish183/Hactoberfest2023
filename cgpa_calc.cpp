#include<iostream>
#include<fstream>
using namespace std;

void sgpa() {
    int mul;
    string grade;
    float credit;
    int subs = 0;
    float sgpa = 0;
    float credits = 0;
    cout << "Enter the number of subjects :" << endl;
    cin >> subs;
    while(subs != 0) {
        cout << "Enter the grade in subject :" << endl;
        cin >> grade;
        if (grade == "O") {
            mul = 10;
        }
        if (grade == "A+") {
            mul = 9;
        }
        if (grade == "A") {
            mul = 8;
        }
        if (grade == "B+") {
            mul = 7;
        }
        if (grade == "B") {
            mul = 6;
        }
        if (grade == "C") {
            mul = 5;
        }
        if (grade == "P") {
            mul = 4;
        }
        if (grade == "F") {
            mul = 0;
        }
        cout << "Enter the credits for the subject :" << endl;
        cin >> credit;
        sgpa += mul*credit;
        credits += credit;
        subs--;
    }
    float sgpa_final = sgpa/credits;
    cout << "Your SGPA is : " << sgpa_final << endl;
}

void cgpa() {
    float add = 0;
    float sgpa = 0;
    int sems;
    cout << "Enter number of semesters : " << endl;
    cin >> sems;
    int sem = sems;
    while(sem != 0) {
        float sg;
        cout << "Enter sgpa of the semester : " << endl;
        cin >> sg;
        sgpa += sg;
        sem--;
    }
    cout << "Your SGPA is : " << sgpa/sems << endl;
}



int main() {
    cout << endl;
    cout << "-------------------CGPA Calculator-----------------------" << endl << endl;
    cout << "Please select the option :" << endl << endl;
    cout << "Calculate CGPA-------------(1)" << endl;
    cout << "Calculate SGPA-------------(2)" << endl;
    cout << "Calculate %age from CGPA---(3)" << endl;
    int choose;
    cin >> choose;
    if(choose == 2) {
        sgpa();
    }
    if(choose == 1) {
        cgpa();
    }
}