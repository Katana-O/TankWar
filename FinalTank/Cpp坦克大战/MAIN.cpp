#include "HEADER.h"
#include "TANK.h"
#include "BULLET.h"
#include "BASE.h"

int main()
{

	system("mode con cols=160 lines=50");
	InvisibleCursor();
	BASE Base;
	Base.GameStart();
	system("pause");

}