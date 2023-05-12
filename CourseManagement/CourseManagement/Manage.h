#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
using namespace std;

struct Date {
    int dd;
    int mm;
    int yy;
};
//Luu danh sach tat ca cac lop.
struct Class
{
    string name;
    Class* next;
};

struct Score
{
    double totalMark, finalMark, midMark, otherMark;
};
struct StudentCourse
{
    string id = "";
    string fullname = "";
    StudentCourse* next;
    Score sc;
};
//Luu danh sach tat ca cac khoa hoc.
struct Course
{
    string name;
    string courseID;
    int numOfCredits, maxStudents = 50, numStudents;
    string room;
    string teacherName;
    string day;
    string session;
    StudentCourse* studentCourseHead;
    Course* next;
};
struct AccountInf {
    string username, password;
    string firstName, lastName;
    int Gender; // 0 Male,1 Female.
    string SocialID;
    Date Dob;
    int Role; // 1 student, 2 staff.
};
// Luu danh sach tat ca cac tai khoan.
struct Account {
    AccountInf acc;
    Account* next;
};
struct AccountList {
    Account* Head;
};
struct CourseList
{
    Course* Head;
};
// Luu danh sach tat ca hoc sinh.
struct Student
{
    Account* accStudent;
    string ID;
    Class* Class;
    CourseList* course;
    Student* next;

};
struct StudentList {
    Student* Head;
};



//Luu danh sach tat ca sinh vien trong 1 khoa hoc





struct Semester
{
    int No;   
    int Year;
    string startDate, endDate;
    Course* courseHead ;
    Semester* next;
};

struct Year
{
    int yearStart;
    Class* Class;
    Semester* Semester;
    Year* next;
};

Account* getNode(AccountInf a);
void loadAccount(AccountList& l);
int login(AccountList l,Account * a);
void Menu(Account* a);
int StudentMenu();
