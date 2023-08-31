// Nicolas Nouhi 
#include "CFileReader.h"
#include "CBonusSquare.h"
#include "CCarWash.h"
#include "CGOSquare.h"
#include "CGoToJailSquare.h"
#include "CJailSquare.h"
#include "CPenaltySquare.h"
#include "CProperty.h"
#include "CStationSquare.h"

SquareVector CFileReader::ReadFile(string fileName, int fileSize)
{
	SquareVector vSquares;

	fstream myFile;
	myFile.open("monopoly.txt", ios::in); //read

	if (myFile.is_open())
	{
		int i = 0;
		string filelineStr;

		// Initialise variables that will hold file data
		int whitespaceIndex;
		string propertyName1;
		string propertyName2;
		string propertyNameConcat;
		int cost=0, rent=0, colourGroup = 0, jailPos = 0;

		while (i < fileSize)
		{
			whitespaceIndex = 0;
			propertyName1 = "";
			propertyName2 = "";
			propertyNameConcat = "";
			cost = 0, rent = 0, colourGroup = 0;

			string spaceSeperatedStr = "";
			getline(myFile, filelineStr);
			
			// Cast first char of fileread to determine square type
			char type = filelineStr[0];

			filelineStr.erase(filelineStr.begin());//remove square type 

			switch (type)
			{
				case '1': // Property
					for (auto x : filelineStr)
					{
						if (x == ' ')//whitespace
						{
							if (whitespaceIndex == 1) // obtain property name 1
							{
								propertyName1 = spaceSeperatedStr;
							}
							else if (whitespaceIndex == 2) // obtain property name 2 and concat with property 1 to produce full name
							{
								propertyName2 = spaceSeperatedStr;
								propertyNameConcat = propertyName1 + " " + propertyName2;
							}
							else if (whitespaceIndex == 3) // obtain cost
							{
								cost = stoi(spaceSeperatedStr);
							}
							
							else if (whitespaceIndex == 4) // obtain rent
							{
								rent = stoi(spaceSeperatedStr);
							}

							spaceSeperatedStr = "";
							whitespaceIndex++;
						}
						else
						{
							spaceSeperatedStr += x; //concat char x with formed string
						}	
					}

					colourGroup = stoi(spaceSeperatedStr); // obtain colour group
					spaceSeperatedStr = "";
					vSquares.push_back(make_shared<CProperty>(propertyNameConcat, cost, rent, colourGroup));
					break;

				case '2': // GO
					vSquares.push_back(make_shared<CGOSquare>(filelineStr));
					break;
				
				case '3': // Station
					vSquares.push_back(make_shared<CStationSquare>(filelineStr));
					break;

				case '4': // Bonus
					vSquares.push_back(make_shared<CBonusSquare>(filelineStr));
					break;

				case '5': // Penalty
					vSquares.push_back(make_shared<CPenaltySquare>(filelineStr));
					break;

				case '6': // Jail
					jailPos = i;
					vSquares.push_back(make_shared<CJailSquare>(filelineStr));
					break;

				case '7': // Go to Jail
					vSquares.push_back(make_shared<CGoToJailSquare>(filelineStr, jailPos));
					break;
				
				case '8': // Car Wash
					vSquares.push_back(make_shared<CCarWash>(filelineStr));
					break;

			}
			i++;
		}
		myFile.close();
	}
	else
	{
		cout << "File could not be opened.";
	}

	
	// only for debug
	/*for (vector<CSquare*>::iterator it = vSquares.begin(); it != vSquares.end(); it++)
	{
		(*it)->Display();
	}*/
	return vSquares;
}

int CFileReader::ReadFile()
{
	fstream myFile;
	myFile.open("seed.txt", ios::in); //read

	if (myFile.is_open())
	{
		string seed;
		getline(myFile, seed);
		myFile.close();

		return stoi(seed);
	}
	else
	{
		cout << "File could not be opened.";
	}

}
