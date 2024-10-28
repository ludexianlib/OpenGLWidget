#pragma once
#include <vector>

/**
 * @brief  \2D顶点
 * @param  \
 */
struct Vec2D
{
	float x;
	float y;

	Vec2D(float x = 0.0, float y = 0.0) : x(x), y(y) {}
};

/**
 * @brief  \3D顶点
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
 * @brief  \对象顶点
 * @param  \
 */
struct Vertex
{
	Vec3D position = 0.0;	// 位置
	Vec3D color = 0.0;		// 颜色
	Vec2D texture = 0.0;	// 纹理坐标

	Vertex(Vec3D p = Vec3D(), Vec3D c = Vec3D(), Vec2D t = Vec2D()) : position(p), color(c), texture(t) {}
};

/**
 * @brief  \纹理
 * @param  \
 */
struct Texture
{
	uint id = 0;	// 位置
};

/**
 * @brief  \网格对象
 * @param  \
 */
struct Mesh
{
	std::vector<Vertex> vertexes;	// 坐标
	std::vector<Texture> textures;	// 纹理
	std::vector<uint> indices;		// 缓冲索引
};
