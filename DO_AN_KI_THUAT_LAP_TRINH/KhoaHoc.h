#pragma once
#include <iostream>
#include "LopHoc.h"
#include <iomanip>
using namespace std;
struct Course
{
	string ID;
	string Course_Name;
	int Credit_Number;
	int Number_Student_Max = 50;
	int Day;
	string Session;
	New_Class CLASS;
};
struct Node_Course
{
	Course info;
	Node_Course* pNext;
};
struct List_Course
{
	Node_Course* pHead;
	Node_Course* pTail;
};
bool isEmpty_Course(List_Course l);
void Initialize_Course(List_Course& l);
Node_Course* Make_Node_Course(Course x);
void Add_Tail_Course(List_Course& l, Course x);
// Them mot khoa hoc moi vao list danh sach khoa hoc
void Remove_Head_List_Course(List_Course& l);
void Remove_Tail_List_Course(List_Course& l);
void Print_1Course(Course x);
void Print_List_Course(List_Course l);
void Add_New_Course(Course &x);
int  Add_New_Student(List_Course &l,string ID);
int  Remove_Student(List_Course& l, string ID);
bool Delete_Course(List_Course& l,string ID);
void Print_ListStudent_1Course(List_Course l,string ID);
void Print_ListCourse_1Student(List_Course l, string ID);
void Output_File_1Course(List_Course l,string ID);
void Check_List_Course(List_Course l , string &ID);
void Update_Course_Information(List_Course &l, string ID_Course);
void Free_Node_Course(List_Course& l);
