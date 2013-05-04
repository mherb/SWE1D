
#ifndef SCENARIOS_SUPERCRITICAL_H_
#define SCENARIOS_SUPERCRITICAL_H_

#include "types.h"
#include "Scenario.h"

namespace scenarios
{

class Supercritical : public Scenario
{
public:
	Supercritical(unsigned int size)
		: Scenario(size)
	{
	}


	/**
	 * @return Bathymetry at pos
	 */
	T getBathymetry(unsigned int pos) {
		if( pos > 8 && pos < 12)
			return -0.13f-(0.05f*(pos-10.0f)*(pos-10.0f));
		return -0.33f;
	}	
 
	/**
	 * @return Initial water height at pos
	 */
	T getHeight(unsigned int pos)
	{
		if (pos >= 0 && pos <= 25)
			return -getBathymetry(pos);
	}

	/**
	 * @return Initial momentum at pos
	 */
	T getMomentum(unsigned int pos) {
		if (pos >= 0 && pos <= 25)
			return 0.18f;	
	}
};

}

#endif /* SCENARIOS_SUPERCRITICAL_H_ */
