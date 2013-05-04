#ifndef SCENARIOS_SCENARIO_H_
#define SCENARIOS_SCENARIO_H_

#include "types.h"

namespace scenarios
{

class Scenario
{
protected:
    /** Number of cells */
    const unsigned int m_size;
    /** Domain size */
    const T m_domain;

public:
    Scenario(unsigned int size, T domain = 25.f)
        : m_size(size), m_domain(domain)
    {
    }

    /**
     * @return Initial water height at pos
     */
    virtual T getHeight(unsigned int pos)
    {
        return 0.0;
    }

    /**
     * @return Initial momentum at pos
     */
    virtual T getMomentum(unsigned int pos)
    {
            return 0.0;
    }
    
    /**
     * @return Bathymetry at pos
     */
    virtual T getBathymetry(unsigned int pos)
    {
            return -100.0;
    }

    /**
     * @return Cell size of one cell (= domain size/number of cells)
     */
    virtual T getCellSize()
    {
        return m_domain / m_size;
    }
};

}

#endif /* SCENARIOS_SCENARIO_H_ */
