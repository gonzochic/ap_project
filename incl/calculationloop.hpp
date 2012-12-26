#ifndef AP_PROJECT_CALCULATION_LOOP_HPP
#define AP_PROJECT_CALCULATION_LOOP_HPP

#include <zthread/Runnable.h>

class CalculationLoop : public ZThread::Runnable
{
public:
	CalculationLoop();
	~CalculationLoop();

	void run();
private:

};


#endif // AP_PROJECT_CALCULATION_LOOP_HPP
