#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

struct Account {
    string username = "", password = "";
    string firstName = "", lastName = "";
    string Gender = ""; // 
    string SocialID = "";
    string birth = "";
    int role; // 1 student, 2 teacher, 3 staff.
    Account* next = nullptr, * prev = nullptr;
};
struct Score
{
    double totalMark = 0, finalMark = 0, midMark = 0, otherMark = 0;
};

struct StudentCourse
{
    string id = "";
    string fullname = "";
    StudentCourse* next = nullptr, * prev = nullptr;
    Score sc;
};

struct Course
{
    string name = "";
    string courseID = ""; 
    int numOfCredits = 0, maxStudents = 50, numStudents = 0;
    string room = "";
    string teacherName = "";
    string day = "";    
    string session = "";
    StudentCourse* studentCourse = nullptr;
    Course* next = nullptr, * prev = nullptr;
};

struct CourseList
{
    Course* course = nullptr;
    CourseList* next = nullptr;
};

struct Student
{
    Account* accStudent = nullptr;
    string ID = "";
    CourseList* course = nullptr;
    Student* next = nullptr, * prev = nullptr;
};

struct Class
{
    string name; 
    Student* studentOnClass = nullptr;
    Class* next = nullptr, * prev = nullptr;
};

struct Semester
{
    int No;   
    int Year;
    string startDate, endDate;
    Course* course = nullptr;
    Semester* next = nullptr, * prev = nullptr;
};

struct Year
{
    int yearStart;
    Class* Class = nullptr;
    Semester* Semester = nullptr;
    Year* next = nullptr;
    Year* prev = nullptr;
};
