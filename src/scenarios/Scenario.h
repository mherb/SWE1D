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
    /** 
     * Maps an external cell position to an internal, continuous position
     * in the domain size (0,*domain*).
     *
     * External (cell) position 0 maps to domain position 0
     * External (cell) position size+2 maps to domain position *domain*
     *
     * @param pos The external cell position
     * @return Internal position in the domain
     */
    T internalPosition(unsigned int pos) {
        return pos * (m_domain / (m_size+2));
    }

public:
    Scenario(unsigned int size, T domain = 1000.f)
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
