#include "SPlayerState.h"

void ASPlayerState::AddCredits(int32 Delta)
{
	if (!ensure(Delta > 0.0f)) return;

	Credits += Delta;
	OnCreditsChanged.Broadcast(this, Credits, Delta);
}


bool ASPlayerState::RemoveCredits(int32 Delta)
{
	if (!ensure(Delta > 0.0f)) return false;
	if (Credits < Delta)return false;

	Credits -= Delta;
	OnCreditsChanged.Broadcast(this, Credits, -Delta);

	return true;
}
