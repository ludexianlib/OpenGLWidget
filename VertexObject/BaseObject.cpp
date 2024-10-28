#include "BaseObject.h"

BaseObject::BaseObject() : QOpenGLFunctions_3_3_Core()
{
	initializeOpenGLFunctions();
}

BaseObject::~BaseObject()
{
}
