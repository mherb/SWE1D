
#ifndef SCENARIOS_VILLAGE_H_
#define SCENARIOS_VILLAGE_H_

#include "types.h"
#include "Scenario.h"

namespace scenarios
{

class Village : public Scenario
{
private:
    /**Dam position */
    unsigned int m_dam_pos;
public:
	Village(unsigned int size)
		: Scenario(size, 50000.f)
	{
        // Dam at 25k (50k/2)
        // | <- 25km -> [dam] <- 25 km -> [village]
        m_dam_pos = m_size/2;
	}

	/**
	 * @return Initial water height at pos
	 */
	T getHeight(unsigned int pos)
	{
		if (pos <= m_dam_pos)
			return 14;
		return 3.5;
	}

        /**
         * @return Initial momentum at pos
         */
	T getMomentum(unsigned int pos) {
		if( pos <= m_dam_pos)
			return 0;
		return 0.7;	
	}
};

}

#endif /* SCENARIOS_VILLAGE_H_ */
