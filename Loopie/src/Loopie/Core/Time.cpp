#include "Time.h"
#include <SDL3/SDL_timer.h>
namespace Loopie
{
	Time::Time()
	{
	}
	void Time::CalculateFrame()
	{
		Uint64 now = SDL_GetPerformanceCounter();
		if (m_lastFrameTime != 0)
		{
			m_deltaTimeMs = (float)((now - m_lastFrameTime) * 1000.0 / (double)SDL_GetPerformanceFrequency());
		}
		else
		{
			m_deltaTimeMs = 0.0f;
		}
		m_lastFrameTime = now;
	}
}