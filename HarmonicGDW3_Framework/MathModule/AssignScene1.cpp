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
		animController.AddAnimation(Animation());
		animController.SetActiveAnim(0);
		//adds first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(60.f, 289.f), vec2(269.f, 110.f));
		anim.AddFrame(vec2(739.f, 289.f), vec2(949.f, 110.f));
		anim.AddFrame(vec2(60.f, 289.f), vec2(269.f, 110.f));
		anim.AddFrame(vec2(739.f, 629.f), vec2(949.f, 450.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(60.f, 289.f), vec2(269.f, 110.f));

		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		//sets time between frames
		anim.SetSecPerFrame(0.1667f);
		animController.SetActiveAnim(1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 24, 24, true, &animController);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 200.f, 100.f));
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);


		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()/0.9), float(tempSpr.GetHeight()/0.9),
			vec2(0.f, 0.f),
			CollisionIDs::Player(), (CollisionIDs::Environment() | CollisionIDs::Enemy()|CollisionIDs::Pickup()|CollisionIDs::Acid()), true);
		tempPhsBody.SetGravity(false);
		tempPhsBody.SetFriction(1.f);
		tempPhsBody.SetMaxVelo(70.f);
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


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
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<HealthArmour>(entity);
		ECS::AttachComponent<Imp>(entity);

		//Sets up components
		std::string Demon = "DemonMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Demon);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(68.f, 905.f), vec2(277.f, 766.f));
		anim.AddFrame(vec2(408.f, 903.f), vec2(617.f, 764.f));
		anim.AddFrame(vec2(68.f, 905.f), vec2(277.f, 766.f));
		anim.AddFrame(vec2(743.f, 911.f), vec2(953.f, 772.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(67.f, 895.f), vec2(277.f, 766.f));
		anim2.AddFrame(vec2(71.f, 572.f), vec2(280.f, 442.f));
		anim2.AddFrame(vec2(411.f, 572.f), vec2(620.f, 442.f));
		anim2.AddFrame(vec2(751.f, 573.f), vec2(960.f, 443.f));
		anim2.AddFrame(vec2(1091.f, 573.f), vec2(1300.f, 443.f));
		anim2.AddFrame(vec2(751.f, 573.f), vec2(960.f, 443.f));
		anim2.AddFrame(vec2(411.f, 572.f), vec2(620.f, 442.f));
		anim2.AddFrame(vec2(71.f, 572.f), vec2(280.f, 442.f));
		anim2.AddFrame(vec2(67.f, 895.f), vec2(277.f, 766.f));
		auto& anim3 = animController.GetAnimation(2);
		anim.AddFrame(vec2(28.f, 290.f), vec2(298.f, 41.f));
		anim.AddFrame(vec2(371.f, 290.f), vec2(640.f, 41.f));
		anim.AddFrame(vec2(711.f, 290.f), vec2(980.f, 41.f));
		anim.AddFrame(vec2(1051.f, 290.f), vec2(1321.f, 41.f));
		anim.AddFrame(vec2(1391.f, 290.f), vec2(1660.f, 41.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Demon, 22, 22, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(20.f, 360.f, 10.f));
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
			|EntityIdentifier::PhysicsBit()| EntityIdentifier::HealthArmourBit()| EntityIdentifier::ImpBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Imp");
	}
	//level 1 begins

	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "HallWayUp.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 50, 120);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 185.f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HallWayUp");
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
		anim.SetSecPerFrame(0.05f);
		anim2.SetSecPerFrame(0.05f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 50), float(tempSpr.GetHeight()),
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
		anim.SetSecPerFrame(0.05f);
		anim2.SetSecPerFrame(0.05f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 50), float(tempSpr.GetHeight()),
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
		ECS::SetUpIdentifier(entity, bitHolder, "SideWaysWall1");
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
		anim.SetSecPerFrame(0.05f);
		anim2.SetSecPerFrame(0.05f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 50), float(tempSpr.GetHeight()),
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
		anim.SetSecPerFrame(0.05f);
		anim2.SetSecPerFrame(0.05f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 50), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 65, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 508.8, 99.f));

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

	//level 3 starts
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
		tempPhsBody = PhysicsBody(float(tempSpr.GetHeight()), float(tempSpr.GetWidth() + 50),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 50, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(173.f, 326.f, 99.f));

		ECS::GetComponent<Transform>(entity).SetRotationAngleZ(PI/2);

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(251, 292.5, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall3");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(251, 359.6, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall3");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(330, 359.6, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall3");
	}

	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "HallWaySide.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 175, 50);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(249.8f, 326.f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HallWaySide3");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(327.f, 218.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "SideWaysWall3");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(405.5f, 284.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "SideWaysWall3");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "HallWayUp.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 59, 153);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(366.4f, 275.f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HallWayUp");
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


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(437.f, 74.f, 0.f));



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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(437.1f, -60.5f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall3");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(327.f, 64.4f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "SideWaysWall3");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(546.9f, 64.4f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "SideWaysWall3");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 147, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(483.3f, 209.1f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall3");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(385.f, 52.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(477.f, 100.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
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
		anim.SetSecPerFrame(0.05f);
		anim2.SetSecPerFrame(0.05f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 50), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 59, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(366.1f, 209.9f, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
	}
	//add shotgun
	//add keycard


	//level 4 begins
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-132.4, 509.9, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall4");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(132.4, 509.9, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall4");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(260.4, 509.9, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall4");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-260.4, 509.9, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall4");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 100);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-350.4, 569.8, 10.f));

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
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 100);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(350.4, 569.8, 10.f));

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
		auto& rot = ECS::GetComponent<Transform>(entity);
		rot.SetRotationAngleZ(PI / 2);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight() + 50),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 65, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-351.8, 652.2, 99.f));

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
		auto& rot = ECS::GetComponent<Transform>(entity);
		rot.SetRotationAngleZ(PI / 2);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight() + 50),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 65, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(351.8, 652.2, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 100);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(350.4, 734.6, 10.f));

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
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 100);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-350.4, 734.6, 10.f));

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
		std::string fileName = "sidewaysWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 100);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(350.4, 734.6, 10.f));

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
		std::string fileName = "longWall.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 200, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-132.3, 794.8, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall4");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(132.3, 794.8, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall4");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(260.4, 794.8, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall4");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-260.4, 794.8, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall4");
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
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 50), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 65, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 796.3, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 681.f, 266.8);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 652.4, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Dark Background");
	}



	//level 7 starts
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
		auto& rot = ECS::GetComponent<Transform>(entity);
		rot.SetRotationAngleZ(PI / 2);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight() + 50),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 65, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-473.f, 652.2, 99.f));

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
		auto& rot = ECS::GetComponent<Transform>(entity);
		rot.SetRotationAngleZ(PI / 2);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight() + 50),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 55, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-765.4f, 650.7f, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 143, 63);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-412.f, 651.7f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "hallway7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 104, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-412.3f, 610.5f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 104, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-412.3f, 692.9f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall7");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 271, 213);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-619.f, 652.f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "floor7");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 120, 108);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-605.6f, 812.4f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "floor7");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 120, 108);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-605.6f, 491.7f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "floor7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 83, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-504.4f, 767.9f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 83, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-504.4f, 535.6f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 89, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-709.8f, 767.9f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 89, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-709.8f, 535.6f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 120, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-605.4f, 875.9f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 120, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-605.4f, 427.1f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 77);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-473.6f, 581.7f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 77);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-473.6f, 721.8f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 109);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-535.6f, 831.4f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 109);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-675.5f, 831.4f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 109);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-535.6f, 471.3f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall7");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 109);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-675.5f, 471.3f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall7");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-764.1f, 575.7f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall7");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-764.1f, 727.9f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall7");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-606.5f, 812.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-606.5f, 490.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-682.f, 600.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-682.f, 705.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-613.f, 655.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-604.f, 760.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
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
		std::string Zombie = "ZombieMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(Zombie);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2454.f, 603.f), vec2(2664.f, 424.f));
		anim.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim.AddFrame(vec2(2794.f, 603.f), vec2(3004.f, 424.f));
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(2114.f, 633.f), vec2(2323.f, 424.f));
		anim2.AddFrame(vec2(2114.f, 291.f), vec2(2323.f, 82.f));
		anim2.AddFrame(vec2(2454.f, 291.f), vec2(2663.f, 82.f));
		anim2.AddFrame(vec2(2794.f, 291.f), vec2(3003.f, 82.f));
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(39.f, 632.f), vec2(309.f, 372.f));
		anim3.AddFrame(vec2(381.f, 632.f), vec2(651.f, 372.f));
		anim3.AddFrame(vec2(1061.f, 632.f), vec2(1330.f, 372.f));
		anim3.AddFrame(vec2(1400.f, 632.f), vec2(1670.f, 372.f));
		anim3.AddFrame(vec2(1741.f, 632.f), vec2(2010.f, 372.f));
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(2114.f, 603.f), vec2(2323.f, 424.f));
		anim4.AddFrame(vec2(70.f, 260.f), vec2(280.f, 81.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		anim4.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim4.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Zombie, 24, 24, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-604.f, 545.f, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ZombieBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Zombie");
	}
	//level 7 ends

	ECS::GetComponent<VerticalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
	ECS::GetComponent<HorizontalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
}
