#include <stdexcept>
#include <algorithm>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string & question) : question(question) {}
	bool isDuplicatedNumber(const string& guessNumber) {
		if (guessNumber[0] == guessNumber[1]) return true;
		if (guessNumber[0] == guessNumber[2]) return true;
		if (guessNumber[1] == guessNumber[2]) return true;
		return false;
	}
	void assertIllegalArgument(const string& guessNumber) {
		if (guessNumber.length() != 3) throw length_error("Must be three letters.");
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber)) throw invalid_argument("Must not have same number");
	}
	void countStrikeOrBall(const string& guessNumber) {
		for (register int i = 0; i < 3; i++) {
			auto idx = find(question.begin(), question.end(), guessNumber[i]);
			if (idx - question.begin() == i) num_strikes++;
			else if (idx != question.end()) num_balls++;
		}
	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if(guessNumber == question) return { true, 3, 0 };
		countStrikeOrBall(guessNumber);
		return { false, num_strikes, num_balls };
	}
private:
	string question;
	int num_strikes = 0;
	int num_balls = 0;
};