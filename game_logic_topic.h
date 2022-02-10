#pragma once
#include"golbal_variables.h"
#include"objects_topic.h"
bool isGameOver()
{
	if (life <= 0)
	{
		return true;
	}
	else
		return false;
}
bool isRoadEmpty()
{
	bool flag = true;
	for (int i = 0; i < 100; i++)
	{
		if (car[i].setVisible)
			flag = false;
	}
	//	printf("\n");
		//printf("flag %d\n",flag);
	return flag;
}

bool isCarCollusion()
{
	bool flag = false;
	for (int i = 0; i < 100; i++)
	{
		if (car[i].setVisible) {
			double a, b;
			if (posX > car[i].pointX)
				a = posX - car[i].pointX;
			else
				a = car[i].pointX - posX;
			if (posY > car[i].pointY)
				b = posY - car[i].pointY;
			else
				b = car[i].pointY - posY;
			if (a < 1 && b < 0.9)
			{
				flag = true;
				car[i].setVisible = false;
			}
		}
	}
	return flag;

}
///
bool isMissileCollusion()
{
	//printf("%d",setMissile);
	bool flag = false;//printf("\n");
	for (int mm = 0; mm < 4; mm++)
	{
		if (m[mm].setVisible)
		{
			for (int i = 0; i < 100; i++)
			{
				if (car[i].setVisible)
				{
					double a, b;
					if (m[mm].pointX > car[i].pointX)
						a = m[mm].pointX - car[i].pointX;
					else
						a = car[i].pointX - m[mm].pointX;

					if (m[mm].pointY > car[i].pointY)
						b = m[mm].pointY - car[i].pointY;
					else
						b = car[i].pointY - m[mm].pointY;

					if (b < 0.7 && a < 1)
					{
						flag = true;
						m[mm].setVisible = false;
						car[i].setVisible = false;
						//printf("%d %d %d\n",m[mm].setVisible ,	car[i].setVisible,mm);

					}
				}
			}
		}
	}
	return flag;

}