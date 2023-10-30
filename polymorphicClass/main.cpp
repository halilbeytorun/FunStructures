#include <iostream>



///////
class Car
{
public:
	virtual void start()
	{
		std::cout << "Car has just started\n";
	}
	virtual void run()
	{
		std::cout << "Car is running now\n";
	}
	virtual void stop()
	{
		std::cout << "Car has just stopped\n";
	}
	void test_car()	// virtual dispatch mechanism will work again.
	{
		start();
		run();
		stop();
	}
};


class Volvo : public Car
{
public:
	void open_sunroof()
	{
		std::cout << "Volvo sunroof opened!!!\n";
	}
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "VOLVO Car has just started\n";
	}
	void run() override
	{
		std::cout << "VOLVO Car is running now\n";
	}
	void stop() override
	{
		std::cout << "VOLVO Car has just stopped\n";
	}
};


class VolvoXC90 : public Volvo
{
public:
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "VolvoXC90 Car has just started\n";
	}
	void run() override
	{
		std::cout << "VolvoXC90 Car is running now\n";
	}
	void stop() override
	{
		std::cout << "VolvoXC90 Car has just stopped\n";
	}
};

class Mercedes : public Car
{
public:
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "MERCEDES Car has just started\n";
	}
	void run() override
	{
		std::cout << "MERCEDES Car is running now\n";
	}
	void stop() override
	{
		std::cout << "MERCEDES Car has just stopped\n";
	}
};


class Opel : public Car
{
public:
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "OPEL Car has just started\n";
	}
	void run() override
	{
		std::cout << "OPEL Car is running now\n";
	}
	void stop() override
	{
		std::cout << "OPEL Car has just stopped\n";
	}
};

class Fiat : public Car
{
public:
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "FIAT Car has just started\n";
	}
	void run() override
	{
		std::cout << "FIAT Car is running now\n";
	}
	void stop() override
	{
		std::cout << "FIAT Car has just stopped\n";
	}
};

class Audi : public Car
{
public:
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "AUDI Car has just started\n";
	}
	void run() override
	{
		std::cout << "AUDI Car is running now\n";
	}
	void stop() override
	{
		std::cout << "AUDI Car has just stopped\n";
	}
};


class Honda : public Car
{
public:
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "HONDA Car has just started\n";
	}
	void run() override
	{
		std::cout << "HONDA Car is running now\n";
	}
	void stop() override
	{
		std::cout << "HONDA Car has just stopped\n";
	}
};


class Togg : public Car
{
public:
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "TOGG Car has just started\n";
	}
	void run() override
	{
		std::cout << "TOGG Car is running now\n";
	}
	void stop() override
	{
		std::cout << "TOGG Car has just stopped\n";
	}
};



class Dacia : public Car
{
public:
	void start() override	// should write override, writing virtual here does not matter, the word is in there by default once we override it from base class.
	{
		std::cout << "DACIA Car has just started\n";
	}
	void run() override
	{
		std::cout << "DACIA Car is running now\n";
	}
	void stop() override
	{
		std::cout << "DACIA Car has just stopped\n";
	}
};



#include <random>	// to generate random number.
Car* create_random_car()
{
	static std::mt19937 eng{ std::random_device{}() };
	static std::uniform_int_distribution dist{ 0, 8 };

	switch (dist(eng)) {
	case 0: return new Volvo;
	case 1: return new Opel;
	case 2: return new Audi;
	case 3: return new Honda;
	case 4: return new Fiat;
	case 5: return new Mercedes;
	case 6: return new Togg;
	case 7: return new VolvoXC90;
	case 8: return new Dacia;
	}
	return nullptr;
}
void car_game(Car* p)
{
	p->test_car();

	//p->start();
	//p->run();
	//p->stop();
	(void)getchar();

}
//
//void car_game(Car p)	// if it were like this, object slicing would occur virtual dispatch won't work...
//{
//	p->start();
//	p->run();
//	p->stop();
//	(void)getchar();
//}


int main()
{
	for (int i = 0; i < 10; i++)
	{
		Car* p = create_random_car();
		std::cout << "\n";
		car_game(p);
	}
}
