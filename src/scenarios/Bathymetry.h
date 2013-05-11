
#ifndef SCENARIOS_BATHYMETRY_H_
#define SCENARIOS_BATHYMETRY_H_

#include <cmath>

#include "types.h"
#include "Scenario.h"

namespace scenarios
{

/**
* Scenario to show off bathymetry handling
*/
class Bathymetry : public Scenario
{
public:
	Bathymetry(unsigned int size)
		: Scenario(size, 18.0f)
	{
	}
    
	/**
	 * @return Bathymetry at pos
	 */
	T getBathymetry(unsigned int pos) {
        T x = internalPosition(pos);
        return (tanh(x - 15) + 5 * (tanh(x - 6) - 1))+0.8;
	}	
 
	/**
	 * @return Initial water height at pos
	 */
	T getHeight(unsigned int pos) {
		T b = getBathymetry(pos);
        if(b >= 0.0)
            return 0.0;
        return -b;
	}

	/**
	 * @return Initial momentum at pos
	 */
	T getMomentum(unsigned int pos) {
        if(pos <= m_size/10)
            return 20;
        return 0;
	}
};

}

#endif /* SCENARIOS_BATHYMETRY_H_ */
