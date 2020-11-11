#pragma once

#include "core/system.h"
#include "core/core.h"

using namespace dagger;

namespace ping_pong
{
    struct ControllerMapping
    {
        EDaggerKeyboard up_key;
        EDaggerKeyboard down_key;

		EDaggerKeyboard boost_key;

		static constexpr float s_frozenMaxTime = 3.0f;
		static constexpr float s_boostMaxTime = 1.0f;
		static constexpr float s_boostSpeedIncrease = 2.0f;

		bool boosting = false;
		float boostLeft = ControllerMapping::s_boostMaxTime;

		bool frozen = false;
		float frozenFor;

        Vector2 input{ 0, 0 };
    };

    class PingPongPlayerInputSystem
        : public System
    {
        static Float32 s_BoarderUp;
        static Float32 s_BoarderDown;

    public:

        static Float32 s_PlayerSpeed;

    public:
        inline String SystemName() { return "PingPong Player Input System"; }

        void SpinUp() override;
        void WindDown() override;
        void Run() override;

        static void SetupPlayerOneInput(ControllerMapping& controllerMapping_)
        {
            controllerMapping_.up_key = EDaggerKeyboard::KeyW;
            controllerMapping_.down_key = EDaggerKeyboard::KeyS;

			controllerMapping_.boost_key = EDaggerKeyboard::KeyLeftShift;
        }

        static void SetupPlayerTwoInput(ControllerMapping& controllerMapping_)
        {
            controllerMapping_.up_key = EDaggerKeyboard::KeyUp;
            controllerMapping_.down_key = EDaggerKeyboard::KeyDown;

			controllerMapping_.boost_key = EDaggerKeyboard::KeyRightShift;
        }

        static void SetupPlayerBoarders(Float32 boarderUp_, Float32 boarderDown_)
        {
            s_BoarderUp = boarderUp_;
            s_BoarderDown = boarderDown_;
        }

    private:

        void OnKeyboardEvent(KeyboardEvent kEvent_);
    };
}