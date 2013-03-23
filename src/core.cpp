#include "core.hpp"

#include <iostream>
#include <boost/bind.hpp>
#include <zthread/SynchronousExecutor.h>

#include "calculationloop.hpp"

const long CALCULATION_LOOP_SYNC_RATE_MS(50);


ApCore::ApCore():
	m_counter(0),
	m_localTime(boost::posix_time::microsec_clock::local_time()),
	m_runProcess(true)
{
	this->reset();
	std::cout << m_localTime << std::endl; 
}
ApCore::~ApCore()
{
	std::cout << "DTOR Core" << std::endl;
}

void ApCore::reset()
{
	std::cout << "Reset Core" << std::endl;
	m_counter = 0;
}

void ApCore::start()
{
	std::cout << "Start Thread" << std::endl;
	try
		{
			std::cout << "Test" << std::endl;
			m_localTime = boost::posix_time::microsec_clock::local_time();
			
			ZThread::SynchronousExecutor executor;
			
			while (m_runProcess) {

				boost::posix_time::time_period 
					timeDifference(m_localTime,boost::posix_time::microsec_clock::local_time()); 
				
				if (timeDifference.length() >= boost::posix_time::milliseconds(CALCULATION_LOOP_SYNC_RATE_MS)) {
					
					m_localTime = boost::posix_time::microsec_clock::local_time();
					std::cout << timeDifference.length() << std::endl; 
					executor.execute(new CalculationLoop());
				}
			
			}
			
		} catch(ZThread::Synchronization_Exception& e) {
		std::cerr << e.what() << std::endl;
		} catch (...) {
		std::cerr << "Unknown ERROR" << std::endl;
		}
}

void ApCore::pause()
{
	std::cout << "Pause Thread" << std::endl;
}


void ApCore::quit()
{
	std::cout << "Quit Core" << std::endl;
	this->reset();

}

void ApCore::run()
{
	std::cout << "Run-> Counter: " << m_counter << std::endl;
}
