#ifndef FUNC_H
#define FUNC_H

struct Kolor
{
	int r, g, b;
};
struct Wspolrzedne
{
	double x, y;
};

class CCzolg
{
private:
	double pozycja;
	double kat;
	double shootX, shootY;
	double width, high;
	Kolor barwa;
	double strona;
public:
	void setShootX(double x);
	void setShootY(double y);
	void setPozycja(double poz);
	void setKat(double _kat);
	void setWidth(double w);
	void setHigh(double h);
	void setKolor(Kolor _barwa);
	void setStrona(double s);

	double showShootX();
	double showShootY();
	double showKat();
	double showPozycja();

	void DrawCzolg(void);
	void DrawPocisk(void);
};

void czas1(int value);
void czas2(int value);
void display(void);
void DrawZiemia(void);
void sterowanie(unsigned char key, int x, int y);

void inicjacja1();
void inicjacja2();

#endif