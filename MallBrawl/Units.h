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

////and inventory
//template<typename T>
//struct Vector
//{
//private:
//	int capacity;
//public:
//	Vector() : capacity(10)
//	{
//		bag = new T[capacity];
//	}
//};
#pragma endregion