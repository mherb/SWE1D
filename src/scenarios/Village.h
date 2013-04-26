
#ifndef SCENARIOS_VILLAGE_H_
#define SCENARIOS_VILLAGE_H_

#include "types.h"

namespace scenarios
{

class Village
{
private:
	/** Number of cells */
	const unsigned int m_size;
    
    /**Dam position */
    unsigned int m_dam_pos;
public:
	Village(unsigned int size)
		: m_size(size)
	{
        // at 5k (30k/6)
        // | <- 5km -> [dam] <- 25 km -> [village]
        m_dam_pos = m_size/6;
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

	T getMomentum(unsigned int pos) {
		if( pos <= m_dam_pos)
			return 0;
		return 0.7;	
	}

	/**
	 * @return Cell size of one cell (= domain size/number of cells)
	 */
	T getCellSize()
	{
		return 30000.f / m_size;
	}
};

}

#endif /* SCENARIOS_VILLAGE_H_ */
