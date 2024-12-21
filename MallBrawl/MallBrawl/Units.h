#pragma once
#pragma region Templates
//wanted me to define all previous functions if placed at the top.
template <typename T>
T getMax(T hitNum, T unitAccuracy)
{
	//if random hit chance is less than or equal to unit accuracy, the move hits
	if (hitNum <= unitAccuracy)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
T manaCheck(T manaCost, T currentMana)
{
	//if the mana cost is less than or equal to the unit's mana, allow it
	if (manaCost <= currentMana)
	{
		return true;
	}
	//otherwise, prevent the action
	else
	{
		return false;
	}
}

//template <typename T>
//vector<T> inventory = { basicItem, basicItem, basicItem };	

//template <typename T>

#pragma endregion