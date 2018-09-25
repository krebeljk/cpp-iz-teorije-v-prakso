#include <array>
#include <iostream>

class EBoard
{
private:
	int maxX_;
	int maxY_;
	int thr_;

	std::array<std::array<int, 9>, 9> state_;

public:
	EBoard():
		maxX_(9),
		maxY_(9),
		thr_(3),
		state_()
	{
		for (int i = 0; i < maxX_; i++)//vrsta
		{
			for (int j = 0; j < maxY_; j++)//stolpec
			{

				// SL
				if (i < thr_ && j < thr_)
					state_[i][j] = -1;

				// SD
				if (i >= 2*thr_ && j < thr_)
					state_[i][j] = -1;
				
				// ZL
				if (i < thr_ && j >= 2*thr_)
					state_[i][j] = -1;

				if (i >= 2*thr_ && j >= 2*thr_)
					state_[i][j] = -1;

			}
		}


	
	
	};

	~EBoard() {};



	void print() {
	
		for (int i = 0; i < maxX_; i++)//vrsta
		{
			for (int j = 0; j < maxY_; j++)//stolpec
			{

				std::cout << state_[i][j];

			}

			std::cout << "\n";
		}
	}

};