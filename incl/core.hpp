#ifndef AP_PROJECT_AP_CORE_HPP
#define AP_PROJECT_AP_CORE_HPP

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <zthread/Thread.h>
#include <zthread/Condition.h>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "calculationloop.hpp"
#include "MPU6050.h"

class ApCore
{
public:
    ApCore();
	~ApCore();

	void reset();
	void start();
	void pause();
	void quit();
	void run();
private:
	void configSensor();

	void configure();
	boost::scoped_ptr<ZThread::Thread> m_thread;
	int m_counter;
	boost::posix_time::ptime m_localTime;
	bool m_runProcess;
	boost::shared_ptr<MPU6050> m_sensor;
};

#endif // AP_PROJECT_AP_CORE_HPP
