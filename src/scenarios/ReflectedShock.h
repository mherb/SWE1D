
#ifndef SCENARIOS_REFLECTEDSHOCK_H_
#define SCENARIOS_REFLECTEDSHOCK_H_

#include "types.h"
#include "Scenario.h"
#include "WavePropagation.h"

namespace scenarios
{

/**
* Scenario showing a shock wave reflected on the right boundary
*/
class ReflectedShock : public Scenario
{
public:
	ReflectedShock(unsigned int size)
		: Scenario(size)
	{
	}
    
    /**
     * @return Initial water height at pos
     */
    T getHeight(unsigned int pos)
    {
    	return 25;
    }

    /**
     * @return Initial momentum at pos
     */
    T getMomentum(unsigned int pos) {
    	return 10;	
    }
    
    unsigned int getOutflowBoundaries()
    {
        // Set outflow boundary on the left
        // and therefore reflecting boundary on the right
        return WavePropagation::BOUNDARY_LEFT;
    }
};

}

#endif /* SCENARIOS_REFLECTEDSHOCK_H_ */
