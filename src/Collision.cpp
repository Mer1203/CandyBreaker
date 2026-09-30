#include "Collision.h"

//COLISIONES AABB ADAPTADAS A SIGIL:

double CheckRectangleCollision(double rectangleAX, double rectagleWidthA, double rectangleBX, double rectagleWidthB,
                  	           double rectangleAY, double rectagleHeightA, double rectangleBY, double rectagleHeightB)
{
	return !(rectangleAX - rectagleWidthA * 0.5 > rectangleBX + rectagleWidthB * 0.5 ||
		   rectangleAX + rectagleWidthA * 0.5 < rectangleBX - rectagleWidthB * 0.5 ||
		   rectangleAY - rectagleHeightA * 0.5 > rectangleBY + rectagleHeightB * 0.5 ||
		   rectangleAY + rectagleHeightA * 0.5 < rectangleBY - rectagleHeightB * 0.5);
}

//double AisToTheRightOfB(double rectangleAX, double rectagleWidthA, double rectangleBX, double rectagleWidthB)
//{
//	return rectangleAX - rectagleWidthA / 2 > rectangleBX + rectagleWidthB / 2;
//}
//
//double AisToTheLeftOfB(double rectangleAX, double rectagleWidthA, double rectangleBX, double rectagleWidthB)
//{
//	return rectangleAX + rectagleWidthA / 2 < rectangleBX - rectagleWidthB / 2;
//}
//
//double AisAboveB(double rectangleAY, double rectagleHeightA, double rectangleBY, double rectagleHeightB)
//{
//	return rectangleAY - rectagleHeightA / 2 > rectangleBY + rectagleHeightB / 2;
//}
//
//double AisUnderB(double rectangleAY, double rectagleHeightA, double rectangleBY, double rectagleHeightB)
//{
//	return rectangleAY + rectagleHeightA / 2 < rectangleBY - rectagleHeightB / 2;
//}

