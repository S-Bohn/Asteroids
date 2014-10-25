#include <random>
#include <iostream>

#include <glm/gtx/rotate_vector.hpp>

#include "Shader/Manager.h"

#include "Projectile.h"

#include <GLFW/glfw3.h>

namespace Game
{
	Projectile::Projectile()
	: _shader(Shader::Manager::getProgram("data/shader/ship.glsl"))
	{
		_physicsComponent.reset(glm::vec2(300, 150), glm::vec2(0.f));
		_physicsComponent.setMaxVelocity(500.f);

		_ready = true;

		float size = 2.f;
		
		int steps = 6;
		float r = 0.f;
		std::vector<glm::vec2> vertices;
		for (int i = 0; i <= steps; i++)
		{
			r += ((2.f * glm::pi<float>()) / (float)steps);
			vertices.push_back(glm::vec2(sin(r), cos(r)) * size);
		}
		
		_mesh.reset(new Geometry::Mesh(vertices));
		_colliderComponent.setCollisionMesh(std::unique_ptr<Geometry::Mesh>(new Geometry::Mesh(*_mesh.get())));
	}

	void Projectile::update(float delta)
	{
		_time -= delta;
		_physicsComponent.update(delta);

		_colliderComponent.setPosition(_physicsComponent.getPosition());

		if (_time <= 0.f)
		{
			_ready = true;
		}
	}

	void Projectile::draw()
	{
		_shader->use();

		for (int y = -1; y < 1; ++y)
		{
			for (int x = -1; x < 1; ++x)
			{
				_shader->uniform("position") = _physicsComponent.getPosition() + glm::vec2(800 * x, 600 * y);
				_mesh->draw(GL_LINE_STRIP);
			}
		}
	}

	const ColliderComponent* Projectile::getColliderComponent()
	{
		return &_colliderComponent;
	}

	const PhysicsComponent* Projectile::getPhysicsComponent()
	{
		return &_physicsComponent;
	}

	bool Projectile::isReady()
	{
		return _ready;
	}

	void Projectile::shoot(glm::vec2 position, glm::vec2 direction)
	{
		_ready = false;
		_time = 2.5f;
		_physicsComponent.reset(position, direction * 150.f);
	}

	void Projectile::reload()
	{
		_ready = true;
	}
}