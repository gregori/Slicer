#pragma once
#include "Mesh.h"
#include "Solid.h"
#include "Rect.h"
#include <map>

namespace ProcessPlanning
{

	class Slicer
	{
    protected:
		float sliceThickness;
		int segmentTime;
		int sliceTime;
		virtual Slice* getSlice(std::map<std::string, Rect*> segments);
		
	public:
		Slicer(void);
		virtual ~Slicer(void);
		
		float getSliceThickness(void) const;
        void setSliceThickness(const float st);
		void setSegmentTime(const int sTime);
		void incSegmentTime(const int sTime);
		int getSegmentTime(void) const;
		void setSliceTime(const int sTime);
		void incSliceTime(const int sTime);
		int getSliceTime(void) const;

        virtual Solid* sliceMesh(Mesh* m)=0;
	};

}
