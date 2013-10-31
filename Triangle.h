#pragma once
#include "ComplexGeometry.h"
#include "Vector.h"
#include "Point.h"
#include "Graphics.h"
#include "Rect.h"

namespace ProcessPlanning
{
	class Triangle :
		public ComplexGeometry
	{
	private:
        Vector* normal;
	public:
		Triangle(void);
		~Triangle(void);
		virtual float getZMin() const = 0;
		virtual float getZMax() const = 0;
        virtual void setZMin(const float z) = 0;
        virtual void setZMax(const float z) = 0;
        virtual float getInterceptZ() const = 0;
        virtual void setInterceptZ(const float z) = 0;
        void addVertex(Point* p);
        void setVector(Vector* v);
        Point* getV1(void) const;
        Point* getV2(void) const;
        Point* getV3(void) const;
        Vector* getVector(void) const;
        bool operator==(const Triangle &t) const;
        bool operator!=(const Triangle &t) const;
		virtual void render(void);
        virtual void intercept() = 0;

	};

}

