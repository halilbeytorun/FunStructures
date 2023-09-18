#include <iostream>
#include <string>
#include <vector>

class Fighter {
public:
	Fighter(const std::string& name) : m_name{ name }
	{
		svec.push_back(this);
	}
	~Fighter()
	{
		std::erase(svec, this);	// C++ 20 function
		// above function implements remove-erase idiom
	}
	void ask_help()
	{
		// range-based for loop.
		for (Fighter* p : svec)
		{
			if (p != this)
			{
				std::cout << p->m_name << " ";
			}
		}
	}
private:
	std::string m_name;
	static std::vector<Fighter*> svec;	// this is only decleration.
};

std::vector<Fighter*> Fighter::svec;

int main()
{
	Fighter f0{ "halo0" }, f1{ "halo1" }, f2{ "halo2" };

	f0.ask_help();
}



//*range based for loop
//for (T x : container)
//{
//}
//for (T& x : container)
//{
//}
//for (const T& x : container)
//{
//}
//for (auto val : container)
//{
//}
//for (const auto val : container)
//{
//}
//for (const auto& val : container)
//{
//}
//for (auto& val : container)
//{
//}
