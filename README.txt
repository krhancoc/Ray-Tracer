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

=== 7. DECLARATION AND IMAGE PERMISSION: ===

<Initial the following:>

KR I have read the regulations regarding plagarism. I affirm with my initials
that I have worked on my own solution to this assignment, and the code I am
submitting is my own.

<Mark with an X if desired. No marks will be deducted either way>

X I grant the instructor and/or TAs permission to use images submitted and/or
   assignment screenshots for future CPSC453 courses.

__ If permission has been granted above, I would prefer the images to remain 
   annonymous. <Otherwise credit will be given, as is due>

X I would like to participate in the raytracer competition. <Competition entries will
   not be annonymous and credited accordingly. Specify which images are for consideration,
   otherwise all will be considered.> 

__
