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
		ECS::AttachComponent<PlayerWeapons>(entity);
		ECS::AttachComponent<HealthArmour>(entity);

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
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, -60.f, 100.f));
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);


		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Player(), (CollisionIDs::Environment() | CollisionIDs::Enemy()|CollisionIDs::Pickup()|CollisionIDs::Acid()), true);
		tempPhsBody.SetGravity(false);
		tempPhsBody.SetFriction(1.f);
		ECS::GetComponent<HealthArmour>(entity).SetHealth(100);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit() 
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::PlayerWeaponBit();
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
		ECS::AttachComponent<HealthArmour>(entity);
		ECS::AttachComponent<Zombie>(entity);

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-20.f, 360.f, 10.f));
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Enemy(), (CollisionIDs::Player() | CollisionIDs::Environment()), true);
		tempPhsBody.SetGravity(false);
		tempPhsBody.SetFriction(1.f);

		ECS::GetComponent<HealthArmour>(entity).SetHealth(30);

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit() 
			|EntityIdentifier::PhysicsBit()| EntityIdentifier::HealthArmourBit()| EntityIdentifier::ZombieBit();
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
		std::string fileName = "Floor.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 50, 120);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 185.f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Hallway1");
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
		std::string fileName = "HalfWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 75, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-62.f, 125.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall1");
	}
	
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		
		//sets up components
		std::string fileName = "HalfWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 75, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(62.f, 125.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "Pillar.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(60.f, 70.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Pillar1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "Pillar.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-60.f, 70.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Pillar1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "Pillar.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-60.f, -70.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Pillar");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "Pillar.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(60.f, -70.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Pillar1");
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
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Door>(entity);

		//Sets up components
		std::string Door = "RegularDoor.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Door);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(1);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(20.f, 210.f), vec2(310.f, 120.f));
		anim.AddFrame(vec2(360.f, 210.f), vec2(649.f, 120.f));
		anim.AddFrame(vec2(700.f, 210.f), vec2(989.f, 120.f));
		anim.AddFrame(vec2(1040.f, 210.f), vec2(1330.f, 120.f));
		anim.AddFrame(vec2(1379.f, 210.f), vec2(1669.f, 120.f));
		anim.AddFrame(vec2(1720.f, 210.f), vec2(2009.f, 120.f));
		anim.AddFrame(vec2(2060.f, 210.f), vec2(2349.f, 120.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2060.f, 210.f), vec2(2349.f, 120.f));
		anim2.AddFrame(vec2(1720.f, 210.f), vec2(2009.f, 120.f));
		anim2.AddFrame(vec2(1379.f, 210.f), vec2(1669.f, 120.f));
		anim2.AddFrame(vec2(1040.f, 210.f), vec2(1330.f, 120.f));
		anim2.AddFrame(vec2(700.f, 210.f), vec2(989.f, 120.f));
		anim2.AddFrame(vec2(360.f, 210.f), vec2(649.f, 120.f));
		anim2.AddFrame(vec2(20.f, 210.f), vec2(310.f, 120.f));
		//Makes it repeat
		anim.SetRepeating(false);
		anim2.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1f);
		anim2.SetSecPerFrame(0.1f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 20), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 52, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 125.f, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Door>(entity);

		//Sets up components
		std::string Door = "RegularDoor.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Door);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(1);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(20.f, 210.f), vec2(310.f, 120.f));
		anim.AddFrame(vec2(360.f, 210.f), vec2(649.f, 120.f));
		anim.AddFrame(vec2(700.f, 210.f), vec2(989.f, 120.f));
		anim.AddFrame(vec2(1040.f, 210.f), vec2(1330.f, 120.f));
		anim.AddFrame(vec2(1379.f, 210.f), vec2(1669.f, 120.f));
		anim.AddFrame(vec2(1720.f, 210.f), vec2(2009.f, 120.f));
		anim.AddFrame(vec2(2060.f, 210.f), vec2(2349.f, 120.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2060.f, 210.f), vec2(2349.f, 120.f));
		anim2.AddFrame(vec2(1720.f, 210.f), vec2(2009.f, 120.f));
		anim2.AddFrame(vec2(1379.f, 210.f), vec2(1669.f, 120.f));
		anim2.AddFrame(vec2(1040.f, 210.f), vec2(1330.f, 120.f));
		anim2.AddFrame(vec2(700.f, 210.f), vec2(989.f, 120.f));
		anim2.AddFrame(vec2(360.f, 210.f), vec2(649.f, 120.f));
		anim2.AddFrame(vec2(20.f, 210.f), vec2(310.f, 120.f));
		//Makes it repeat
		anim.SetRepeating(false);
		anim2.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1f);
		anim2.SetSecPerFrame(0.1f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 20), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 52, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 235.f, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
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
		std::string fileName = "HalfSideWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 25, 65);

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
		std::string fileName = "HalfSideWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 25, 65);

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
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 70, 100);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 445.f, 0.f));



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
		std::string fileName = "HalfSideWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 100);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-40.f, 450.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Halfsidewayswall1");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "HalfSideWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 100);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(40.f, 450.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfsidewaysWall1");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Door>(entity);

		//Sets up components
		std::string Door = "RegularDoor.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Door);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(1);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(20.f, 210.f), vec2(310.f, 120.f));
		anim.AddFrame(vec2(360.f, 210.f), vec2(649.f, 120.f));
		anim.AddFrame(vec2(700.f, 210.f), vec2(989.f, 120.f));
		anim.AddFrame(vec2(1040.f, 210.f), vec2(1330.f, 120.f));
		anim.AddFrame(vec2(1379.f, 210.f), vec2(1669.f, 120.f));
		anim.AddFrame(vec2(1720.f, 210.f), vec2(2009.f, 120.f));
		anim.AddFrame(vec2(2060.f, 210.f), vec2(2349.f, 120.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2060.f, 210.f), vec2(2349.f, 120.f));
		anim2.AddFrame(vec2(1720.f, 210.f), vec2(2009.f, 120.f));
		anim2.AddFrame(vec2(1379.f, 210.f), vec2(1669.f, 120.f));
		anim2.AddFrame(vec2(1040.f, 210.f), vec2(1330.f, 120.f));
		anim2.AddFrame(vec2(700.f, 210.f), vec2(989.f, 120.f));
		anim2.AddFrame(vec2(360.f, 210.f), vec2(649.f, 120.f));
		anim2.AddFrame(vec2(20.f, 210.f), vec2(310.f, 120.f));
		//Makes it repeat
		anim.SetRepeating(false);
		anim2.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1f);
		anim2.SetSecPerFrame(0.1f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 20), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 65, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 407.f, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Door>(entity);

		//Sets up components
		std::string Door = "RegularDoor.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Door);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(1);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(20.f, 210.f), vec2(310.f, 120.f));
		anim.AddFrame(vec2(360.f, 210.f), vec2(649.f, 120.f));
		anim.AddFrame(vec2(700.f, 210.f), vec2(989.f, 120.f));
		anim.AddFrame(vec2(1040.f, 210.f), vec2(1330.f, 120.f));
		anim.AddFrame(vec2(1379.f, 210.f), vec2(1669.f, 120.f));
		anim.AddFrame(vec2(1720.f, 210.f), vec2(2009.f, 120.f));
		anim.AddFrame(vec2(2060.f, 210.f), vec2(2349.f, 120.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2060.f, 210.f), vec2(2349.f, 120.f));
		anim2.AddFrame(vec2(1720.f, 210.f), vec2(2009.f, 120.f));
		anim2.AddFrame(vec2(1379.f, 210.f), vec2(1669.f, 120.f));
		anim2.AddFrame(vec2(1040.f, 210.f), vec2(1330.f, 120.f));
		anim2.AddFrame(vec2(700.f, 210.f), vec2(989.f, 120.f));
		anim2.AddFrame(vec2(360.f, 210.f), vec2(649.f, 120.f));
		anim2.AddFrame(vec2(20.f, 210.f), vec2(310.f, 120.f));
		//Makes it repeat
		anim.SetRepeating(false);
		anim2.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1f);
		anim2.SetSecPerFrame(0.1f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 20), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 65, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 488.f, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Pickup>(entity);

		//Sets up components
		std::string Potion = "HealPot.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Potion);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(140.f, 229.f), vec2(209.f, 140.f)); //Neutral
		anim.AddFrame(vec2(280.f, 229.f), vec2(349.f, 140.f)); //Down1
		anim.AddFrame(vec2(140.f, 229.f), vec2(209.f, 140.f)); //Neutral
		anim.AddFrame(vec2(410.f, 229.f), vec2(479.f, 140.f)); //Up1

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 20), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetHealth(20,0);
		ECS::GetComponent<Pickup>(entity).SetAmmo(0, 12, 1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(Potion, 7, 10, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 80.f, 101.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Potion");
	}
	//level 2 ends


	ECS::GetComponent<VerticalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
	ECS::GetComponent<HorizontalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
}
