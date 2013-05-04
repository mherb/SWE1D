
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
		: Scenario(size)
	{
	}


	/**
	 * @return Bathymetry at pos
	 */
	T getBathymetry(unsigned int pos) {
		if( pos > 8 && pos < 12)
			return -1.8f-(0.05f*(pos-10.0f)*(pos-10.0f));
		return -2;
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
			return 4.42f;
	}
};

}

#endif /* SCENARIOS_SUBCRITICAL_H_ */
