#pragma once

#include "Facet.h"

namespace ProcessPlanning
{
    class SimpleTriangle : public Facet
    {
        private:
		    float zMin;
		    float zMax;
            float interceptZ;

        public:
            SimpleTriangle();
            ~SimpleTriangle();

    		float getZMin() const;
    		float getZMax() const;
            void setZMin(const float z);
            void setZMax(const float z);
            float getInterceptZ() const;
            void setInterceptZ(const float z);
            Rect* intercept(const float z);
            bool operator<(const SimpleTriangle &rt) const;
            bool checkInterception(const float z) const;
    };
}
