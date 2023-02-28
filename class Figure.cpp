// class Figure.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// директива для числа пи
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

/*
	1) Используя наследование, создайте классы для геометрических фигур 
	(см. рисунок из презентации по наследованию). Базовый класс будет 
	содержать одно поле - сторона фигуры.
	2) Используя множественное наследование, разработать класс
	“Окружность, вписанная в квадрат”.
*/

// Задача 1---------------------------------------------------------------

class Figure  // базовый класс фигура
{
protected:        // доступ открыт в этом классе и в дочерних
	double side;  // сторона фигуры
public:
	Figure() : side{0} {}
	Figure(double sideP) : side{sideP} 
	{
		std::cout << "Constructor with parameters Figure\n";
	}

	void print()
	{
		std::cout << "Side of figure: " << side << " sm." << std::endl;
	}

	~Figure()
	{
		std::cout << "Destructor Figure\n";
	}
};

class Square : public Figure  // дочерний класс квадрат
{
public:
	Square() : Figure() {}
	Square(double sqr_side) : Figure(sqr_side)
	{
		std::cout << "Constructor with parameters Square\n";
	}

	double square_p()  // метод - вичисление периметра квадрата
	{
		return (side * 4);
	}

	double square_s()  // метод - вичисление площади квадрата
	{
		return (side * side);
	}

	double get_side()
	{
		return side;
	}
	
	void print()  // вывод на экран
	{
		square_p();
		std::cout << "P of square: " << square_p() << std::endl;
		square_s();
		std::cout << "S of square: " << square_s() << std::endl;
	}

	~Square()
	{
		std::cout << "Destructor Square\n";
	}
};

class Triangle : public Figure  // дочерний класс треугольник
{
public:
	Triangle() :Figure() {}
	Triangle(double trian_side) : Figure(trian_side)
	{
		std::cout << "Constructor with parameters Triangle\n";
	}

	double triangle_p()   // метод - вичисление периметра треугольника
	{                     // (берем равносторонний треугольник)
		return (side * 3);
	}
	
	double triangle_s()  // метод - вичисление площади треугольника
	{
		return (((side * side) * sqrt(3)) / 4);
	}

	void print()  // вывод на экран
	{
		triangle_p();
		std::cout << "P of triangle: " << triangle_p() << std::endl;
		triangle_s();
		std::cout << "S of triangle: " << triangle_s() << std::endl;
	}

	~Triangle()
	{
		std::cout << "Destructor Triangle\n";
	}
};

class Rectangle : public Figure  // дочерний класс прямоугольник
{
public:
	Rectangle() : Figure() {}
	Rectangle(double rect_side) : Figure(rect_side)
	{
		std::cout << "Constructor with parameters Rectangle\n";
	}

	double rectangle_p()   // метод - вичисление периметра прямоугольника
	{                      // (берем, что 2ая сторона = 1ая*2)
		return ((side + (side*2)) * 2);
	}

	double rectangle_s()  // метод - вичисление площади прямоугольника
	{
		return (side * (side * 2));
	}

	void print()  // вывод на экран
	{
		rectangle_p();
		std::cout << "P of rectangle: " << rectangle_p() << std::endl;
		rectangle_s();
		std::cout << "S of rectangle: " << rectangle_s() << std::endl;
	}

	~Rectangle()
	{
		std::cout << "Destructor Rectangle\n";
	}

};

class Circle : public Figure  // дочерний класс круг
{
public:
	Circle() : Figure() {}
	Circle(double diameter) : Figure(diameter)
	{
		std::cout << "Constructor with parameters Circle\n";
	}

	double circle_p()   // метод - вичисление периметра круга
	{
		return (M_PI * side);
	}

	double circle_s()  // метод - вичисление площади круга
	{
		return ((M_PI * pow(side,2)) / 4);
	}

	void print()  // вывод на экран
	{
		circle_p();
		std::cout << "P of circle: " << circle_p() << std::endl;
		circle_s();
		std::cout << "S of circle: " << circle_s() << std::endl;
	}

	~Circle()
	{
		std::cout << "Destructor Circle\n";
	}
};

// множественное неследование: класс Круг_в_квадрате наследует классы
// Фигура и Квадрат
class Circle_in_Sqr : public Figure, public Square
{
	double radius;  // радиус
public:
	Circle_in_Sqr() :  radius{ 0 } {}
	Circle_in_Sqr(double radiusP)
		: radius{radiusP} 
	{
		std::cout << "Constructor with parameters Circle_in_Sqr\n";
	}

	double get_radius()  // геттер
	{
		return radius;
	}

	// для демонстрации работы множественного наследования:
	// делаю метод, который позволяет узнать, "влезет" ли объект класса
	// Circle_in_Sqr в объект класса Квадрат
	bool fit_into(Square obj)
	{		
		if ((get_radius()*2) <= obj.get_side())  // если (радиус*2) < стороны квадрата
			return true;                         // то объект Circle_in_Sqr вписывается в Square
		else
			return false;
	}

	~Circle_in_Sqr()
	{
		std::cout << "Destructor Circle_in_Square\n";
	}
};

int main()
{
	double x{ 5 };  // сторона
	std::cout << "Side = " << x  << '\n';
	Figure side(x);  // создание объекта класса Сторона
	
	std::cout << "Square:\n";
	Square sqr(x);  // создание объекта класса Квадрат,
	                // инициализация полем класса Фигура
	sqr.print();

	std::cout << "Triangle:\n";
	Triangle trian(x);  // создание объекта класса Треугольник
	                    // инициализация полем класса Фигура
	trian.print();

	std::cout << "Rectangle:\n";
	Rectangle rect(x);  // создание объекта класса Прямоугольник
	                    // инициализация полем класса Фигура
	rect.print();

	std::cout << "Circle:\n";
	Circle circ(x);  // создание объекта класса Круг
	                 // инициализация полем класса Фигура
	circ.print();

	std::cout << "Circle in square? \n";
	Circle_in_Sqr circ_in_sqr(2);  // создание объекта класса Круг_в_Квадрате

	if (circ_in_sqr.fit_into(sqr) == true)
	{
		std::cout << "Yes\n";
	}
	else
	{
		std::cout << "No\n";
	}

	return 0;	
}

// задача 2

class Sqr  // базовый класс квадрат
{
protected:
	float side;
public:
	Sqr() : side{ 0 } {}
	Sqr(float sideP) : side{sideP} {}

	float get_side()
	{
		return side;
	}

};

class Circ  // базовый класс круг
{
protected:
	float diam;
public:
	Circ() : diam{ 0 } {}
	Circ(float diamP) : diam{ diamP } {}

	float get_diam()
	{
		return diam;
	}

};

class Circ_in_Sqr : public Sqr, public Circ  // класс-наследник классов Квадрат и Круг
{
public:
	Circ_in_Sqr() : Sqr(), Circ() {}
	Circ_in_Sqr(float side, float diam) : Sqr(side), Circ(diam) {}

	bool fit_into(Sqr obj1, Circ obj2)
	{
		if (obj1.get_side() == obj2.get_diam())  // если диаметр = стороне квадрата
			return true;                         // то объект Circle_in_Sqr вписывается в Square
		else
			return false;
	}

};

int main2()
{
	Sqr sqr(4);
	Circ circ(3);

	Circ_in_Sqr res_ob;

	if (res_ob.fit_into(sqr, circ) == true)
	{
		std::cout << "Yes\n";
	}
	else
	{
		std::cout << "No\n";
	}
	
	return 0;

}


