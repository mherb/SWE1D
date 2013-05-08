
#ifndef SCENARIOS_SUBCRITICAL_H_
#define SCENARIOS_SUBCRITICAL_H_

#include "types.h"
#include "Scenario.h"

namespace scenarios
{

class Subcritical : public Scenario
{
public:
	Subcritical(unsigned int size)
		: Scenario(size, 25.f)
	{
	}
    
	/**
	 * @return Bathymetry at pos
	 */
	T getBathymetry(unsigned int pos) {
        T intPos = internalPosition(pos);
		if( intPos > 8 && intPos < 12)
			return -1.8f - (0.05f * ( intPos - 10.0f ) * ( intPos - 10.0f ) );
		return -2;
	}	

	/**
	 * @return Initial water height at pos
	 */
	T getHeight(unsigned int pos) {
		return -getBathymetry(pos);        
	}

	/**
	 * @return Initial momentum at pos
	 */
	T getMomentum(unsigned int pos) {
		return 4.42f;
	}
};

}

#endif /* SCENARIOS_SUBCRITICAL_H_ */
