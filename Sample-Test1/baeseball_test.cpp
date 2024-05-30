#include "pch.h"
#include "../baseball/baseball.cpp"


TEST(BaseballGame, ThrowExceptionWhenInputLengthIsHnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}