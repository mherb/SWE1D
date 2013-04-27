#ifndef WAVEPROPAGATIONTEST_H_
#define WAVEPROPAGATIONTEST_H_
#include <cxxtest/TestSuite.h>
#include <types.h>
#include <WavePropagation.h>

#define private public
#define protected public

class WavePropagationTest : public CxxTest::TestSuite {
    private:
        /** relative tolerance for assertions */
        const static T REL_TOLERANCE = 0.5e-4;
        
        /** Number of cells */
        const static unsigned int SIZE = 100;
        
        /** Number of timesteps to compute */
        const static unsigned int TIMESTEPS = 100;
    private:
        T computeMiddleState(T h_l, T h_r, T hu_l, T hu_r) {
        	// Water height
        	T *h = new T[SIZE+2];
        	// Momentum
        	T *hu = new T[SIZE+2];
            
            // Set initial values (left side)
            for(int i = 0; i <= SIZE/2; i++) {
                h[i] = h_l;
                hu[i] = hu_l;
            }
            // Set initial values (right side)
            for(int i = SIZE/2+1; i < SIZE+2; i++) {
                h[i] = h_r;
                hu[i] = hu_r;
            }
            
            WavePropagation wavePropagation(h, hu, SIZE, 10.0/SIZE);
            
            // Run for certain period
            for(int t = 0; t < TIMESTEPS; t++) {
        		// Update boundaries
        		wavePropagation.setOutflowBoundaryConditions();

        		// Compute numerical flux on each edge
        		T maxTimeStep = wavePropagation.computeNumericalFluxes();

        		// Update unknowns from net updates
        		wavePropagation.updateUnknowns(maxTimeStep);
            }
            
            return h[SIZE/2];
        }
    public:
        void testMiddleStates() {
            T h_star;
            
            /*
                ShockShock: >>>> | <<<<
            */
            // 7781.912989633684,8054.840009903921,203.1276261791413,-122.4011484425361,7918.373220432552
            h_star = 7918.373220432552;
            TSM_ASSERT_DELTA(
                ">>>> | <<",
                (computeMiddleState(7781.912989633684,8054.840009903921,203.1276261791413,-122.4011484425361) - h_star) / h_star,
                0,
                REL_TOLERANCE);
            
            // 8709.32742637268,8398.943787972428,16.31677886119139,-297.5005775927029,8553.97985164423
            h_star = 8553.97985164423;
            TSM_ASSERT_DELTA(
                ">> | <<<<",
                (computeMiddleState(8709.32742637268,8398.943787972428,16.31677886119139,-297.5005775927029) - h_star) / h_star,
                0,
                REL_TOLERANCE);
            
            /*
                RareRare: <<<< | >>>>
            */
            // 8246.335606036884,7834.326652848147,-101.4664517025663,375.0676367556275,8038.143703952788
            h_star = 8038.143703952788;
            TSM_ASSERT_DELTA(
                "<< | >>>>",
                (computeMiddleState(8246.335606036884,7834.326652848147,-101.4664517025663,375.0676367556275) - h_star) / h_star,
                0,
                REL_TOLERANCE);
            
            // 3814.688047198105,4002.530660204575,-135.0359958085737,78.12536809677577,3907.494484009667
            h_star = 3907.494484009667;
            TSM_ASSERT_DELTA(
                "<<<< | >>",
                (computeMiddleState(3814.688047198105,4002.530660204575,-135.0359958085737,78.12536809677577) - h_star) / h_star,
                0,
                REL_TOLERANCE);
            
            /*
                Left: <<<< | <<<<
            */
            // 9363.07979812313,9538.622978955222,-77.49088144714374,-402.0715021452193,9451.17296172589
            h_star = 9451.17296172589;
            TSM_ASSERT_DELTA(
                "<< | <<<<",
                (computeMiddleState(9363.07979812313,9538.622978955222,-77.49088144714374,-402.0715021452193) - h_star) / h_star,
                0,
                REL_TOLERANCE);
            
            // 9765.619684772966,9656.918442715243,-242.5122752342027,-194.2713123297806,9711.118748907351
            h_star = 9711.118748907351;
            TSM_ASSERT_DELTA(
                "<<<< | <<",
                (computeMiddleState(9765.619684772966,9656.918442715243,-242.5122752342027,-194.2713123297806) - h_star) / h_star,
                0,
                REL_TOLERANCE);
            
            /*
                Right: >>>> | >>>>
            */
            // 9545.149896800789,9506.81392410783,265.0620480958033,87.06461442666324,9526.26224357462
            h_star = 9526.26224357462;
            TSM_ASSERT_DELTA(
                ">>>> | >>",
                (computeMiddleState(9545.149896800789,9506.81392410783,265.0620480958033,87.06461442666324) - h_star) / h_star,
                0,
                REL_TOLERANCE);

            // 5798.368717874997,5772.370154743168,234.0617759602983,599.8482522759736,5784.590510676296            
            h_star = 5784.590510676296;
            TSM_ASSERT_DELTA(
                ">> | >>>>",
                (computeMiddleState(5798.368717874997,5772.370154743168,234.0617759602983,599.8482522759736) - h_star) / h_star,
                0,
                REL_TOLERANCE);
            
            
        }
};


#endif /* WAVEPROPAGATIONTEST_H_ */
