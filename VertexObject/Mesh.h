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
	std::vector<Vertex> vertexes;	// ����
	std::vector<Texture> textures;	// ����
	std::vector<uint> indices;		// ��������

};

