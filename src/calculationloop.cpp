#include "calculationloop.hpp"

#include <iostream>

#include "dataholder.hpp"

CalculationLoop::CalculationLoop()
{
}

CalculationLoop::~CalculationLoop()
{}

void CalculationLoop::run()
{
	DataHolder::instance().writeToConsole("Run the Dataholder");
}
