#pragma once
#include "List.h"
#include "Geometry.h"
#include <vector>

namespace ProcessPlanning
{
	class Geometry;

	class GeometryList
	{
	protected:
		//List<Geometry> lGeom;
		std::vector<Geometry*> lGeom;

	public:
		GeometryList(void);
		~GeometryList(void);
		void insert(Geometry* item);
		Geometry* get(int index) const;
		Geometry* getFirst() const;
		Geometry* getNext() const;
		void renderAllGeometries(void);
		int getSize(void) const;
	};
		
}
