#include "SimpleTriangle.h"
#include "PointFactory.h"
#include "GraphicsImp.h"
#include "OpenGLImp.h"
#include <iostream>

namespace ProcessPlanning
{
    SimpleTriangle::SimpleTriangle()
    {
        zMin = 1e8;
        zMax = -1e8;
    }

    SimpleTriangle::~SimpleTriangle()
    {
    }

    void SimpleTriangle::setZMax(const float z)
    {
        zMax = z;
    }

    float SimpleTriangle::getZMax() const
    {
		return zMax;
    }

    void SimpleTriangle::setZMin(const float z)
    {
        zMin = z;
    }

	float SimpleTriangle::getZMin() const
	{
		return zMin;
	}

    float SimpleTriangle::getInterceptZ() const
    {
        return interceptZ;
    }

    void SimpleTriangle::setInterceptZ(const float z)
    {
        interceptZ = z;
    }

    bool SimpleTriangle::operator<(const SimpleTriangle &rt) const
    {
        return getZMin() < rt.getZMin() || getZMin() == rt.getZMin() && getZMax() < rt.getZMax();
    }

    bool SimpleTriangle::checkInterception(const float z) const
    {
        return (z > zMin && z < zMax && zMin != zMax);
    }

    Rect* SimpleTriangle::intercept(const float z)
    {
        Rect *interception = new Rect();
        Point *v1, *v2, *v3;
        float x, y;
		int vcount = 0;
		
        v1 = this->getV1();
        v2 = this->getV2();
        v3 = this->getV3();

        if (v1->getZ() == z)
		{
            interception->addGeometry(v1);
			vcount++;
		}

        if (v2->getZ() == z)
		{
            interception->addGeometry(v2);
			vcount++;
		}

        if (v3->getZ() == z && vcount < 2)
		{
            interception->addGeometry(v3);
			vcount++;
		}

        if ((v1->getZ() > z && v2->getZ() < z || v1->getZ() < z && v2->getZ() > z) && vcount < 2)
        {
		    x = (v2->getX() - v1->getX()) * (z - v1->getZ()) / (v2->getZ() - v1->getZ()) + v1->getX();
		    y = (v2->getY() - v1->getY()) * (z - v1->getZ()) / (v2->getZ() - v1->getZ()) + v1->getY();

            interception->addGeometry(PointFactory::getPoint(x, y, z));
			vcount++;
        }

        if ((v2->getZ() > z && v3->getZ() < z || v2->getZ() < z && v3->getZ() > z) && vcount < 2)
        {
		    x = (v3->getX() - v2->getX()) * (z - v2->getZ()) / (v3->getZ() - v2->getZ()) + v2->getX();
		    y = (v3->getY() - v2->getY()) * (z - v2->getZ()) / (v3->getZ() - v2->getZ()) + v2->getY();

            interception->addGeometry(PointFactory::getPoint(x, y, z));
			vcount++;
        }

        if ((v1->getZ() > z && v3->getZ() < z || v1->getZ() < z && v3->getZ() > z) && vcount < 2)
        {
		    x = (v3->getX() - v1->getX()) * (z - v1->getZ()) / (v3->getZ() - v1->getZ()) + v1->getX();
		    y = (v3->getY() - v1->getY()) * (z - v1->getZ()) / (v3->getZ() - v1->getZ()) + v1->getY();

            interception->addGeometry(PointFactory::getPoint(x, y, z));
			vcount++;
        }
		
        interception->setInterface(new Graphics(static_cast<GraphicsImp*>(new OpenGLImp())));
		if (vcount < 2)
			std::cout << "Problema com vcount" << std::endl;
		
        return interception;
        
    }
}
