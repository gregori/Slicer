#include "Point.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

namespace ProcessPlanning
{
	Point::Point(const float x, const float y, const float z)
		: SimpleGeometry(x, y, z)
	{
	}
	
	Point::Point()
		: SimpleGeometry()
	{
	}
	
	Point::~Point()
	{
	}
	
	double Point::distanceFrom(Point* p)
	{
		return sqrt(pow(p->getX() - this->getX(),2) + 
					pow(p->getY() - this->getY(), 2) + pow(p->getZ() - this->getZ(), 2));
	}

    std::string Point::getLabel()
    {
        std::stringstream ss;
        ss << std::setprecision(7) << this->getX() << "|" << std::setprecision(7) << this->getY()
			<< "|" << std::setprecision(7) << this->getZ();
        return ss.str();
    }
	
	float Point::distanceFrom(Point &p)
	{
		return sqrtf( powf((p.getX() - getX()), 2.0) + 
					  powf((p.getY() - getY(), 2.0)) + 
					  powf((p.getZ() - getZ(), 2.0) );
	}
		
    bool Point::operator== (const Point &p) const
    {
        return (distanceFrom(p) <= 0.0005f);
    }		/* -----  end of method Point::operator==  ----- */

    bool Point::operator!= (const Point &p) const
    {
        return (distanceFrom(p) > 0.0005f);
    }		/* -----  end of method Point::operator!=  ----- */

    bool Point::operator< (const Point &p) const
    { 
        if (this->x == p.x) 
		{
			if (this->y == p.y)
				return (this->z < p.z);
			return (this->y < p.y);
		}
		return (this->x < p.x);
    }		/* -----  end of method Point::operator!=  ----- */

    bool Point::operator> (const Point &p) const
    { 
        //return !(this < p);
		return false;
    }		/* -----  end of method Point::operator!=  ----- */

	Point Point::operator+(const Point &p)
	{
		Point result(getX() + p.getX(), getY() + p.getY(), getZ() + p.getZ());

		return result;
	}
	
	Point Point::operator-(const Point &p)
	{
		Point result(getX() - p.getX(), getY() - p.getY(), getZ() - p.getZ());

		return result;
	}
	
	Point Point::operator*(const float &f)
	{
		Point result(getX() * f, getY() * f, getZ() * f);
		
		return result;
	}
	
	void Point::render(void)
	{
		ifImp->render(this);
	}
}
