
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;



void PrintText3D(double x, double y, double z, std::string text)
{
    glRasterPos3d(x, y, z);
    glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char *)text.c_str());
}

void display(void) 
{ 
/* стираем */ 
glClear (GL_COLOR_BUFFER_BIT);

/* рисуем белый прямоугольник 
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/ 
glColor3f (0.3, 0.7, 0); 
glBegin(GL_POLYGON); 
glVertex2f (0.025, 0.85); 
glVertex2f (0.13, 0.85); 
glVertex2f (0.13, 0.9); 
glVertex2f (0.025, 0.9);
glEnd(); 

glColor3f(0, 0.0f, 1);
    PrintText3D(0.025, 0.867,0, "reaction");
    glFinish();
/* поехали ! */ 
glFlush (); 
} 



void init (void) 
{ 
/* установим бордовый фон */ 
glClearColor (0.2, 0.0, 0.0, 0.0); 

/* инициализация viewing values */ 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
} 

/* 
Определим параметры окна , display mode 
* (single buffer and RGBA). Откроем окно с фразой "hello" 
* в title bar. 
*/ 
int main(int argc, char** argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize (700,500); 
glutInitWindowPosition (100, 100); 
glutCreateWindow ("AvadoN"); 
init (); 

glutDisplayFunc(display); 
glutMainLoop(); 

return 0; /* ISO C requires main to return int. */ 
} 