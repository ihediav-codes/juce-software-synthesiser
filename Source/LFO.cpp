/*
  ==============================================================================

    LFO.cpp

  ==============================================================================
*/

#include "LFO.h"
#include <math.h>
#define PI 3.141592654

LFO::LFO()
{
    m_fs = 44100;
    m_frequency = 1.0;
    m_phaseIncrement = (2*PI*m_frequency)/m_fs;
    m_currentPhase = 0.0;
    m_depth = 1.0;
    m_shape = kSine;
}

float LFO::process()
{
    float output = 0.0f;
    
    //get the next sample based on waveshape and depth
    switch(m_shape)
    {
        case kSine:
            output = renderSine(m_currentPhase) * m_depth; break;
        case kSquare:
            output = renderSquare(m_currentPhase) * m_depth; break;
        case kSaw:
            output = renderSaw(m_currentPhase) * m_depth; break;
        case kTriangle:
            output = renderTriangle(m_currentPhase) * m_depth; break;
        default:
            output = 0.0; break;
            
    }
  
    //increment the current phase
    m_currentPhase += m_phaseIncrement;
    
    if(m_currentPhase > 2.0*PI)
        m_currentPhase -= 2.0*PI;
    
    return output;
}

void LFO::setSamplingFrequency(float fs)
{
    m_fs = fs;
}

void LFO::setFrequency(float frequency)
{
    m_frequency = frequency;
    m_phaseIncrement = (2*PI*m_frequency)/m_fs;
    reset();
}

void LFO::setDepth(float depth)
{
    m_depth = depth;
}

void LFO::setWaveshape(Waveshape shape)
{
    m_shape = shape;
    reset();
}

float LFO::getFrequency()
{
    return m_frequency;
}

float LFO::getDepth()
{
    return m_depth;
}

Waveshape LFO::getWaveshape()
{
    return m_shape;
}

void LFO::reset()
{
    m_currentPhase = 0.0f;
}

//render different waveforms

double LFO::renderSine(double phase)
{
    return sin(phase); //simple rendering, but fine for current applications
}

double LFO::renderSquare(double phase)
{
    return phase < PI ? -1.0 : 1.0;
}

double LFO::renderSaw(double phase)
{
    return (1.0 / PI) * phase - 1.0;
}

double LFO::renderTriangle(double phase)
{
    return (phase < PI   ? -1.0 + (2.0 / PI) * phase
                                :  3.0 - (2.0 / PI) * phase);
}
