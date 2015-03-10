#ifndef __POINTF2D_H__
#define __POINTF2D_H__

class PointF2D
{
private:
	float x, y;

public:
	PointF2D operator- (const PointF2D& p) const;
	PointF2D operator+ (const PointF2D& p) const;
	PointF2D& operator+= (const PointF2D& p);
	PointF2D& operator-= (const PointF2D& p);
	bool operator== (const PointF2D& p) const;
	bool operator!= (const PointF2D& p) const;
	bool isZero();
	void setZero();
	float distanceTo(PointF2D p);
};
#endif