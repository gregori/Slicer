#include "SimpleGeometry.h"

namespace ProcessPlanning 
{

	SimpleGeometry::SimpleGeometry(const float x, const float y, const float z)
	{
		setX(x);
		setY(y);
		setZ(z);
	}


	SimpleGeometry::~SimpleGeometry(void)
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}

	float SimpleGeometry::getX(void) const
	{
		return x;
	}

	float SimpleGeometry::getY(void) const
	{
		return y;
	}

	float SimpleGeometry::getZ(void) const
	{
		return z;
	}

	void SimpleGeometry::setX(const float x)
	{
		this->x = x;
	}

	void SimpleGeometry::setY(const float y)
	{
		this->y = y;
	}

	void SimpleGeometry::setZ(const float z)
	{
		this->z = z;
	}

	float* SimpleGeometry::getCoords(void) const
	{
		float *coords = new float[3];

		coords[0] = x;
		coords[1] = y;
		coords[2] = z;

		return coords;
	}

}
