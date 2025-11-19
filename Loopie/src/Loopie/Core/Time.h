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
		float m_deltaTime = 0;
		float m_deltaTimeMs = 0;
		float m_fixedDeltaTime = 1;
		float m_timeScale = 1;
	public:
		static float DeltaTime();
		static float DeltaTimeMS();
		static float FixedDeltaTime();
		static float TimeScale();
	};
}