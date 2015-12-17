CPSC453 - Assignment 4

NAME: Kenneth R Hancock
UCID Number: 10041150
Tutorial Section: Josh

=== 1. EXECUTION: ===

To compile the program, on the terminal enter the following commands:

	qmake -project QT+=widgets
	qmake
	make

To run the program, on the terminal enter the following command:

	./a4

=== 2. PROGRAM USE: ===

Just run the program and the progam will output and image based on the scene.

== 3. ALGORITHMS and DESIGN DECISIONS: ===

Used many perfect reflection formulas and geometric - line intersection formulas to help create the rays and simulate the rays to be traced.

Phong Illumination Model - Ambient, Diffuse, Specular.

With recursion being used for reflection.

=== 4. FILES SUBMITTED: ===

1.  README
2.  brdf.h/.cpp
3. camera.h/.cpp
5. ipoint.h/.cpp
6. lights.h/.cpp
7. material.h/.cpp
8. polyroots.h/.cpp
9. ray.h/.cpp
10. scene.h/.cpp
11. shapes.h/.cpp
12. tracer.h/.cpp
13. screenshots folder


=== 5. IMAGES SUBMITTED: ===

1. Standard Image no Anti Aliasing
2. Anti Aliasing on
3. Ryan At 6 AM mode on
4. Scene of tower/water fountain
5. Standard scene
6. Better image to show reflection/shadows on primitives triange and square.

=== 6. PROGRAM ASSUMPTIONS: ===

User knows C++ to create scenes to be rendered.


Grade Recieved: 108%
