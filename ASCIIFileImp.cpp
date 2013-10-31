/* 
 * File:   ASCIIFileImp.cpp
 * Author: rodrigo
 * 
 * Created on 8 de Agosto de 2013, 21:32
 */

#include "ASCIIFileImp.h"

namespace ProcessPlanning
{
    ASCIIFileImp::ASCIIFileImp() 
    {
    }

    ASCIIFileImp::~ASCIIFileImp() 
    {
    }
    
    void ASCIIFileImp::cameraSetup(float zoom, float posX, float posY, float rotX, float rotY)
    {
    }

	void ASCIIFileImp::init(void)
    {
    }

	void ASCIIFileImp::prepareRenderRect(void)
    {
    }

	void ASCIIFileImp::prepareRenderTriangle(void)
    {
    }

	void ASCIIFileImp::prepareRenderPolygon(void)
    {
    }

	void ASCIIFileImp::finishRender(void)
    {
    }

	void ASCIIFileImp::drawPoint(Point *p)
    {
        std::cout << p->getX() << " " << p->getY() << " " << p->getZ() << std::endl;
    }
	
	void ASCIIFileImp::drawRect(Rect *r)
	{
		Point *v1, *v2;
		v1 = static_cast<Point*>(r->getGeometry(0));
		v2 = static_cast<Point*>(r->getGeometry(1));
		
		std::cout << v1->getX() << " " << v1->getY() << " " << v1->getZ() << std::endl;
		std::cout << v2->getX() << " " << v2->getY() << " " << v2->getZ() << std::endl;
	}
	
	void ASCIIFileImp::center3DObject(ComplexGeometry *cg)
	{
	}

	void ASCIIFileImp::drawTriangle(Facet *t)
    {
        t->getV1()->render();
        t->getV2()->render();
        t->getV3()->render();
    }

	void ASCIIFileImp::resizeView(float posX, float posY)
    {
    }

	void ASCIIFileImp::clearScreen(void)
    {
    }

}
