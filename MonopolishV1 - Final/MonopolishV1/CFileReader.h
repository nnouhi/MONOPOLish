// Nicolas Nouhi 
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <functional>


class CSquare;

using namespace std;
typedef vector<shared_ptr<CSquare>> SquareVector;
class CFileReader
{
public:
	SquareVector ReadFile(string fileName, int fileSize);
	int ReadFile();
};

