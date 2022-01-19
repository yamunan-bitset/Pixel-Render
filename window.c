#include "window.h"

void render_init(struct Window* window)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, window->width, window->height, 0.0);
}

void pixel(unsigned x, unsigned y, unsigned size, struct Colour* colour)
{
  glPointSize(size);
  glBegin(GL_POINTS);
  glColor3f(colour->r, colour->b, colour->g);
  glVertex2i(x, y);
  glEnd();
  glFlush();
}

void render_array(unsigned* array, unsigned xsize, unsigned ysize, unsigned size, struct Colour* colour1, struct Colour* colour2)
{
  for (unsigned x = 0; x < xsize; x++)
    for (unsigned y = 0; y < ysize; y++)
      {
	if (array[y * xsize + x] == 1) pixel(x, y, size, &colour1);
	if (array[y * xsize + x] == 0) pixel(x, y, size, &colour2);
      }
}

void font(char letter)
{
  switch (letter)
    {
    case 'a':
      #include "font/a.inc"
    case 'b':
      #include "font/b.inc"
    case 'c':
      #include "font/c.inc"
    case 'd':
      #include "font/d.inc"
    case 'e':
      #include "font/e.inc"
    case 'f':
      #include "font/f.inc"
    case 'g':
      #include "font/g.inc"
    case 'h':
      #include "font/h.inc"
    case 'i':
      #include "font/i.inc"
    case 'j':
      #include "font/j.inc"
    case 'k':
      #include "font/k.inc"
    case 'l':
      #include "font/l.inc"
    case 'm':
      #include "font/m.inc"
    case 'n':
      #include "font/n.inc"
    case 'o':
      #include "font/o.inc"
    case 'p':
      #include "font/p.inc"
    case 'q':
      #include "font/q.inc"
    case 'r':
      #include "font/r.inc"
    case 's':
      #include "font/s.inc"
    case 't':
      #include "font/t.inc"
    case 'u':
      #include "font/u.inc"
    case 'v':
      #include "font/v.inc"
    case 'w':
      #include "font/w.inc"
    case 'x':
      #include "font/x.inc"
    case 'y':
      #include "font/y.inc"
    case 'z':
      #include "font/z.inc"
    }
  return;
}

void render_font(char* msg)
{
  for (unsigned i = 0; i < sizeof msg; i++)
    render_array(font(msg[i]));
  return;
}

void init(struct Window* window)
{
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
  glutInitWindowSize(window->height, window->width);
  glutCreateWindow(window->title);
}

