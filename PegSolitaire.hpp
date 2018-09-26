#include <array>
#include <iostream>

class EBoard
{
private:
	int maxX_;
	int maxY_;
	int thr_;

	std::array<std::array<int, 7>, 7> state_;

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
	
		for (int j = 0; j < maxY_; j++)
		{
			for (int i = 0; i < maxX_; i++)
			{

				//std::cout << "i" << i << "j" << j << " ";
				std::cout << state_[i][j];

			}

			std::cout << "\n";
		}
	}

	void print() {

		for (int j = 0; j < maxY_; j++)
		{
			for (int i = 0; i < maxX_; i++)
			{
				int peg = state_[i][j];

				char rep = ' ';

				if (peg == 0)
					rep = '.';

				std::cout << rep;

			}

			std::cout << "\n";
		}
	
	}

	int pegCount() {

		int count = 0;

		for (int j = maxY_ - 1; j >= 0; j--)
		{
			for (int i = 0; i < maxX_; i++)
			{
				if (state_[i][j] > -1)
				{
					count++;
				}
			}

		}

		return count;
	}

};