#ifndef AP_PROJECT_AP_CORE_HPP
#define AP_PROJECT_AP_CORE_HPP

#include <boost/scoped_ptr.hpp>
#include <zthread/Thread.h>
#include <zthread/Condition.h>
#include <boost/date_time/posix_time/posix_time.hpp>


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
	void configure();
	boost::scoped_ptr<ZThread::Thread> m_thread;
	int m_counter;
	boost::posix_time::ptime m_localTime;
	bool m_runProcess;
};

#endif // AP_PROJECT_AP_CORE_HPP
