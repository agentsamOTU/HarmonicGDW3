#include "AssignScene1.h"

AssignScene1::AssignScene1(std::string name)
	:Scene(name)
{
}

void AssignScene1::InitScene(float windowWidth, float windowHeight)
{
	//Dynamically allocates the register
	//you can later reInit this scene
	m_sceneReg = new entt::registry;

	//attach the register
	ECS::AttachRegister(m_sceneReg);

	//sets up aspect ratio for camera
	float aspectRatio = windowWidth / windowHeight;

	//setup main camera entity
	{
		//creates camera entity
		auto entity = ECS::CreateEntity();
		EntityIdentifier::MainCamera(entity);

		//create new orthographic camera
		ECS::AttachComponent<Camera>(entity);
		ECS::AttachComponent<VerticalScroll>(entity);
		ECS::AttachComponent<HorizontalScroll>(entity);
		ECS::AttachComponent<Transform>(entity);
		vec4 temp = ECS::GetComponent<Camera>(entity).GetOrthoSize();
		ECS::GetComponent<Camera>(entity).SetWindowSize(vec2(float(windowWidth), float(windowHeight)));
		ECS::GetComponent<Camera>(entity).Orthographic(aspectRatio, temp.x, temp.y, temp.z, temp.w, -100.f, 100.f);
		ECS::GetComponent<VerticalScroll>(entity).SetCam(&ECS::GetComponent<Camera>(entity));
		ECS::GetComponent<VerticalScroll>(entity).SetOffset(0.f);
		ECS::GetComponent<HorizontalScroll>(entity).SetCam(&ECS::GetComponent<Camera>(entity));
		ECS::GetComponent<HorizontalScroll>(entity).SetOffset(0.f);
		
		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::VertScrollCameraBit()|| EntityIdentifier::HoriScrollCameraBit() || EntityIdentifier::CameraBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Main Camera");
		ECS::SetIsMainCamera(entity, true);
	}
	
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "DoomGuy_Walk.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(fileName);
		animController.AddAnimation(Animation());
		animController.SetActiveAnim(0);
		//adds first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(60.f, 289.f), vec2(269.f, 110.f));
		anim.AddFrame(vec2(739.f, 289.f), vec2(949.f, 110.f));
		anim.AddFrame(vec2(60.f, 289.f), vec2(269.f, 110.f));
		anim.AddFrame(vec2(739.f, 629.f), vec2(949.f, 450.f));

		anim.SetRepeating(true);
		//sets time between frames
		anim.SetSecPerFrame(0.1667f);
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 24, 24, true, &animController);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, -60.f, 10.f));
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);


		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Player(), (CollisionIDs::Environment() | CollisionIDs::Enemy()), true);
		tempPhsBody.SetGravity(false);
		tempPhsBody.SetFriction(1.f);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit()|EntityIdentifier::PhysicsBit();
		ECS::SetUpIdentifier(entity, bitHolder, "doomGuy");
		ECS::SetIsMainPlayer(entity, true);
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 200, 250);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 0.f, 0.f));
		


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Dark Background");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string Zombie = "Zombie_Walk.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(69.f, 259.f), vec2(279.f, 80.f));
		anim.AddFrame(vec2(410.f, 259.f), vec2(619.f, 80.f));
		anim.AddFrame(vec2(69.f, 259.f), vec2(279.f, 80.f));
		anim.AddFrame(vec2(750.f, 259.f), vec2(959.f, 80.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-20.f, 360.f, 100.f));
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Enemy(), (CollisionIDs::Player() | CollisionIDs::Environment()), true);
		tempPhsBody.SetGravity(false);
		tempPhsBody.SetFriction(1.f);

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit() | EntityIdentifier::PhysicsBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
	}
	//level 1 begins

	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 50, 190);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 150.f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Dark Background");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 200, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, -125.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 75, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-62.f, 125.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		
		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 75, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(62.f, 125.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(60.f, 70.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-60.f, 70.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-60.f, -70.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(60.f, -70.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 270);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-110.f, 0.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 270);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(110.f, 0.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 130);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-35.f, 180.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 130);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(35.f, 180.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	//level 1 ends
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 326, 150);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 320.f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Dark Background");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 131.5, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(97.5, 405, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 131.5, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-97.5, 405, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 140, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(115.2, 235, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 140, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-115.2, 235, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 65);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(173.f, 270.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 65);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(173.f, 382.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 170);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-173.f, 330.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall1");
	}
	//level 2 begins


	ECS::GetComponent<VerticalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
	ECS::GetComponent<HorizontalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
}
