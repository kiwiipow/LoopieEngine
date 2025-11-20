namespace Loopie {
	class Time
	{
	private:
		Time();
		~Time() = default;
	public:
		void CalculateFrame();
	private:
		float m_lastFrameTime = 0;

		static float m_frameCount;
		//Physic
		static float m_fixedDeltaTimeMs;

		// Game Clock
		static float m_time;
		static float m_timeScale;
		static float m_deltaTimeMs;

		//Real Time Clock
		static float m_realTimeGameStart;
		static float m_realTimeDeltaTime;

	public:
		static float DeltaTime() { return m_deltaTimeMs / 1000; }
		static float DeltaTimeMs() { return m_deltaTimeMs; }
		static float FixedDeltaTime() { return m_fixedDeltaTimeMs / 1000; }
		static float TimeScale() { return m_timeScale; }
	};
}