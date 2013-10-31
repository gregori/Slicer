#include "Facet.h"

namespace ProcessPlanning
{

	Facet::Facet(void)
	{
	}

	Facet::~Facet(void)
	{
	}

    void Facet::setVector (Vector* v)
    {
        normal = v;
    }

    Vector* Facet::getVector(void) const
    {
        return normal;
    }

    Point* Facet::getV1(void) const
    {
        return static_cast<Point*>(geomList.get(0));
    }

    Point* Facet::getV2(void) const
    {
        return static_cast<Point*>(geomList.get(1));
    }

    Point* Facet::getV3(void) const
    {
        return static_cast<Point*>(geomList.get(2));
    }

    void Facet::addVertex(Point* p)
    {
        addGeometry(static_cast<Geometry*>(p));
    }

    bool Facet::operator==(const Facet &t) const
    {
        if (t.getVector() != normal)
            return false;

        if (t.getV1() == getV1() && t.getV2() == getV2() && t.getV3() == getV3())
            return true;

		return false;
    }

    bool Facet::operator!=(const Facet &t) const
    {
        if (t.getVector() == normal && t.getV1() == getV1() && t.getV2() == getV2()
                && t.getV3() == getV3())
            return false;
        return true;
    }

	void Facet::render(void)
	{
		ifImp->render(this);
		//geomList.renderAllGeometries();
		//ifImp->finishRender();
	}
	
	float Facet::getFacetHeight(void) const
	{
		return this->getZMax() - this->getZMin();
	}

}
