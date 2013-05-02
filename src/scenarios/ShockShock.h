
#ifndef SCENARIOS_SHOCKSHOCK_H_
#define SCENARIOS_SHOCKSHOCK_H_

#include "types.h"
#include "Scenario.h"

namespace scenarios
{

class ShockShock : public Scenario
{
public:
	ShockShock(unsigned int size)
		: Scenario(size)
	{
	}

	/**
	 * @return Initial water height at pos
	 */
	T getHeight(unsigned int pos)
	{
		if (pos <= m_size/2)
			return 25;

		return 25;
	}

	/**
	 * @return Initial momentum at pos
	 */
	T getMomentum(unsigned int pos) {
		if( pos <= m_size / 2)
			return 10;
		return -10;	
	}
};

}

#endif /* SCENARIOS_SHOCKSHOCK_H_ */
