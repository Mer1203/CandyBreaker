#include "Collision.h"

//COLISIONES AABB ADAPTADAS A SIGIL:

double CheckRectangleCollision(double rectangleAX, double rectagleWidthA, double rectangleBX, double rectagleWidthB,
                  	           double rectangleAY, double rectagleHeightA, double rectangleBY, double rectagleHeightB)
{
	return !(rectangleAX - rectagleWidthA / 2 > rectangleBX + rectagleWidthB / 2 ||
		   rectangleAX + rectagleWidthA / 2 < rectangleBX - rectagleWidthB / 2 || 
		   rectangleAY - rectagleHeightA / 2 > rectangleBY + rectagleHeightB / 2 ||
		   rectangleAY + rectagleHeightA / 2 < rectangleBY - rectagleHeightB / 2);
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

