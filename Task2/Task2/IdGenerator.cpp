#include "pch.h"
#include "IdGenerator.h"

int IdGenerator::getNextId()
{
	return next_id++;
}
