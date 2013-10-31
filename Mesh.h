#pragma once
#include "Facet.h"
#include "ComplexGeometry.h"
#include "Slice.h"
#include "Contour.h"
#include "Point.h"
#include "PointFactory.h"
#include <map>

using namespace std;

namespace ProcessPlanning
{

	class Mesh :
		public ComplexGeometry
	{
    protected:
        int ifCounter;
		int sliceCounter;
		float heightSum;
		map<std::string, Rect*> segments;
        map<std::string, Rect*>::iterator segIt;
		
		virtual Slice* getSlice();

	public:
		Mesh(void);
		~Mesh(void);

		Facet* getTriangle(Facet *t) const;
        void addTriangle(Facet *t);
        int getIfCounter();
		int getSliceCounter();
        virtual void orderedInsertTriangle(Facet *t) = 0;
        virtual Slice* interceptTriangles(float z) = 0;
		void incIfCounter();
		void incSliceCounter();
		float getAvgFacetHeight(void);
	};

}
