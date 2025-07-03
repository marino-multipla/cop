# OpenGL Setup

sudo apt-get install freeglut3 freeglut3-dev
pip install PyOpenGL PyOpenGL_accelerate

sudo apt install mesa-utils

glxinfo | grep "OpenGL vendor"
OpenGL vendor string: Intel

sudo prime-select nvidia
sudo reboot

glxinfo | grep "OpenGL vendor"
OpenGL vendor string: NVIDIA Corporation



