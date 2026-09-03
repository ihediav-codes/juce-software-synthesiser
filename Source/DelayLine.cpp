/*
DelayLine.cpp

Created by Matthew Stephenson on 11/11/2015
University of Huddersfield
Copyright 2015 Matthew Stephenson

License:
This source code is provided as is, without warranty.
You may copy and distribute verbatim copies of this document.
You may modify and use this source code to create binary code for your own purposes, free or commercial.
*/

#include "DelayLine.h"

DelayLine::DelayLine()
{
	m_delayInSamples = 0.0;
	m_bufferSize = 0;
	m_indexRead = 0;
	m_indexWrite = 0;
	m_currentSampleRate = 0;
}

DelayLine::~DelayLine()
{
}

void DelayLine::initialise(float sampleRate, float maxDelayMS)
{
	m_bufferSize = (maxDelayMS*0.001*sampleRate);
	m_buffer.setSize(1,m_bufferSize,false);
	reset();

	//we need to store the sample rate in our class so we can convert
	//incoming delay times in MS into samples
    m_currentSampleRate = sampleRate;
}

void DelayLine::reset()
{
	//flush the buffer - fill it with zeroes
	m_buffer.clear(0,0,m_bufferSize);

    //reset indexes
    m_indexRead = 0;
    m_indexWrite = 0;
}

void DelayLine::process(float& in)
{
	//get a pointer to the circular buffer
	float* buff = m_buffer.getWritePointer(0);

    float xn = in;
	float yn = buff[m_indexRead];

    if(m_delayInSamples == 0)
        yn = xn;

	buff[m_indexWrite] = xn;

    m_indexRead++;
    if(m_indexRead >= m_bufferSize)
        m_indexRead = 0;
        
    m_indexWrite++;
    if(m_indexWrite >= m_bufferSize)
        m_indexWrite = 0;
        
	in = yn;
}

void DelayLine::setDelay(float delayInMS)
{
	m_delayInSamples = delayInMS * m_currentSampleRate * 0.001;

	m_indexRead = m_indexWrite - m_delayInSamples;
	if (m_indexRead < 0)
		m_indexRead += m_bufferSize;
}

float DelayLine::getDelay()
{
	return m_delayInSamples/m_currentSampleRate * 1000;
}