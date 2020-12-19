#pragma once
#include "core/core.h"
#include "core/game/finite_state_machine.h"
#include "gameplay/team_game/animation_fsm.h"

namespace team_game
{

	enum class ECharacterStates
	{
		Idle,
		Running,
		Dashing,
		InAir,
		DoubleJumping,
		Using,
		Attacking,
		Tossing,
		Dead
	};

	struct CharacterControllerFSM : public FSM<ECharacterStates>
	{
		AnimationFSM animationFSM;

		DEFINE_STATE(CharacterControllerFSM, ECharacterStates, Idle);
		DEFINE_STATE(CharacterControllerFSM, ECharacterStates, Running);
		DEFINE_STATE(CharacterControllerFSM, ECharacterStates, InAir);

		CharacterControllerFSM()
		{
			CONNECT_STATE(ECharacterStates, Idle);
			CONNECT_STATE(ECharacterStates, Running);
			CONNECT_STATE(ECharacterStates, InAir);
		}

		void Run(StateComponent& component_) override;
	};
}