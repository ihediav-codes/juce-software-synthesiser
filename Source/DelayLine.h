/*
  DelayLine.h

  Created by Matthew Stephenson on 11/11/2015
  University of Huddersfield
  Copyright 2015 Matthew Stephenson

  License:
  This source code is provided as is, without warranty.
  You may copy and distribute verbatim copies of this document.
  You may modify and use this source code to create binary code for your own purposes, free or commercial.
*/

#ifndef DELAYLINE_H_INCLUDED
#define DELAYLINE_H_INCLUDED

#include <JuceHeader.h>

class DelayLine
{
public:

    DelayLine();
    ~DelayLine();
    
	//initialise function sets up the circular buffer
	//so MUST be called before using the DelayLine
    void initialise(float sampleRate, float maxDelayMS);
    void reset();
    
	//processes a single sample through the delay line
	//sample is passed by reference, with 'in' being 
	//overwritten with the delayed output sample
    void process(float& in);

	//delay time should be set in milliseconds
    void setDelay(float delayInMS);
    float getDelay();
    
private:
    
	//buffer
	juce::AudioSampleBuffer m_buffer;
    long m_bufferSize;

	//delay parameters
	float m_delayInSamples;

	//control variables
    long m_indexRead;
    long m_indexWrite;
    float m_currentSampleRate;
    
};

#endif  // DELAYLINE_H_INCLUDED