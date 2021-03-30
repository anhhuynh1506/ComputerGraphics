#include "pch.h"
#include "MidPoint.h"
void Eight_point(CDC* pDC, int X, int x_center, int Y, int y_center, int r, COLORREF color)
{
	if (r > 0)
	{
		pDC->SetPixel(X + x_center, Y + y_center, color);
		pDC->SetPixel(-X + x_center, Y + y_center, color);
		pDC->SetPixel(X + x_center, -Y + y_center, color);
		pDC->SetPixel(-X + x_center, -Y + y_center, color);
		pDC->SetPixel(Y + x_center, X + y_center, color);
		pDC->SetPixel(-Y + x_center, X + y_center, color);
		pDC->SetPixel(Y + x_center, -X + y_center, color);
		pDC->SetPixel(-Y + x_center, -X + y_center, color);
	}
}
void MidPoint::MidPoint_Algo(CDC* pDC, int x_center, int y_center, int r, COLORREF color)
{
	int X = 0;
	int Y = r;
	int f = 1 - r;
	Eight_point(pDC, X, x_center, Y, y_center, r, RGB(255, 0, 0));
	while (X < Y)
	{
		X++;
		if (f < 0)
		{
			f += 2 * X + 3;
		}
		else
		{
			Y -= 1;
			f += 2 * X - 2 * Y + 5;
		}
		Eight_point(pDC, X, x_center, Y, y_center, r, RGB(255, 0, 0));
	}
}
