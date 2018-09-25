#include <array>

class EBoard
{
private:
	int maxX_;
	int maxY_;

	std::array<std::array<int, 9>, 9> state_;

public:
	EBoard():
		maxX_(9),
		maxY_(9),
		state_()
	{
		for (int i = 0; i < maxX_; i++)//vrsta
			for (int j = 0; j < maxY_; j++)//stolpec
			{
				state_[i][j] = 0;
			}
	
	
	};
	~EBoard() {};




};