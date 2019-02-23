#include "CGame.h"

int main(int argc, char *argv[])
{
	srand(static_cast<unsigned int>(time(0)));
	CGame Game;
	Game.Run();
   
   return 0;
}