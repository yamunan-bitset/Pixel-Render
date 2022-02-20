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

/*
unsigned* font(char letter)
{
  switch (letter)
    {
    case 'a':
      return {
#include "font/a.inc"
      }
    case 'b':
      return {
#include "font/b.inc"
      }
    case 'c':
      return {
#include "font/c.inc"
	}
    case 'd':
      return {
#include "font/d.inc"
	}
    case 'e':
      return {
#include "font/e.inc"
	}
    case 'f':
      return {
#include "font/f.inc"
	}
    case 'g':
      return {
#include "font/g.inc"
	}
    case 'h':
      return {
#include "font/h.inc"
	}
    case 'i':
      return {
#include "font/i.inc"
	}
    case 'j':
      return {
#include "font/j.inc"
      }
      case 'k':
      return {
#include "font/k.inc"
	}
    case 'l':
      return {
#include "font/l.inc"
	}
    case 'm':
      return {
#include "font/m.inc"
	}
    case 'n':
      return {
#include "font/n.inc"
	}
    case 'o':
      return {
#include "font/o.inc"
	}
    case 'p':
      return {
#include "font/p.inc"
	}
    case 'q':
      return {
#include "font/q.inc"
	}
    case 'r':
      return {
#include "font/r.inc"
	}
    case 's':
      return {
#include "font/s.inc"
	}
    case 't':
      return {
#include "font/t.inc"
	}
    case 'u':
      return {
#include "font/u.inc"
	}
    case 'v':
      return {
#include "font/v.inc"
	}
    case 'w':
      return {
#include "font/w.inc"
	}
    case 'x':
      return {
#include "font/x.inc"
	}
    case 'y':
      return {
#include "font/y.inc"
	}
    case 'z':
      return {
#include "font/z.inc"
	}
      }
}

void render_font(char* msg, unsigned size, struct Colour colour1, struct Colour colour2)
{
  for (unsigned i = 0; i < sizeof msg; i++)
    render_array(font(msg[i]), size/8, size/8, size, colour1, colour2);
  return;
}
*/

