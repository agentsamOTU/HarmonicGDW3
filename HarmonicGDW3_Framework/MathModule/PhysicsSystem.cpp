#include "PhysicsSystem.h"

void PhysicsSystem::Update(entt::registry * reg)
{
	auto view = reg->view<PhysicsBody, Transform>();

	//runs the update
	for (auto entity : view)
	{
		//grabs ref to each component
		auto& physBod = view.get<PhysicsBody>(entity);
		auto& trans = view.get<Transform>(entity);

		//update body
		physBod.Update(&trans, Timer::deltaTime);
	}

	//run collision upddate
	Run(reg);

}

void PhysicsSystem::Run(entt::registry* reg)
{
	auto view = reg->view<PhysicsBody, Transform>();

	for (auto entity : view)
	{
		auto& body1 = view.get<PhysicsBody>(entity);
		auto& trans1 = view.get<Transform>(entity);

		Circle worldPosC;
		Box worldPosB;

		switch (body1.GetBodyType())
		{
		case BodyType::BOX:
			//sets box
			worldPosB.m_center = trans1.GetPosition() + vec3(body1.GetCenterOffset().x, body1.GetCenterOffset().y, 0.f);
			worldPosB.m_bottomLeft = trans1.GetPosition() + vec3(body1.GetBottomLeft().x, body1.GetBottomLeft().y, 0.f);
			worldPosB.m_topRight = trans1.GetPosition() + vec3(body1.GetTopRight().x, body1.GetTopRight().y, 0.f);
			worldPosB.m_bottomRight = vec3(worldPosB.m_topRight.x, worldPosB.m_bottomLeft.y, 0.f);
			worldPosB.m_topLeft = vec3(worldPosB.m_bottomLeft.x, worldPosB.m_topRight.y, 0.f);
			break;
		case BodyType::CIRCLE:
			//sets up circle
			worldPosC.m_center = trans1.GetPosition() + vec3(body1.GetCenterOffset().x, body1.GetCenterOffset().y, 0.f);
			worldPosC.m_radius = body1.GetRadius();
			break;
		}
		if (body1.GetDynamic())
		{
			//loops through all bods again
			for (auto entity2 : view)
			{
				if (entity != entity2)
				{
					auto& body2 = view.get<PhysicsBody>(entity2);
					auto& trans2 = view.get<Transform>(entity2);

					Circle worldPosC2;
					Box worldPosB2;

					switch (body2.GetBodyType())
					{
					case BodyType::BOX:
						//sets box
						worldPosB2.m_center = trans2.GetPosition() + vec3(body2.GetCenterOffset().x, body2.GetCenterOffset().y, 0.f);
						worldPosB2.m_bottomLeft = trans2.GetPosition() + vec3(body2.GetBottomLeft().x, body2.GetBottomLeft().y, 0.f);
						worldPosB2.m_topRight = trans2.GetPosition() + vec3(body2.GetTopRight().x, body2.GetTopRight().y, 0.f);
						worldPosB2.m_bottomRight = vec3(worldPosB2.m_topRight.x, worldPosB2.m_bottomLeft.y, 0.f);
						worldPosB2.m_topLeft = vec3(worldPosB2.m_bottomLeft.x, worldPosB2.m_topRight.y, 0.f);
						break;
					case BodyType::CIRCLE:
						//sets up circle
						worldPosC2.m_center = trans2.GetPosition() + vec3(body2.GetCenterOffset().x, body2.GetCenterOffset().y, 0.f);
						worldPosC2.m_radius = body2.GetRadius();
						break;
					}
					if (body1.GetBodyType() == BodyType::CIRCLE)
					{
						if (body2.GetBodyType() == BodyType::BOX)
						{

						}
						else if (body2.GetBodyType() == BodyType::CIRCLE)
						{

						}
					}
					else if (body1.GetBodyType() == BodyType::BOX)
					{
						if (body2.GetBodyType() == BodyType::BOX)
						{
							if (BoxBoxCollision(std::pair<PhysicsBody&, Box>(body1, worldPosB), std::pair<PhysicsBody&, Box>(body2, worldPosB2)))
							{
								if (body2.GetBodyID() & CollisionIDs::Pickup())
								{
									ECS::GetComponent<Pickup>(entity2).Collect();
									ECS::DestroyEntity(entity2);
								}
								else if (body2.GetBodyID() & CollisionIDs::Acid())
								{
									if (ECS::GetComponent<PlayerWeapons>(entity).GetAcid() > 1.5f)
									{
										ECS::GetComponent<PlayerWeapons>(entity).ResetAcid();
										ECS::GetComponent<HealthArmour>(entity).SetDamaged(true);
									}
								}
								else if (body2.GetBodyID() & CollisionIDs::Win())
								{
									ECS::GetComponent<PlayerWeapons>(entity).EndGame();
									auto& playPhys = ECS::GetComponent<PhysicsBody>(EntityIdentifier::MainPlayer());
									auto& playLoc = ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
									ECS::GetComponent<Sprite>(EntityIdentifier::MainPlayer()).SetHeight(28.f);
									playPhys.SetVelocity(vec3(0.f, 0.f, 0.f));
									playPhys.SetAcceleration(vec3(0.f, 0.f, 0.f));
									playPhys.SetForce(vec3(0.f, 0.f, 0.f));
									//Creates entity 
									auto entity = ECS::CreateEntity();

									//Add components
									ECS::AttachComponent<Sprite>(entity);
									ECS::AttachComponent<Transform>(entity);

									//Sets up components
									std::string GameOver = "levelcomplete.png";
						
									ECS::GetComponent<Sprite>(entity).LoadSprite(GameOver, 180, 75);

									ECS::GetComponent<Transform>(entity).SetPosition(vec3(playLoc.GetPosition()) + vec3(0.f, 10.f, 1.f));

									//Sets up the identifier
									unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
									ECS::SetUpIdentifier(entity, bitHolder, "levelDone");
								}
								else
								{
									//moves dynamic object out of static object it is colliding with
									trans1.SetPosition(trans1.GetPosition() + (-body1.GetVelocity() * (Timer::deltaTime)));
									//once it collides we stop
									body1.SetAcceleration(vec3(0.f, 0.f, 0.f));
									body1.SetVelocity(vec3(0.f, 0.f, 0.f));
									if (body1.GetBodyID() & CollisionIDs::Bullet())
									{
										ECS::DestroyEntity(entity);
										if (ECS::GetComponent<EntityIdentifier>(entity2).GetIdentifier()& EntityIdentifier::HealthArmourBit())
										{
											ECS::GetComponent<HealthArmour>(entity2).SetDamaged(true);
										}
										break;
									}
								}
							}
						}
						else if (body2.GetBodyType() == BodyType::CIRCLE)
						{

						}
					}
				}
			}
		}
	}
}

bool PhysicsSystem::BoxBoxCollision(std::pair<PhysicsBody&, Box> group1, std::pair<PhysicsBody&, Box> group2)
{
	
	if (group1.first.GetCollideID() & group2.first.GetBodyID())
	{
		//is x collide
		bool axisXCollide = group1.second.m_bottomRight.x >= group2.second.m_bottomLeft.x &&
			group2.second.m_bottomRight.x >= group1.second.m_bottomLeft.x;

		//is y collide
		bool axisYCollide = group1.second.m_topLeft.y >= group2.second.m_bottomLeft.y &&
			group2.second.m_topLeft.y >= group1.second.m_bottomLeft.y;
		//true if both overlap
		return axisXCollide && axisYCollide;
	}
	else
	{
		return false;
	}
}

void PhysicsSystem::Init()
{
	physicsDrawShader.Load("./assets/shader/PhysicsDraw.vert", "./assets/shader/PhysicsDraw.frag");
}

void PhysicsSystem::Draw(entt::registry* reg)
{
	auto view = reg->view<PhysicsBody, Transform>();
	auto& cam = reg->get<Camera>(EntityIdentifier::MainCamera());
	if (PhysicsBody::GetDraw())
	{
		for (auto entity : view)
		{
			auto& physBody = view.get<PhysicsBody>(entity);
			auto& trans = view.get<Transform>(entity);
			//Temporary transform so we can actually draw the bodies
			Transform temp = trans;
			temp.SetScale(vec3(physBody.GetWidth(), physBody.GetHeight(), 1.f));
			//Sets the pos so offset is relevant
			temp.SetPosition(temp.GetPosition() + vec3(physBody.GetCenterOffset().x, physBody.GetCenterOffset().y, 0.f));
			//Puts the temporary transform for the physics body at top z 
			temp.SetPositionZ(100.f);
			//Updates the transform to create model matrix 
			temp.Update();

			std::string fileName = "Masks/";
			if (physBody.GetBodyType() == BodyType::BOX)
			{
				fileName += "SquareMask.png";
			}
			else if (physBody.GetBodyType() == BodyType::CIRCLE)
			{
				fileName += "CircleMask.png";
			}
			Texture* mask = TextureManager::FindTexture(fileName);

			//BInds the draw shader
			physicsDrawShader.Bind();
			//Sends the uniforms we need for drawing the bodies
			physicsDrawShader.SendUniform("uView", cam.GetView());
			physicsDrawShader.SendUniform("uProj", cam.GetProjection());
			physicsDrawShader.SendUniform("uModel", temp.GetLocalToWorldMatrix());
			physicsDrawShader.SendUniform("uColor", vec4(1.f, 0.f, 0.f, 0.3f));

			mask->Bind(0);

			//draws the body
			physBody.DrawBody();
			mask->Unbind(0);

			//unbinds the shader
			physicsDrawShader.Unbind();
		}
	}

}
