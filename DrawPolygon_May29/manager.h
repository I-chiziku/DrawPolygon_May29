#pragma once
#include	<cinttypes>

// �O���Q��
class Application;

class Manager
{
private:

public:
	static void Init(Application* ap);
	static void Uninit();
	static void Update(uint64_t d);
	static void Draw(uint64_t d);
};