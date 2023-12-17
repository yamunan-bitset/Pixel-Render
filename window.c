#include "window.h"

void render_init(struct Window window)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, window.width, window.height, 0.0);
}

void pixel(unsigned x, unsigned y, unsigned size, struct Colour colour)
{
  glPointSize(size);
  glBegin(GL_POINTS);
  glColor3f(colour.r, colour.b, colour.g);
  glVertex2i(x, y);
  glEnd();
  glFlush();
}

void render_array(unsigned* array, unsigned xsize, unsigned ysize, unsigned size, struct Colour colour1, struct Colour colour2)
{
  for (unsigned x = 0; x < xsize; x++)
    for (unsigned y = 0; y < ysize; y++)
      {
        if (array[y * xsize + x] == 1) pixel(x, y, size, colour1);
        if (array[y * xsize + x] == 0) pixel(x, y, size, colour2);
      }
}

void init(struct Window window)
{
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
  glutInitWindowSize(window.height, window.width);
  glutCreateWindow(window.title);
}
