#pragma once

#include "Point.h"
#include "ComplexGeometry.h"
#include "Facet.h"
#include "Mesh.h"

namespace ProcessPlanning
{
	class GraphicsImp
	{
	protected:
		GraphicsImp();
		virtual ~GraphicsImp();

	public:
		virtual void cameraSetup(float zoom, float posX, float posY, float rotX, float rotY) = 0;
		virtual void init(void) = 0;
		virtual void prepareRenderRect(void) = 0;
		virtual void prepareRenderTriangle(void) = 0;
		virtual void prepareRenderPolygon(void) = 0;
		virtual void finishRender(void) = 0;
		virtual void drawPoint(Point *p) = 0;
		virtual void drawTriangle(Facet *t) = 0;
		virtual void drawRect(Rect *r) = 0;
		//virtual void draw3dGeometry(ComplexGeometry *cg) = 0;
		virtual void resizeView(float posX, float posY) = 0;
		virtual void clearScreen(void) = 0;
		virtual void center3DObject(ComplexGeometry* cg) = 0;
	};
}
