#pragma once


#include<iostream>
#include<fstream>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<iomanip>

using namespace std;
const int MAX=10000;
const int ENTER=13;
const int ESC=27;
const int SPACEBAR=32;
int pointer = 17; // con tro dieu khien menu main
int toadoXBox = 90;
int toadoYBox = 10;
const int MaxNodes = 10000;
int SoNgayDcMuon = 7; //so ngay toi da duoc muon sach
const int randomInt = 30000;
static bool* randomArray = new bool[randomInt];
int numberReaderTicket = 0;
int backgroundColor = 7;
int currentDay = 29;
int currentMonth = 7;
int currentYear = 2020;

