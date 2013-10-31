#pragma once
#include "Geometry.h"
#include "GeometryList.h"
#include "Graphics.h"

using namespace ProcessPlanning;

namespace ProcessPlanning
{
	class ComplexGeometry :
		public Geometry
	{
	private:
		float xMin, yMin, zMin;
		float xMax, yMax, zMax;
		double sphereRadius;
		Point* sphereCenter;	
		
	protected:
		GeometryList geomList;
	public:
		ComplexGeometry(void);
		~ComplexGeometry(void);
		void addGeometry(Geometry* geom);
        Geometry* getGeometry(const int index);
        int getSize(void) const;
		virtual void render(void);
		
		void setXMin(const float x);
		void setYMin(const float y);
		void setZMin(const float z);
		
		void setXMax(const float x);
		void setYMax(const float y);
		void setZMax(const float z);
		
		float getXMin(void) const;
		float getYMin(void) const;
		float getZMin(void) const;
		
		float getXMax(void) const;
		float getYMax(void) const;
		float getZMax(void) const;
		
		Point* getSphereCenter(void) const;
		void setSphereCenter(void);
		
		void setSphereRadius(void);
		double getSphereRadius(void) const;
	};

}
