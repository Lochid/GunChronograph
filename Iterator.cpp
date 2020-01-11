#include "Iterator.h"

void Iterator::setProgress()
{
    _progress = (double)_iteration / _maximalIteration;
}

void Iterator::setComplete()
{
    _complete = getPartValue() - 1 < 0.001;
}

Iterator::Iterator(unsigned int maximalIteration)
{
    _iteration = 0;
    _maximalIteration = maximalIteration;
    setProgress();
    setComplete();
}

unsigned int Iterator::getIteration()
{
    return _iteration;
}

double Iterator::getPartValue()
{
    return _progress;
}

bool Iterator::getCompleteStatus()
{
    return _complete;
}

void Iterator::next()
{
    _iteration++;
    setProgress();
    setComplete();
}

void Iterator::reset()
{
    _iteration = 0;
    setProgress();
    setComplete();
}
