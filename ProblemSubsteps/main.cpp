#include <iostream>

class SubstepStarter final
{
private:
	int stepCnt, substepCnt;

public:
	SubstepStarter() : stepCnt(0), substepCnt(0) {}

	bool start()
	{
		return substepCnt == stepCnt;
	}

	void end()
	{
		++substepCnt;
	}

	bool next_run()
	{
		++stepCnt;

		if (substepCnt > stepCnt) {
			substepCnt = 0;
			return true;
		}
		else
			return false;
	}
};

void run_substep(SubstepStarter& s)
{
	if (s.start()) {
		std::cout << '1';
	}
	s.end();

	if (s.start()) {
		std::cout << '2';
	}
	s.end();

	std::cout << '#';
}

void run_step(SubstepStarter& s)
{
	do {
		run_substep(s);
	} while (s.next_run());
}

int main()
{
	SubstepStarter s;
	run_step(s);
	return 0;
}