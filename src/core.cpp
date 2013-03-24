#include "core.hpp"

#include <iostream>
#include <boost/bind.hpp>
#include <zthread/SynchronousExecutor.h>

#include "calculationloop.hpp"

const long CALCULATION_LOOP_SYNC_RATE_MS(50);


ApCore::ApCore():
	m_counter(0),
	m_localTime(boost::posix_time::microsec_clock::local_time()),
	m_runProcess(true),
	m_sensor(new MPU6050())
{
	this->reset();
	m_sensor->initialize();

	this->configSensor();
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
					int16_t x,y,z;
					int imax = std::numeric_limits<int16_t>::max();
					std::cout << imax << std::endl;	
					m_sensor->getAcceleration(&x, &y, &z);
					m_localTime = boost::posix_time::microsec_clock::local_time();
					double xx((static_cast<double>(x)/imax) * 2 * 9.81);
					double xy((static_cast<double>(y)/imax) * 2 * 9.81);
					double xz((static_cast<double>(z)/imax) * 2 * 9.81);
					std::cout << "X: " << xx << " - Y: " << xy << " - Z: " << xz << std::endl; 
					
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

void ApCore::configSensor()
{
	// 0 = 2g
	m_sensor->setFullScaleAccelRange(0);
	std::cout << "Sensitiviy: " << m_sensor->getFullScaleAccelRange() << std::endl;
}
