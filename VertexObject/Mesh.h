#pragma once
#include "BaseObject.h"

class Mesh : public BaseObject
{
public:
	Mesh();
	~Mesh();

	void init() override;
	void draw() override;

protected:
	std::vector<Vertex> vertexes;	// ×ø±ê
	std::vector<Texture> textures;	// ÎÆÀí
	std::vector<uint> indices;		// »º³åË÷Òý

};

