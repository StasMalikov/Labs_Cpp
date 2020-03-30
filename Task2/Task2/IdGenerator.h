#pragma once
class IdGenerator
{
private:
	static int next_id;
public:
	static int getNextId();
};

