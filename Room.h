#ifndef ROOM_H
#define ROOM_H

#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include<vector>

namespace room
{
	typedef std::vector<int> iVec;
	typedef std::vector<bool> bVec;
	typedef std::string str;
	
	class Room
	{
		public:
		
		/*explicit constructor. No default constructor as of yet.
		this program will only be calling explicit constructor anyways, 
		so there is not much need for a default.*/
		Room(str name, str description, iVec loc, bVec doors, bool goblet=false):
			m_name(name), m_description(description), is_goblet_game(goblet), 
			m_loc(loc.size() == 2 ? loc : iVec(2,-1)),  //initialize grid location to passed vector if same size. Else, (-1,-1)
			m_doors(doors.size() == 4 ? doors : bVec(4,-1))  //initialize door booleans to passed vector if same size. Default True.
		{
				m_doorsOpen["North"] = m_doors[0];
				m_doorsOpen["East"] = m_doors[1];
				m_doorsOpen["South"] = m_doors[2];
				m_doorsOpen["West"] = m_doors[3];
		}
		
		str getName() const {return m_name;}
		str getDesc() const {return m_description;}
		iVec getLoc() const {return m_loc;}
		bool isOpen(str door){return m_doorsOpen[door];}
		
		private:
		
		
		/********************************************************\
			Things I have not yet added but could:
				- Enemies within the room
				- list of items within the room
				
			if there are things I am missing that you would want,
				send me back this file with your desired additions
				somewhere as a comment or added.
		\*********************************************************/
		
		str m_name;
		str m_description;	
		iVec m_loc; /* location within 2D vector where room is located. 
						  [row, column] */
						  
		bVec m_doors; //north is index 0, east = 1, south = 2, west = 3.
		
		std::map<str, bool> m_doorsOpen; 
			/*the above map is stored out of want of a function 
				isOpen | the name of a door is passed, and its 
				boolean open value is returned.*/
				
		bool is_goblet_game; 
		/* a special script called goblet_game() or something to that extent will
		be run for the only room for which the above boolean is set to true.*/
	
	};//end class declaration
	
	
	//reads from file, converts each chunk of text into a vector of strings
	//truncated at each instance of delimChar.
	void readRoomFile(str filename, std::vector<str> &lineList, char delimChar = '&')
	{
		str line;
		std::fstream testFile(filename, std::fstream::in | std::fstream::out);
		if (testFile.is_open())
		{
			while (getline(testFile, line, '&'))
				{lineList.push_back(line);}	
		}
		testFile.close();
	}
	
	
	
	/*********************************************************************\
	the next two functions parse the result of readRoomFile into data 
		structures for dispersing into class Room's memeber data types.
	\*********************************************************************/
	
	
	
	
	/* ********************************************************************\ 
		takes as an argument the second element (linelist[2]) of linelist 
			vector, converts it into an list of integers.
		this function is supposed to be used to extract room location 
			from vector containing relevant room information.
	\***********************************************************************/
	void get_loc(str const &locStr, iVec &intVec)
	{
		//this only works for grids w/ sides < 10. I can fix that later if im feeling motivated.
		char locStr0 = locStr[0];
		char locStr2 = locStr[2];
		intVec[0] = locStr0-'0';
		intVec[1] = locStr2-'0';
	}
	
	
	/*****************************************************************\
	This function shall take as input a string of the form "0 1 0 0" 
		or similar, and convert it into a vector of booleans. 
	\*****************************************************************/
	void get_bools(str boolStr, bVec &boolVec)
	{
		char boolStr0 = boolStr[0];
		char boolStr2 = boolStr[2];
		char boolStr4 = boolStr[4];
		char boolStr6 = boolStr[6];
		boolVec[0] = ((bool)boolStr0-'0');
		boolVec[2] = ((bool)boolStr2-'0');
		boolVec[4] = ((bool)boolStr4-'0');
		boolVec[6] = ((bool)boolStr6-'0');
	}
	
	
}
#endif //ROOM_H