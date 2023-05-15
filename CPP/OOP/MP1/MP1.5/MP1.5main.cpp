//
//  main.cpp
//  MP1.5
//
//  Created by Fei Gao on 2022/3/12.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


//definition block
struct student
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
} studentData[20];

void reading(ifstream&, student studentData[]);
void grading(student studentData[]);
void highest(student studentData[], string&, int&);
void print(string, int);

int main()
{
    ifstream inFile;
    inFile.open("data.txt");
    if(!inFile)
    {
        cout << "Open Failure.";
    }
    //function1
    reading(inFile, studentData);
    
    //function2
    grading(studentData);
    
    //function3
    string name;
    int gradeMax = 0;
    highest(studentData, name, gradeMax);
    
    //function4
    print(name, gradeMax);
    return 0;
}

//function1
void reading(ifstream& inFile, student studentData[])
{
    for (int i = 0; i < 20 ; i++)
    {
        inFile >> studentData[i].studentFName >> studentData[i].studentLName >> studentData[i].testScore;
    }
}

//function2
void grading(student studentData[])
{
    //I combined the grade-assigning function and the formatting function
    for (int i = 0; i < 20 ; i++)
    {
        int k = studentData[i].testScore;
        if (k < 60)
            studentData[i].grade = 'F';
        else if ((k >= 60) and (k < 70))
            studentData[i].grade = 'D';
        else if ((k >= 70) and (k < 80))
            studentData[i].grade = 'C';
        else if ((k >= 80) and (k < 90))
            studentData[i].grade = 'B';
        else if (k >= 90)
            studentData[i].grade = 'A';
        
        string fullName = studentData[i].studentLName + ", " + studentData[i].studentFName;
        cout << left << setw(35) << fullName << setw(5) << studentData[i].testScore << studentData[i].grade << endl;
    }
}

//function3
//I neglected the condition of tie. If there is a tie, the later student's data will be ignored
void highest(student studentData[], string& name, int& gradeMax)
{
    for (int i = 0; i < 20 ; i++)
    {
        if (studentData[i].testScore > gradeMax)
        {
            gradeMax = studentData[i].testScore;
            name = studentData[i].studentFName + " " + studentData[i].studentLName;
        }
    }
}

void print(string name, int grade)
{
    cout << "__________________________ " << endl <<  "The best student is " << name << " with a grade of " << grade << "!" << endl;
}
