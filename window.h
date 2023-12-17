#ifndef __WINDOW__H__
#define __WINDOW__H__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define PIXEL_SIZE_DEFAULT 1

struct Window
{
  char* title;
  unsigned width, height;
};

struct Colour
{
  float r, g, b;
};

void init(struct Window);
void render_init(struct Window);
void pixel(unsigned, unsigned, unsigned, struct Colour);
void render_array(unsigned*, unsigned, unsigned, unsigned, struct Colour, struct Colour);

#endif
