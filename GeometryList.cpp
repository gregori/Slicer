#include "GeometryList.h"

namespace ProcessPlanning {
	
	GeometryList::GeometryList(void)
	{
	}


	GeometryList::~GeometryList(void)
	{
	}
	
	void GeometryList::insert(Geometry* item)
	{
		//lGeom.insert(item);
		lGeom.push_back(item);
	}

	Geometry* GeometryList::get(int index) const
	{
		//return lGeom.get(index);
		return lGeom[index];
	}
	
	void GeometryList::renderAllGeometries(void)
	{
		//List<Geometry>::Node<Geometry> *aux;
		Geometry* g;

		//for (aux = lGeom.getFirst(); aux != NULL; aux = aux->getNext())
		//{
		//	g = aux->getData();
		//	g->render();
		//}
		for (std::vector<Geometry*>::iterator it = lGeom.begin(); it != lGeom.end(); ++it) 
		{
			(*it)->render();
		}
		
	}

	int GeometryList::getSize(void) const
	{
		//return lGeom.getSize();
		return lGeom.size();
	}
	
}
