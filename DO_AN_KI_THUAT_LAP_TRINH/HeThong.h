#pragma once
#include <iostream>
#include "SinhVien.h"
#include "GiaoVien.h"
using namespace std;
struct New_Register
{
	string Name;
	string ID;
	string pass;
};
struct Node_Register
{
	New_Register data;
	Node_Register* pNext;
};
struct List_Register
{
	Node_Register* pHead;
	Node_Register* pTail;
};
struct HeThong
{
	List_Register REGIS_TEA;
	List_Register REGIS_STU;
	string account;
	string pass;
};

void Initialize_Register(List_Register& l);
Node_Register* Make_Node_Register(New_Register x);
void Add_Tail_List_Register(List_Register& l,New_Register x );
void System(HeThong &s,string &maso,int &choose);
void Update_Pass(HeThong s, int choose);


