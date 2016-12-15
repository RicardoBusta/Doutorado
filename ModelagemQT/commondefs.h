#ifndef COMMONDEFS
#define COMMONDEFS

#define UB_COLOR(color) qRed(color), qGreen(color), qBlue(color)
#define FVECTOR3D(vector) vector.x(), vector.y(), vector.z()
#define GLVERTEX3D(vector) glVertex3f(vector.x(),vector.y(),vector.z())
#define GLNORMAL3D(vector) glNormal3f(vector.x(),vector.y(),vector.z())

#define M_PI 3.14159265358979323846

#endif // COMMONDEFS
