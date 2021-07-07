#ifndef COINTOSS_H
#define COINTOSS_H
#include <string>
using namespace std;

class coinToss
{
private:
	string sideUp;
public:
	coinToss();
	void toss();
	string getSideUp();
};
#endif 
