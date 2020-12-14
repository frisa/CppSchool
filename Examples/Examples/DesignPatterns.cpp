#include <iostream>

using namespace std;

class CSingleton
{
private:
	CSingleton() {};
	CSingleton(const CSingleton& other);
	const CSingleton& operator=(const CSingleton& other);
	~CSingleton() {}

public:
	static CSingleton& getInstance()
	{
		static CSingleton instance;
		return instance;
	}
	void print()
	{
		cout << __FUNCTION__ << endl;
	}
};

int main()
{
	cout << "Design Patterns Example" << std::endl;
	CSingleton::getInstance().print();
	return 0;
}