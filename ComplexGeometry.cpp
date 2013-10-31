#include "ComplexGeometry.h"
#include "PointFactory.h"

namespace ProcessPlanning
{
	ComplexGeometry::ComplexGeometry(void)
	{
		xMin = 0;
        yMin = 0;
        zMin = 0;
        xMax = 0;
        yMax = 0;
        zMax = 0;
		sphereCenter = NULL;
	}


	ComplexGeometry::~ComplexGeometry(void)
	{
	}

	void ComplexGeometry::addGeometry(Geometry* geom)
	{
        if (geom != NULL)
		    geomList.insert(geom);
	}

    int ComplexGeometry::getSize(void) const
    {
        return geomList.getSize();
    }

    Geometry* ComplexGeometry::getGeometry(const int index)
    {
        return geomList.get(index);
    }
	
	void ComplexGeometry::setXMin(const float x)
	{
		xMin = x;
	}
	
	void ComplexGeometry::setYMin(const float y)
	{
		yMin = y;
	}
	
	void ComplexGeometry::setZMin(const float z)
	{
		zMin = z;
	}
	
	void ComplexGeometry::setXMax(const float x)
	{
		xMax = x;
	}
	
	void ComplexGeometry::setYMax(const float y)
	{
		yMax = y;
	}
	
	void ComplexGeometry::setZMax(const float z)
	{
		zMax = z;
	}
	
	float ComplexGeometry::getXMin(void) const
	{
		return xMin;
	}
	
	float ComplexGeometry::getYMin(void) const
	{
		return yMin;
	}
	
	float ComplexGeometry::getZMin(void) const
	{
		return zMin;
	}
	
	float ComplexGeometry::getXMax(void) const
	{
		return xMax;
	}
	
	float ComplexGeometry::getYMax(void) const
	{
		return yMax;
	}
	
	float ComplexGeometry::getZMax(void) const
	{
		return zMax;
	}
	
	Point* ComplexGeometry::getSphereCenter(void) const
	{
		return sphereCenter;
	}
	
	void ComplexGeometry::setSphereCenter(void)
	{
		sphereCenter = PointFactory::getPoint((xMax + xMin)/2, (yMax + yMin)/2, (zMax + zMin)/2);
	}
	
	void ComplexGeometry::setSphereRadius(void)
	{
		sphereRadius = sphereCenter->distanceFrom(PointFactory::getPoint(xMax, yMax, zMax));
	}
	
	double ComplexGeometry::getSphereRadius(void) const
	{
		return sphereRadius;
	}
	
	void ComplexGeometry::render(void)
	{
		//ifImp->prepareRender(this);
		geomList.renderAllGeometries();
	}
}
