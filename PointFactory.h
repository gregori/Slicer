#pragma once
#include "Point.h"
#include "Graphics.h"
#include <map>
#include <algorithm>

using namespace std;

namespace ProcessPlanning
{

	class PointFactory
	{
	private:
		typedef map<std::string, Point*> PMap;
		typedef map<std::string, Point*>::iterator PMapIterator;
		static PMap points;
		static Graphics* gr;
	public:
		PointFactory(void);
		~PointFactory(void);
		static Point* getPoint(const float x, const float y, const float z);
		static void setGraphics(Graphics* g);
	};

}
