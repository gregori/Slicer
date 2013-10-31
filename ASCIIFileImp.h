/* 
 * File:   ASCIIFileImp.h
 * Author: rodrigo
 *
 * Created on 8 de Agosto de 2013, 21:32
 */
#include <iostream>
#include "Point.h"
#include "Facet.h"
#include "GraphicsImp.h"

#ifndef ASCIIFILEIMP_H
#define	ASCIIFILEIMP_H

namespace ProcessPlanning
{
    class ASCIIFileImp 
        : public GraphicsImp
    {
    public:
        ASCIIFileImp();
        virtual ~ASCIIFileImp();

     	void cameraSetup(float zoom, float posX, float posY, float rotX, float rotY);
		void init(void);
		void prepareRenderRect(void);
		void prepareRenderTriangle(void);
		void prepareRenderPolygon(void);
		void finishRender(void);
		void drawPoint(Point *p);
		void drawTriangle(Facet *t);
		virtual void drawRect(Rect *r);
		virtual void resizeView(float posX, float posY);
		virtual void clearScreen(void);
		virtual void center3DObject(ComplexGeometry* cg);
    private:

    };
}

#endif	/* ASCIIFILEIMP_H */

