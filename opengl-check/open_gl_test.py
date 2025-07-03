from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

def display():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glFlush()

glutInit()
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE)
glutCreateWindow("OpenGL Test")
glutDisplayFunc(display)
glutMainLoop()
