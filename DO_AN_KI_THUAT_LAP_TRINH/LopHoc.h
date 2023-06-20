#pragma once
#include <iostream>
#include "SinhVien.h"
#include "GiaoVien.h"
#include <iomanip>
using namespace std;
struct New_Class
{
	
	string type;
	string Class_Name;
	int Number_Student;
	List_Student LIST_STUDENT;
	Teacher TEACHER;
};
struct Node_Class
{
	New_Class info;
	Node_Class* pNext;
};
struct List_Class
{
	Node_Class* pHead;
};
bool isEmpty_Class(List_Class l);
void Initialize_Class(List_Class& l);
Node_Class* Make_Node_Class(New_Class x);
void Add_Tail_Class(List_Class& l, New_Class x);
void Number_Student_1Class(New_Class &CLASS);
void Print_1Class(New_Class x);
void Print_List_Class(List_Class l);
void Print_ListStudent_1Class(List_Class,string Name);
void Free_Node_Class(List_Class& l);


