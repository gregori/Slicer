#pragma once
#include "ComplexGeometry.h"
#include "Vector.h"
#include "Point.h"
#include "Graphics.h"
#include "Rect.h"

namespace ProcessPlanning
{
	class Facet :
		public ComplexGeometry
	{
	private:
        Vector* normal;
	public:
		Facet(void);
		~Facet(void);
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
        bool operator==(const Facet &t) const;
        bool operator!=(const Facet &t) const;
		virtual void render(void);
        virtual Rect* intercept(const float z) = 0;
		float getFacetHeight(void) const;
	};

}

