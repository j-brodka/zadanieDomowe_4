#include <iostream>
#include <math.h>
#include "func.h"
#define PI 3.14159265

#include <GL/freeglut.h>

CCzolg gracz1, gracz2;
double t1=0, t2=0;
Wspolrzedne gracz1_poz, pocisk1_poz, gracz2_poz, pocisk2_poz;


void inicjacja1()
{
	gracz1_poz.x=-3.5;
	gracz1_poz.y=0.29;
	pocisk1_poz.x=-3.5;
	pocisk1_poz.y=0.29;

	gracz1.setKat(0);
	gracz1.setPozycja(-3.5);
	gracz1.setShootX(0);
	gracz1.setShootY(0);
	gracz1.setWidth(0.5);
	gracz1.setHigh(0.5);
	Kolor _barwa;
	_barwa.r=1;
	_barwa.g=0;
	_barwa.b=1;
	gracz1.setKolor(_barwa);
	gracz1.setStrona(0);
}

void inicjacja2()
{
	gracz2_poz.x=3.5;
	gracz2_poz.y=0.29;
	pocisk2_poz.x=3.5;
	pocisk2_poz.y=0.29;

	gracz2.setKat(0);
	gracz2.setPozycja(3.5);
	gracz2.setShootX(0);
	gracz2.setShootY(0);
	gracz2.setWidth(0.5);
	gracz2.setHigh(0.5);
	Kolor _barwa;
	_barwa.r=0;
	_barwa.g=0;
	_barwa.b=1;
	gracz2.setKolor(_barwa);
	gracz2.setStrona(1);
}

void  CCzolg::setPozycja(double poz)
{
	pozycja+=poz;
}
void  CCzolg::setKat(double _kat)
{
	kat+=_kat;
}
void CCzolg::setShootX(double x)
{
	shootX+=x;
}
void CCzolg::setShootY(double y)
{
	shootY+=y;
}
void CCzolg::setWidth(double w)
{
	width=w;
}
void CCzolg::setHigh(double h)
{
	high=h;
}
void CCzolg::setKolor(Kolor _barwa)
{
	barwa.r=_barwa.r;
	barwa.g=_barwa.g;
	barwa.b=_barwa.b;
}
void CCzolg::setStrona(double s)
{
	strona=s;
}
double CCzolg::showKat()
{
	return kat;
}
double CCzolg::showShootX()
{
	return shootX;
}
double CCzolg::showShootY()
{
	return shootY;
}
double CCzolg::showPozycja()
{
	return pozycja;
}

void czas1(int)
{
	t1+=0.0003;
	gracz1.setShootX(0.5*t1*cos((gracz1.showKat()*PI)/180.0));
	gracz1.setShootY(0.5*t1*sin((gracz1.showKat()*PI)/180.0)-(10*pow(t1,2)/2));

	pocisk1_poz.x+=0.5*t1*cos((gracz1.showKat()*PI)/180.0);
	pocisk1_poz.y+=0.5*t1*sin((gracz1.showKat()*PI)/180.0)-(10*pow(t1,2)/2);

	if(gracz1.showShootY()<=-0.29)
	{
		gracz1.setShootX(-gracz1.showShootX());
		gracz1.setShootY(-gracz1.showShootY());
		t1=0;

	}
	else if(pocisk1_poz.x>=(gracz2_poz.x-0.4) && pocisk1_poz.x<=(gracz2_poz.x+0.15))
	{
		if(pocisk2_poz.y<=gracz1_poz.y)
		{
			Kolor _klr2;
			_klr2.r=1;
			_klr2.g=0;
			_klr2.b=0;
			gracz2.setKolor(_klr2);
			gracz1.setShootX(-gracz1.showShootX());
			gracz1.setShootY(-gracz1.showShootY());
			t1=0;
		}
	}
	else
		glutTimerFunc(1, czas1, 0);
}
void czas2(int)
{
	t2+=0.0003;
	gracz2.setShootX(0.5*t2*cos((gracz2.showKat()*PI)/180.0));
	gracz2.setShootY(0.5*t2*sin((gracz2.showKat()*PI)/180.0)-(10*pow(t2,2)/2));

	pocisk2_poz.x-=0.5*t2*cos((gracz2.showKat()*PI)/180.0);
	pocisk2_poz.y+=0.5*t2*sin((gracz2.showKat()*PI)/180.0)-(10*pow(t2,2)/2);

	if(gracz2.showShootY()<=-0.29)
	{
		gracz2.setShootX(-gracz2.showShootX());
		gracz2.setShootY(-gracz2.showShootY());
		t2=0;
	}
	else if(pocisk2_poz.x<=(gracz1_poz.x+0.15) && pocisk2_poz.x>=(gracz1_poz.x-0.4))
	{
		if(pocisk2_poz.y<=gracz1_poz.y)
		{
			Kolor _klr1;
			_klr1.r=1;
			_klr1.g=0;
			_klr1.b=0;
			gracz1.setKolor(_klr1);
			gracz2.setShootX(-gracz2.showShootX());
			gracz2.setShootY(-gracz2.showShootY());
			t2=0;
		}
	}
	else
		glutTimerFunc(1, czas2, 0);
}

void sterowanie(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		gracz1.setKat(1);	
	}
	else if (key == 's')
	{
		gracz1.setKat(-1);
	}
	if (key == 'd')
	{
		gracz1.setPozycja(0.1);
		gracz1_poz.x+=0.1;
		pocisk1_poz.x+=0.1;
	}
	else if (key == 'a')
	{
		gracz1.setPozycja(-0.1);
		gracz1_poz.x-=0.1;
		pocisk1_poz.x-=0.1;
	}


	if (key == 'i')
	{
		gracz2.setKat(1);
	}
	else if (key == 'k')
	{
		gracz2.setKat(-1);
	}
	if (key == 'l')
	{
		gracz2.setPozycja(0.1);
		gracz2_poz.x+=0.1;
		pocisk2_poz.x+=0.1;
	}
	else if (key == 'j')
	{
		gracz2.setPozycja(-0.1);
		gracz2_poz.x-=0.1;
		pocisk2_poz.x-=0.1;
	}

	if (key == 'e')
	{
		glutTimerFunc(300, czas1, 0);
	}

	if (key == 'o')
	{	
		glutTimerFunc(300, czas2, 0);
	}
}

void CCzolg::DrawCzolg(void)
{
	glPushMatrix();

	glTranslated(0 + pozycja, 0, 0);
	glColor3d(barwa.r, barwa.g, barwa.b);

	glBegin(GL_POLYGON);
	{
		glVertex3d(0*width, 0.4*high, 0);
		glVertex3d(0*width, 0*high, 0);
		glVertex3d(0.8*width, 0*high, 0);
		glVertex3d(0.8*width, 0.4*high, 0);
	}
	glEnd();

	glTranslated(0.15, 0.09, 0);
	glBegin(GL_POLYGON);
	{
		glVertex3d(0, 0.38*high, 0);
		glVertex3d(0, 0.2*high, 0);
		glVertex3d(0.3*width, 0.2*high, 0);
		glVertex3d(0.3*width, 0.38*high, 0);
	}
	glEnd();

	glTranslated(0.075, 0.15, 0);
	glRotated(180*strona, 0, strona, 0);
	glRotated(kat, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glVertex3d(0, 0.025*high, 0);
		glVertex3d(0, -0.025*high, 0);
		glVertex3d(0.4*width, -0.025*high, 0);
		glVertex3d(0.4*width, 0.025*high, 0);
	}
	glEnd();	

	glPopMatrix();
}

void CCzolg::DrawPocisk(void)
{
	glPushMatrix();
	glTranslated(0 + pozycja, 0, 0);
	glRotated(180*strona, 0, strona, 0);
	glTranslated(0.27-(0.54*strona)+shootX, 0.26+shootY, 0);
	glRotated(kat, 0.0, 0.0, 1.0);
	glColor3d(0, 0, 0);
	glBegin(GL_POLYGON);
	{
		for(double i = 0; i < 2 * PI; i += PI / 30)
 					glVertex3f(cos(i)*0.02, sin(i)*0.02, 0.0);
	}
	glEnd();
	glPopMatrix();
}

void DrawZiemia(void)
{
	glPushMatrix();
	glColor3d(0, 1.0, 0);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-10, -10.0, 0);
		glVertex3d(-10, 0.1, 0);
		glVertex3d(10, 0.1, 0);
		glVertex3d(10, -10, 0);
	}
	glEnd();
	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	
	glPushMatrix();
	gracz2.DrawCzolg();
	gracz2.DrawPocisk();
	glPopMatrix();
	

	glPushMatrix();
	gracz1.DrawCzolg();
	gracz1.DrawPocisk();
	glPopMatrix();



	glPushMatrix();
	DrawZiemia();
	glPopMatrix();

	glutSwapBuffers();
}

