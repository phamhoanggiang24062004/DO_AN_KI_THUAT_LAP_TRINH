#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct Date
{
	int Day;
	int Month;
	int Year;
};
struct Student
{
	int No;
	string StudentID;
	string FirstName;
	string LastName;
	string Gender;
	Date DateOfBirth;
	string SocialID;
	float TotalMark;
	float MidtermMark;
	float FinalMark;
	float OtherMark;
};


struct Node_Student
{
	Student info;
	Node_Student* pNext;
};
struct List_Student
{
	Node_Student* pHead;
	Node_Student* pTail;
};
void isLeapYear(int year,int A[13]);
void Initialize_Student(List_Student& l);
Node_Student* Make_Node_Student(Student x);
void Add_Tail_List_Student(List_Student& l, Student x);
void Remove_Head_List_Student(List_Student& l);
void Remove_Tail_List_Student(List_Student& l);
void Print_1Student(Student x);
void Print_List_Student(List_Student l);
void Read_1Student(ifstream & read,Student &x);
void Read_File_Student( List_Student& l);
void Input_1Student(Student &x);
void Update_IDStudent(List_Student& l, string ID);
void Delete_1Student(List_Student& l,string ID);
void Free_Node_Student(List_Student &l);





