#include <GL/glut.h>

namespace pr
{
  void CreateWindow(int argc, char** argv, const char* title, unsigned x, unsigned y)
  {
    glutInit(&argc, argv);
    glutInitWindowSize(x, y);
    glutInitDisplayMode(GLUT_RGBA | GLUT_INDEX | GLUT_SINGLE | GLUT_DOUBLE | GLUT_ACCUM
			| GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE
			| GLUT_STEREO | GLUT_LUMINANCE);
    glutCreateWindow(title);
  }
}
