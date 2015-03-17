#include "PointF2D.h"
#include <math.h>


PointF2D PointF2D::operator- (const PointF2D& p) const
{
	PointF2D tmp;
	tmp.x = x - p.x;
	tmp.y = y - p.y;
	return(tmp);
}

PointF2D PointF2D::operator+ (const PointF2D& p) const
{
	PointF2D tmp;
	tmp.x = x + p.x;
	tmp.y = y + p.y;
	return(tmp);
}

PointF2D& PointF2D::operator+= (const PointF2D& p)
{
	x += p.x;
	y += p.y;
	return(*this);
}

PointF2D& PointF2D::operator-= (const PointF2D& p)
{
	x -= p.x;
	y -= p.y;
	return(*this);
}

bool PointF2D::operator== (const PointF2D& p)const
{
	return(x == p.x && y == p.y);
}

bool PointF2D::operator!= (const PointF2D& p) const
{
	return(x != p.x || y != p.y);
}

bool PointF2D::isZero()
{
	return(x == 0.0f && y == 0.0f);
}

void PointF2D::setZero()
{
	x = y = 0.0f;
}

float PointF2D::distanceTo(PointF2D p)
{
	//Define dx and dy as the distances between the two points.
	float dx = p.x - x, dy = p.y - y;
	//Return the distance between the two points, calculating the hypotenuse of the distances dx and dy (h^2 = dx^2 + dy^2)
	//"sqrt" returns the square root of x.
	return(sqrt(dx*dx + dy*dy));
}