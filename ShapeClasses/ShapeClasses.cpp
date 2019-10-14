/*	SHAPE CLASSES
	
	For practice with abstract base classes, pure virtual functions, inheritance



*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


// Abstract base classes (use as interface only) ----------------------------------------
class shape {

public:	
		
	virtual ~shape() {} 
	
	// pure virtual functions
	virtual int		getSides()  = 0;    
	virtual double	getArea()   = 0;   
	virtual double	getVolume() = 0;    
};
 
//abstract 2D class
class shape_2D : public shape {

public:
			
	virtual ~shape_2D() {}	

	 // pure virtual functions
	virtual int		getSides() = 0;   
	virtual double 	getArea() = 0;    
	
};

//abstract 3D class
class shape_3D : public shape {


public:
				
	virtual ~shape_3D() { } 
	
	// pure virtual function
	virtual int		getSides() = 0;    
	virtual double 	getArea()   = 0;  
	virtual double 	getVolume() = 0;   

};

// 2D classes ----------------------------------------------------------------------------

//rectangle
class rectangle : public shape_2D {

private:

	int sides;
	double area;

public:

	//default constructor
	rectangle() :
		sides(4), area(2) {cout << "Default rectangle constructor called." << endl;}

	//destructor
	~rectangle() { cout << "Rectangle destroyed..." << endl; }

	//overridden access function
	int	   getSides()  { return sides; }    
	double getArea()   { return area; }
	double getVolume() { return 0; }

};

//square
class square : public shape_2D {

private:

	int sides;
	double area;

public:

	//default constructor
	square() :
		sides(4), area(1) {
		cout << "Default square constructor called." << endl;
	}

	//destructor
	~square() { cout << "Square destroyed..." << endl; }

	//overridden access function
	int	   getSides() { return sides; }
	double getArea() { return area; }
	double getVolume() { return 0; }

};

//ellipse
class ellipse : public shape_2D {

private:

	int sides;
	double area;

public:

	//default constructor
	ellipse() :
		sides(1), area(2) {
		cout << "Default ellipse constructor called." << endl;
	}

	//destructor
	~ellipse() { cout << "Ellipse destroyed..." << endl; }

	//overridden access function
	int	   getSides() { return sides; }
	double getArea() { return area; }
	double getVolume() { return 0; }

};

//circle
class circle : public shape_2D {

private:

	int sides;
	double area;

public:

	//default constructor
	circle() :
		sides(1), area(1) {
		cout << "Default circle constructor called." << endl;
	}

	//destructor
	~circle() { cout << "Circle destroyed..." << endl; }

	//overridden access function
	int	   getSides() { return sides; }
	double getArea() { return area; }
	double getVolume() { return 0; }

};

// 3D classes ----------------------------------------------------------------------------

//cuboid
class cuboid : public shape_3D {

private:

	int sides;
	double area, volume;

public:

	//default constructor
	cuboid() :
		sides(6), area(10), volume(2) {
		cout << "Default cuboid constructor called." << endl;
	}

	//destructor
	~cuboid() { cout << "Cuboid destroyed..." << endl; }

	//overridden access function
	int	   getSides() { return sides; }
	double getArea() { return area; }
	double getVolume() { return 0; }

};

//cube
class cube : public shape_3D {

private:

	int sides;
	double area, volume;

public:

	//default constructor
	cube() :
		sides(6), area(6), volume(1) {
		cout << "Default cube constructor called." << endl;
	}

	//destructor
	~cube() { cout << "Cube destroyed..." << endl; }
	
	//overridden access function
	int	   getSides() { return sides; }
	double getArea() { return area; }
	double getVolume() { return 0; }

};

//ellipsoid
class ellipsoid : public shape_3D {

private:

	int sides;
	double area, volume;

public:

	//default constructor
	ellipsoid() :
		sides(1), area(20), volume(10) {
		cout << "Default ellipsoid constructor called." << endl;
	}

	//destructor
	~ellipsoid() { cout << "Ellipsoid destroyed..." << endl; }

	//overridden access function
	int	   getSides() { return sides; }
	double getArea() { return area; }
	double getVolume() { return 0; }

};
 
//sphere
class sphere : public shape_3D {

private:

	int sides;
	double area, volume;

public:

	//default constructor
	sphere() :
		sides(1), area(12.566), volume(4.189) {
		cout << "Default sphere constructor called." << endl;
	}

	//destructor
	~sphere() { cout << "Sphere destroyed..." << endl; }

	//overridden access function
	int	   getSides() { return sides; }
	double getArea() { return area; }
	double getVolume() { return 0; }

};

//prism
class prism : public shape_3D {

private:

	int sides;
	double area, volume;

public:

	
	//parameterised constructor
	prism(double depth, shape_2D *prismatic) :
		sides(prismatic->getSides()), area((prismatic->getSides()*1*depth)+(2*prismatic->getArea())),volume(prismatic->getArea()*depth) {
		cout << "Parameterised prism constructor called." << endl;
	}

	//destructor
	~prism() { cout << "Prism destroyed..." << endl; }

	//overridden access function
	int	   getSides() { return sides; }
	double getArea() { return area; cout << " (for unit-sided polygons only)"; }
	double getVolume() { return volume; } 

};

int main()
{

	// Code demonstrates polymorphism using an array (or vector) of base class pointers,
	// each pointing to different shape

	// Eight derived classes (4 2D, 4 3D), each overriding pure virtual functions -------

	//Create 2D shapes
	rectangle rectangle_1;
	square square_1;
	ellipse ellipse_1;
	circle circle_1;

	//Create 3D shapes
	cuboid cuboid_1;
	cube cube_1;
	ellipsoid ellipsoid_1;
	sphere sphere_1;

	prism prism_1(10, &square_1);

	

	// Array of shapes to store shapes	
	int n = 9;
	shape** shape_storage = new shape*[n];

	// Construct new shapes based on previously constructed shapes
	// No new memory allocated!
	// Uses dereferenced shapes to construct new shape in array
	shape_storage[0] = new (&rectangle_1) rectangle;
	shape_storage[1] = new (&square_1) square;
	shape_storage[2] = new (&ellipse_1) ellipse;
	shape_storage[3] = new (&circle_1) circle;

	shape_storage[4] = new (&cuboid_1) cuboid;
	shape_storage[5] = new (&cube_1) cube;
	shape_storage[6] = new (&ellipsoid_1) ellipsoid;
	shape_storage[7] = new (&sphere_1) sphere;

	shape_storage[8] = new (&prism_1) prism(prism_1);

	
	// Code correctly prints out the area (2D) and area and volume (3D) of each shape -----

	for (int i = 0; i < n; i++) {		

		cout << "Shape " << i+1 << " has area = " << shape_storage[i]->getArea()
			 << " and volume = " << shape_storage[i]->getVolume() << "." << endl;

			}

	// Code correctly cleans up, deleting objects and array ------------------------------
	
	// Delete objects
	for (int i = 0; i < n; i++) {

		delete &shape_storage[i];
		cout << i << endl;
	}


	// Delete array
	delete[] shape_storage;


}