#include "window.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <time.h>

struct Window window =
  {
    .title = "Pixel Engine",
    .width = 500,
    .height = 500
  };

int sprite[][7] =
  {
#include "art.inc"
  };

void render()
{
  struct Colour colour1 = { .r=1,.g=1,.b=1 };
  struct Colour colour2 = { .r=1,.g=0,.b=0 };
  srand(time(0));
  render_init(window);
  for (int i = 0; i < window.width; i += 10)
    for (int j = 0; j < window.height; j += 10)
      {
        if (sprite[i % 5][j % 7] == 1) pixel(i, j, 10, colour1);
        else pixel(i, j, 10, colour2);
      }
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  init(window);
  glutDisplayFunc(render);
  glutMainLoop();
  return 0;
}
