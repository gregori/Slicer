#include "Mesh.h"
#include "OpenGLImp.h"
#include "GraphicsImp.h"
#include <cmath>
#include <iostream>
#include <stdio.h>

using namespace std;

namespace ProcessPlanning
{
	Mesh::Mesh(void)
	{
        ifCounter = 0;
		sliceCounter = 0;
		heightSum = 0.0;
	}

	Mesh::~Mesh(void)
	{
	}
    
    int Mesh::getIfCounter()
    {
        return ifCounter;
    }
	
	int Mesh::getSliceCounter()
	{
		return sliceCounter;
	}
	
	void Mesh::incIfCounter()
	{
		ifCounter++;
	}
	
	void Mesh::incSliceCounter()
	{
		sliceCounter++;
	}
	
    void Mesh::addTriangle(Facet *t)
    {
        addGeometry(static_cast<Geometry*>(t));
		heightSum += t->getFacetHeight();
        orderedInsertTriangle(t);
    } 

    Facet* Mesh::getTriangle(Facet* t) const
    {
        //traverse list and compares the triangle
		return NULL;
    }
	
	Slice* Mesh::getSlice()
	{
		Slice *s = new Slice();
		Contour *c = new Contour();
		
		while (!segments.empty())
        {
            segIt = segments.begin();
            std::string lbl = static_cast<Point*>(segIt->second->getGeometry(0))->getLabel();
			
            while (segments.count(lbl))
            {				
				//if (lbl.compare("50.79235|15.27517|75.54418") == 0)
//					std::cout << lbl << std::endl;
				Rect *l = segments[lbl];
				c->addGeometry(l);
				segments.erase(segments.find(lbl));
				Point *p2 = static_cast<Point*>(l->getGeometry(1));
				lbl = p2->getLabel();
            }
            c->setInterface(new Graphics(static_cast<GraphicsImp*>(new OpenGLImp())));
			s->addGeometry(c);
			c = new Contour();
        } 
		
		return s;
	}
	
	float Mesh::getAvgFacetHeight(void)
	{
		//float heightSum = 0.0;
		
		//for (int i = 0; i < this->getSize(); i++)
		//{
		//	heightSum += static_cast<Facet*>(this->getGeometry(i))->getFacetHeight();
		//}
		
		return heightSum / this->getSize();
	}
	
}


