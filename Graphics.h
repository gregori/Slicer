#pragma once

namespace ProcessPlanning
{
	class GraphicsImp;
	class Facet;
	class Point;
	class Rect;
	class Raster;
	class Contour;
	class Mesh;
	class ComplexGeometry;
	class Graphics
	{
	private:
		GraphicsImp* imp;

	public:
		Graphics(GraphicsImp* implementation = NULL);
		~Graphics();

		void init(void);
		void render(Point* p);
		void render(Facet* t);
		void render(Rect* r);
		void prepareRender(Point* p);
		void prepareRender(Rect* r);
		void prepareRender(Facet* t);
		void prepareRender(Raster* r);
		void prepareRender(Contour* c);
		void prepareRender(Mesh* m);
		void prepareRender(ComplexGeometry *cg);
		void finishRender(void);
		void resizeView(float posX, float posY);
		void clearScreen(void);
		void cameraSetup(float zoom, float posX, float posY, float rotX, float rotY);

	};
}
