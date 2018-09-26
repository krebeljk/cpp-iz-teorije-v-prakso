#include <array>
#include <iostream>

class EBoard
{
private:
	int maxX_;
	int maxY_;
	int thr_;

	using row_t = std::array<int, 7>;

	std::array<row_t, 7> state_;

public:
	EBoard():
		maxX_(7),
		maxY_(7),
		state_()
	{
		for (int i = 0; i < maxX_; i++)//vrsta
		{
			for (int j = 0; j < maxY_; j++)//stolpec
			{

				// SL
				if (i < 2 && j < 2)
					state_[i][j] = -1;

				// SD
				if (i >= 5 && j < 2)
					state_[i][j] = -1;
				
				// ZL
				if (i < 2 && j >= 5)
					state_[i][j] = -1;

				// ZD
				if (i >= 5 && j >= 5)
					state_[i][j] = -1;
			}
		}


		state_[3][3] = 1;


	
	
	};




	void printNum() {
	
		for (auto &row : state_)
		{
			for (auto &el : row)
			{

				//std::cout << "i" << i << "j" << j << " ";
				std::cout << el;

			}

			std::cout << "\n";
		}
	}

	void print() {

		for (auto &row : state_)
		{
			for (auto &el : row)
			{
				char rep = ' ';

				if (el == 0)
					rep = '.';

				if (el == 1)
					rep = 'o';

				std::cout << rep;

			}

			std::cout << "\n";
		}
	
	}

	int pegCount() {

		int count = 0;

		for (auto &row : state_)
		{
			for (auto &el : row)
			{
				if (el == 0)
				{
					count++;
				}
			}

		}

		return count;
	}

};