
#ifndef SCENARIOS_SUPERCRITICAL_H_
#define SCENARIOS_SUPERCRITICAL_H_

#include "types.h"
#include "Scenario.h"

namespace scenarios
{

/**
* Scenario causing a supercritical state (Froude number > 1)
*/
class Supercritical : public Scenario
{
public:
	Supercritical(unsigned int size)
		: Scenario(size, 25.f)
	{
	}
    
	/**
	 * @return Bathymetry at pos
	 */
	T getBathymetry(unsigned int pos) {
        T intPos = internalPosition(pos);
		if( intPos > 8 && intPos < 12)
			return -0.13f - ( 0.05f * ( intPos - 10.0f ) * ( intPos - 10.0f ) );
		return -0.33f;
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
		return 0.18f;	
	}
};

}

#endif /* SCENARIOS_SUPERCRITICAL_H_ */
