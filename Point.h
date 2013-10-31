#pragma once
#include "SimpleGeometry.h"
#include "Graphics.h"
#include <string>

namespace ProcessPlanning 
{
	class Point : public SimpleGeometry
	{
	public:
		Point(const float x=0.0, const float y=0.0, const float z=0.0);
		Point();
		~Point();
		
		double distanceFrom(Point* p);
		
        std::string getLabel();
		bool operator==(const Point &p) const;
	    bool operator!=(const Point &p) const;
	    bool operator<(const Point &p) const;
	    bool operator>(const Point &p) const;
		Point operator+(const Point &p);
		Point operator-(const Point &p);
		Point operator*(const float &f);
		float distanceFrom(Point &p);

		virtual void render(void);
	};
}
