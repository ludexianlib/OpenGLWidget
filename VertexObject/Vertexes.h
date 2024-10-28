#pragma once
#include <vector>

/**
 * @brief  \2D����
 * @param  \
 */
struct Vec2D
{
	float x;
	float y;

	Vec2D(float x = 0.0, float y = 0.0) : x(x), y(y) {}
};

/**
 * @brief  \3D����
 * @param  \
 */
struct Vec3D
{
	float x;
	float y;
	float z;

	Vec3D(float x = 0.0, float y = 0.0, float z = 0.0) : x(x), y(y), z(z) {}
};

/**
 * @brief  \���󶥵�
 * @param  \
 */
struct Vertex
{
	Vec3D position = 0.0;	// λ��
	Vec3D color = 0.0;		// ��ɫ
	Vec2D texture = 0.0;	// ��������

	Vertex(Vec3D p = Vec3D(), Vec3D c = Vec3D(), Vec2D t = Vec2D()) : position(p), color(c), texture(t) {}
};

/**
 * @brief  \����
 * @param  \
 */
struct Texture
{
	uint id = 0;	// λ��
};

/**
 * @brief  \�������
 * @param  \
 */
struct Mesh
{
	std::vector<Vertex> vertexes;	// ����
	std::vector<Texture> textures;	// ����
	std::vector<uint> indices;		// ��������
};
