#include "PhysicsSystem.h"

void PhysicsSystem::Update(entt::registry* reg)
{
	auto view = reg->view<PhysicsBody, Transform>();

	//Runs the update for the physics bodies
	for (auto entity : view)
	{
		//Grabs references to each component within view
		auto& physBod = view.get<PhysicsBody>(entity);
		auto& trans = view.get < Transform>(entity);

		//Updates physics body
		physBod.Update(&trans, Timer::deltaTime);
	}

}


void PhysicsSystem::Run(entt::registry* reg)
{
	auto view = reg->view<PhysicsBody, Transform>();
	//Body 1
	for (auto entity : view)
	{
		auto& trans1 = view.get < Transform>(entity);
		auto& body1 = view.get < PhysicsBody>(entity);

		Circle worldPosC;
		Box worldPosB;

		switch (body1.GetBodyType())
		{
		case BodyType::BOX:
			//Sets up box values
			//Calculates the corners in the world space
			worldPosB.m_center = trans1.GetPosition() + vec3(body1.GetCenterOffset().x, body1.GetCenterOffset().y, 0.f);
			worldPosB.m_bottomLeft = trans1.GetPosition() + vec3(body1.GetBottomLeft().x, body1.GetBottomLeft().y, 0.f);
			worldPosB.m_bottomRight = trans1.GetPosition() + vec3(body1.GetTopRight().x, body1.GetTopRight().y, 0.f);
			worldPosB.m_bottomRight = vec3(worldPosB.m_topRight.x, worldPosB.m_bottomLeft.y, 0.f);
			worldPosB.m_bottomLeft = vec3(worldPosB.m_bottomLeft.x, worldPosB.m_topRight.y, 0.f);
			break;
		case BodyType::CIRCLE:
			//Sets up circle values
			worldPosC.m_center = trans1.GetPosition() + vec3(body1.GetCenterOffset().x, body1.GetCenterOffset().y, 0.f);
			worldPosC.m_radius = body1.GetRadius();
			break;
		}

		//Check if body1 is dynamic, if it is, compare it to the other bosies within the list
		if (body1.GetDynamic())
		{
			//Loops through all bodies again
			for (auto entity2 : view)
			{
				auto& trans2 = view.get < Transform>(entity2);
				auto& body2 = view.get < PhysicsBody>(entity2);

				Circle worldPosC2;
				Box worldPosB2;

				switch (body2.GetBodyType())
				{
				case BodyType::BOX:
					//Sets up box values
					//Calculates the corners in the world space
					worldPosB.m_center = trans2.GetPosition() + vec3(body2.GetCenterOffset().x, body2.GetCenterOffset().y, 0.f);
					worldPosB.m_bottomLeft = trans2.GetPosition() + vec3(body2.GetBottomLeft().x, body2.GetBottomLeft().y, 0.f);
					worldPosB.m_bottomRight = trans2.GetPosition() + vec3(body2.GetTopRight().x, body2.GetTopRight().y, 0.f);
					worldPosB.m_bottomRight = vec3(worldPosB2.m_topRight.x, worldPosB2.m_bottomLeft.y, 0.f);
					worldPosB.m_bottomLeft = vec3(worldPosB2.m_bottomLeft.x, worldPosB2.m_topRight.y, 0.f);
					break;
				case BodyType::CIRCLE:
					//Sets up circle values
					worldPosC2.m_center = trans2.GetPosition() + vec3(body2.GetCenterOffset().x, body2.GetCenterOffset().y, 0.f);
					worldPosC2.m_radius = body2.GetRadius();
					break;
				}
			}
		}

		//Body 2
		for (auto entity : view)
		{
			auto& trans2 = view.get < Transform>(entity);
			auto& body2 = view.get < PhysicsBody>(entity);

			Circle worldPos;
			Box worldPosB;

			switch (body2.GetBodyType())
			{
			case BodyType::BOX:
				//Sets up box values

				break;
			case BodyType::CIRCLE:
				//Sets up circle values

				break;
			}

			//Check if body1 is dynamic, if it is, compare it to the other bosies within the list
			if (body2.GetDynamic())
			{
				//Loops through all bodies again
				for (auto entity1 : view)
				{
					auto& trans1 = view.get < Transform>(entity1);
					auto& body1 = view.get < PhysicsBody>(entity1);

					Circle worldPosC1;
					Box worldPosB1;

					switch (body1.GetBodyType())
					{
					case BodyType::BOX:
						//Sets up box values

						break;
					case BodyType::CIRCLE:
						//Sets up circle values

						break;
					}
				}
			}

			if (body1.GetBodyType() == BodyType::CIRCLE)
			{
				if (body2.GetBodyType() == BodyType::BOX)
				{
					//Perform Circle=Box collision
				}
				else if (body2.GetBodyType() == BodyType::CIRCLE)
				{
					//Perform Box-Boxcollision

				}
			}
			if (body1.GetBodyType() == BodyType::BOX)
			{
				if (body2.GetBodyType() == BodyType::BOX)
				{
					//Perform Circle=Box collision
				}
				else if (body2.GetBodyType() == BodyType::CIRCLE)
				{
					//Perform Box-Circle collision
				}
			}
		}
	}

	bool PhysicsSystem::BoxBoxCollision(std::pair<PhysicsBody&, Box> group1, std::pair<PhysicsBody&, Box> group2)
	{
		return false;
	}

