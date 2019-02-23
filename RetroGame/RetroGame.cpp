#include "pch.h"
#include "CGame.h"

int main(int argc, char *argv[])
{
	try
	{
		srand(static_cast<unsigned int>(time(0)));
		CGame Game;
		Game.Run();
	}
	catch (string err)
	{
		cout << err << endl ;
	}

	return 0;
}