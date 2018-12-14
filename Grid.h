#ifndef GRID_H
#define GRID_H

#include<iostream>
#include<vector>


namespace grid
{ 
	template<typename gridType>
	class Grid
	{
	//NOTE: This grid will be in ROW MAJOR (grid[0] being the first row)
	
		public:
			/*i wasnt sure where to put the typedefs below within the
				class declaration, so i put them in the public section */
				
			typedef std::vector<gridType> gridCol;
			typedef std::vector<gridCol> gridT;
			
			//hybrid constructor
			Grid(int num_rows = 9, int num_cols = 9):
			m_grid(num_rows, gridCol(num_cols))
			{m_locPtr = &m_grid[0][0];}
			
			//destructor
			~Grid(){delete m_locPtr;}
			
			void move_pos(int row_pos, int col_pos)
			{
				if (row_pos <= m_grid.size() && col_pos <= m_grid[row_pos].size())
					m_locPtr = &m_grid[row_pos][col_pos];
				else:
					std::cerr<<"position out of bounds! Location unchaged."<<std::endl;
			}
		//
		private:
			gridT m_grid;
			gridType *m_locPtr;//points to current location
			
	};//end class Grid declaration
}//end grid namespace

#endif //GRID_H