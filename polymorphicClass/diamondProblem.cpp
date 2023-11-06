#include <iostream>
#include <typeinfo>

using namespace std;


class Device
{
public:
	bool is_on()const
	{
		return mflag;
	}
	void turn_on()
	{
		mflag = true;
		cout << "Device opened\n";
	}
	void turn_off()
	{
		mflag = false;
		cout << "Device closed\n";
	}
private:
	bool mflag{};
};

// class Fax : virtual public Device {	// writing virtual inheritance will solve the problem
class Fax : public Device {
public:
	virtual void send_fax()
	{
		if (is_on())
		{
			cout << "sent fax\n";
		}
		else
			cout << "device is off, fax is not sent\n";
	}
	virtual void receive_fax()
	{
		if (is_on())
		{
			cout << "received fax\n";
		}
		else
			cout << "device is off, fax is not received\n";
	}
};

// class Modem : virtual public Device {	// writing virtual inheritance will solve the problem
class Modem : public Device {
public:
	virtual void send_data()
	{
		if (is_on())
		{
			cout << "sent data\n";
		}
		else
			cout << "device is off, data is not sent\n";
	}
	virtual void receive_data()
	{
		if (is_on())
		{
			cout << "received data\n";
		}
		else
			cout << "device is off, data is not received\n";
	}
};

class FaxModem : public Fax, public Modem
{
};
int main()
{
	FaxModem fm;
	fm.Fax::turn_on();
	fm.receive_fax();
	fm.send_data();// logical error
	fm.Modem::turn_off();
	fm.send_fax();	// logical error
};
