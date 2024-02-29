#include <iostream>

using namespace std;

class Tools
{
public:
	void apply()
	{
		cout << "Tuk-tuk";
	}
	Tools(int value)
	{
		weight = value;
	}
private:
	int weight;
	
};


int main()
{
	Tools molotok(12);
	molotok.apply();
}