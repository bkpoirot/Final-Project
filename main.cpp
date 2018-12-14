#include"Room.h"


int main()
{
	std::vector<std::string> fileVec;
	room::readRoomFile("testFile.txt",fileVec);
	std::cout<<fileVec[2]<<std::endl;
	std::vector<int> locVec;
	room::get_loc(fileVec[2], locVec);
	std::cout<<"Extracted fileVec loc contents into LocVec"<<std::endl;
	for(int i = 0; i < locVec.size(); i++)
	{
		std::cout<<locVec[i]<<std::endl;
	}
	
	return 0;
}

