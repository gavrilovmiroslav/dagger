#pragma once

#include "engine.h"
#include "events.h"

#include <spdlog/spdlog.h>
#include <atomic>
#include <chrono>

struct FrameCountSystem : public dagger::System
{
	using TimePoint = std::chrono::time_point< std::chrono::steady_clock>;
	using Duration = std::chrono::duration<double>;

	uint64_t m_FrameCounter;
	TimePoint m_LastFrameTime;
	Duration m_DeltaTime;

	void Tick(dagger::Frame)
	{
		static TimePoint nextTime;

		nextTime = std::chrono::steady_clock::now();
		m_DeltaTime += (nextTime - m_LastFrameTime);
		m_LastFrameTime = nextTime;
		m_FrameCounter++;
	}

	void SpinUp(dagger::Engine& engine_) override
	{
		engine_.GetDispatcher().sink<dagger::Frame>().connect<&FrameCountSystem::Tick>(this);
	}

	void Run(dagger::Engine&) override
	{
		auto delta = m_DeltaTime.count();
		if (delta >= 1.0)
		{
			spdlog::info("FPS: {} ({})", m_FrameCounter, delta);
			m_FrameCounter = 0;
			m_DeltaTime = Duration::zero();
		}
	}

	void WindDown(dagger::Engine& engine_) override
	{
		engine_.GetDispatcher().sink<dagger::Frame>().disconnect<&FrameCountSystem::Tick>(this);
	}
};

