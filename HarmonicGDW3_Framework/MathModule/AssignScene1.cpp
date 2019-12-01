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
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);

		//Sets up components
		std::string RedNum = "NumberLineR.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(RedNum);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());

		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(9.f, 79.f), vec2(70.f, 0.f));
		auto& anim1 = animController.GetAnimation(1);
		anim1.AddFrame(vec2(95.f, 79.f), vec2(154.f, 0.f));
		auto& anim2 = animController.GetAnimation(2);
		anim2.AddFrame(vec2(170.f, 79.f), vec2(230.f, 0.f));
		auto& anim3 = animController.GetAnimation(3);
		anim3.AddFrame(vec2(250.f, 79.f), vec2(309.f, 0.f));
		auto& anim4 = animController.GetAnimation(4);
		anim4.AddFrame(vec2(330.f, 79.f), vec2(389.f, 0.f));
		auto& anim5 = animController.GetAnimation(5);
		anim5.AddFrame(vec2(410.f, 79.f), vec2(469.f, 0.f));
		auto& anim6 = animController.GetAnimation(6);
		anim6.AddFrame(vec2(490.f, 79.f), vec2(549.f, 0.f));
		auto& anim7 = animController.GetAnimation(7);
		anim7.AddFrame(vec2(570.f, 79.f), vec2(629.f, 0.f));
		auto& anim8 = animController.GetAnimation(8);
		anim8.AddFrame(vec2(650.f, 79.f), vec2(709.f, 0.f));
		auto& anim9 = animController.GetAnimation(9);
		anim9.AddFrame(vec2(730.f, 79.f), vec2(789.f, 0.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(RedNum, 6, 7.5, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-80.f, 10.f, 101.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "NumbersR");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);

		//Sets up components
		std::string RedNum = "NumberLineR.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(RedNum);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());

		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(9.f, 79.f), vec2(70.f, 0.f));
		auto& anim1 = animController.GetAnimation(1);
		anim1.AddFrame(vec2(95.f, 79.f), vec2(154.f, 0.f));
		auto& anim2 = animController.GetAnimation(2);
		anim2.AddFrame(vec2(170.f, 79.f), vec2(230.f, 0.f));
		auto& anim3 = animController.GetAnimation(3);
		anim3.AddFrame(vec2(250.f, 79.f), vec2(309.f, 0.f));
		auto& anim4 = animController.GetAnimation(4);
		anim4.AddFrame(vec2(330.f, 79.f), vec2(389.f, 0.f));
		auto& anim5 = animController.GetAnimation(5);
		anim5.AddFrame(vec2(410.f, 79.f), vec2(469.f, 0.f));
		auto& anim6 = animController.GetAnimation(6);
		anim6.AddFrame(vec2(490.f, 79.f), vec2(549.f, 0.f));
		auto& anim7 = animController.GetAnimation(7);
		anim7.AddFrame(vec2(570.f, 79.f), vec2(629.f, 0.f));
		auto& anim8 = animController.GetAnimation(8);
		anim8.AddFrame(vec2(650.f, 79.f), vec2(709.f, 0.f));
		auto& anim9 = animController.GetAnimation(9);
		anim9.AddFrame(vec2(730.f, 79.f), vec2(789.f, 0.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(RedNum, 6,7.5, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-80.f, 10.f, 101.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "NumbersR");
	}
	{
		// Creates entity
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);

		//Sets up components
		std::string BlueNum = "NumberLineB.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(BlueNum);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());

		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(9.f, 79.f), vec2(70.f, 0.f));
		auto& anim1 = animController.GetAnimation(1);
		anim1.AddFrame(vec2(95.f, 79.f), vec2(154.f, 0.f));
		auto& anim2 = animController.GetAnimation(2);
		anim2.AddFrame(vec2(170.f, 79.f), vec2(230.f, 0.f));
		auto& anim3 = animController.GetAnimation(3);
		anim3.AddFrame(vec2(250.f, 79.f), vec2(309.f, 0.f));
		auto& anim4 = animController.GetAnimation(4);
		anim4.AddFrame(vec2(330.f, 79.f), vec2(389.f, 0.f));
		auto& anim5 = animController.GetAnimation(5);
		anim5.AddFrame(vec2(410.f, 79.f), vec2(469.f, 0.f));
		auto& anim6 = animController.GetAnimation(6);
		anim6.AddFrame(vec2(490.f, 79.f), vec2(549.f, 0.f));
		auto& anim7 = animController.GetAnimation(7);
		anim7.AddFrame(vec2(570.f, 79.f), vec2(629.f, 0.f));
		auto& anim8 = animController.GetAnimation(8);
		anim8.AddFrame(vec2(650.f, 79.f), vec2(709.f, 0.f));
		auto& anim9 = animController.GetAnimation(9);
		anim9.AddFrame(vec2(730.f, 79.f), vec2(789.f, 0.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(BlueNum, 6, 7.5, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-80.f, -10.f, 101.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "NumbersB");
	}
	{
		// Creates entity
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);

		//Sets up components
		std::string BlueNum = "NumberLineB.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(BlueNum);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());

		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(9.f, 79.f), vec2(70.f, 0.f));
		auto& anim1 = animController.GetAnimation(1);
		anim1.AddFrame(vec2(95.f, 79.f), vec2(154.f, 0.f));
		auto& anim2 = animController.GetAnimation(2);
		anim2.AddFrame(vec2(170.f, 79.f), vec2(230.f, 0.f));
		auto& anim3 = animController.GetAnimation(3);
		anim3.AddFrame(vec2(250.f, 79.f), vec2(309.f, 0.f));
		auto& anim4 = animController.GetAnimation(4);
		anim4.AddFrame(vec2(330.f, 79.f), vec2(389.f, 0.f));
		auto& anim5 = animController.GetAnimation(5);
		anim5.AddFrame(vec2(410.f, 79.f), vec2(469.f, 0.f));
		auto& anim6 = animController.GetAnimation(6);
		anim6.AddFrame(vec2(490.f, 79.f), vec2(549.f, 0.f));
		auto& anim7 = animController.GetAnimation(7);
		anim7.AddFrame(vec2(570.f, 79.f), vec2(629.f, 0.f));
		auto& anim8 = animController.GetAnimation(8);
		anim8.AddFrame(vec2(650.f, 79.f), vec2(709.f, 0.f));
		auto& anim9 = animController.GetAnimation(9);
		anim9.AddFrame(vec2(730.f, 79.f), vec2(789.f, 0.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(BlueNum, 6,7.5, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-80.f, -10.f, 101.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "NumbersB");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);

		//Sets up components
		std::string YellowNum = "NumberLineY.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(YellowNum);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());

		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(9.f, 79.f), vec2(70.f, 0.f));
		auto& anim1 = animController.GetAnimation(1);
		anim1.AddFrame(vec2(95.f, 79.f), vec2(154.f, 0.f));
		auto& anim2 = animController.GetAnimation(2);
		anim2.AddFrame(vec2(170.f, 79.f), vec2(230.f, 0.f));
		auto& anim3 = animController.GetAnimation(3);
		anim3.AddFrame(vec2(250.f, 79.f), vec2(309.f, 0.f));
		auto& anim4 = animController.GetAnimation(4);
		anim4.AddFrame(vec2(330.f, 79.f), vec2(389.f, 0.f));
		auto& anim5 = animController.GetAnimation(5);
		anim5.AddFrame(vec2(410.f, 79.f), vec2(469.f, 0.f));
		auto& anim6 = animController.GetAnimation(6);
		anim6.AddFrame(vec2(490.f, 79.f), vec2(549.f, 0.f));
		auto& anim7 = animController.GetAnimation(7);
		anim7.AddFrame(vec2(570.f, 79.f), vec2(629.f, 0.f));
		auto& anim8 = animController.GetAnimation(8);
		anim8.AddFrame(vec2(650.f, 79.f), vec2(709.f, 0.f));
		auto& anim9 = animController.GetAnimation(9);
		anim9.AddFrame(vec2(730.f, 79.f), vec2(789.f, 0.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(YellowNum, 6,7.5, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-80.f, -30.f, 101.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "NumbersY");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);

		//Sets up components
		std::string YellowNum = "NumberLineY.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(YellowNum);
		//Adds first animation
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());

		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(9.f, 79.f), vec2(70.f, 0.f));
		auto& anim1 = animController.GetAnimation(1);
		anim1.AddFrame(vec2(95.f, 79.f), vec2(154.f, 0.f));
		auto& anim2 = animController.GetAnimation(2);
		anim2.AddFrame(vec2(170.f, 79.f), vec2(230.f, 0.f));
		auto& anim3 = animController.GetAnimation(3);
		anim3.AddFrame(vec2(250.f, 79.f), vec2(309.f, 0.f));
		auto& anim4 = animController.GetAnimation(4);
		anim4.AddFrame(vec2(330.f, 79.f), vec2(389.f, 0.f));
		auto& anim5 = animController.GetAnimation(5);
		anim5.AddFrame(vec2(410.f, 79.f), vec2(469.f, 0.f));
		auto& anim6 = animController.GetAnimation(6);
		anim6.AddFrame(vec2(490.f, 79.f), vec2(549.f, 0.f));
		auto& anim7 = animController.GetAnimation(7);
		anim7.AddFrame(vec2(570.f, 79.f), vec2(629.f, 0.f));
		auto& anim8 = animController.GetAnimation(8);
		anim8.AddFrame(vec2(650.f, 79.f), vec2(709.f, 0.f));
		auto& anim9 = animController.GetAnimation(9);
		anim9.AddFrame(vec2(730.f, 79.f), vec2(789.f, 0.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(YellowNum, 6, 7.5, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-80.f, -30.f, 101.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "NumbersY");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//Sets up components
		std::string Stats = "Stats.png";

		ECS::GetComponent<Sprite>(entity).LoadSprite(Stats, 20, 25);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-80.f, -80.f, 101.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Stats");
	}
	{
		//Creates entity 
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//Sets up components
		std::string Stats = "false.png";

		ECS::GetComponent<Sprite>(entity).LoadSprite(Stats, 36, 34);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-80.f, -80.f, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "black box");
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
		std::string fileName = "DoomGuyMasterSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(fileName);
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.AddAnimation(Animation());
		animController.SetActiveAnim(0);
		//Walking w/ pistol
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(740.f, 629.f), vec2(950.f, 450.f));
		anim.AddFrame(vec2(1080.f, 969.f), vec2(1289.f, 790.f));
		anim.AddFrame(vec2(740.f, 629.f), vec2(950.f, 450.f));
		anim.AddFrame(vec2(59.f, 1309.f), vec2(269.f, 1130.f));
		//Static 
		auto& anim2 = animController.GetAnimation(1);
		anim2.AddFrame(vec2(740.f, 629.f), vec2(950.f, 450.f));
		//Shot gun walk
		auto& anim3 = animController.GetAnimation(2);
		anim3.AddFrame(vec2(400.f, 1319.f), vec2(609.f, 1130.f));
		anim3.AddFrame(vec2(1420.f, 979.f), vec2(1629.f, 790.f));
		anim3.AddFrame(vec2(400.f, 1319.f), vec2(609.f, 1130.f));
		anim3.AddFrame(vec2(1420.f, 1319.f), vec2(1629.f, 1130.f));
		//Shot gun static
		auto& anim4 = animController.GetAnimation(3);
		anim4.AddFrame(vec2(400.f, 1319.f), vec2(609.f, 1130.f));
		//Doom Guy(shot)
		auto& anim5 = animController.GetAnimation(4);
		anim5.AddFrame(vec2(400.f, 1349.f), vec2(609.f, 1129.f));
		anim5.AddFrame(vec2(1080.f, 1349.f), vec2(1289.f, 1129.f));
		anim5.AddFrame(vec2(1420.f, 329.f), vec2(1629.f, 110.f));
		anim5.AddFrame(vec2(1420.f, 670.f), vec2(1629.f, 450.f));
		anim5.AddFrame(vec2(400.f, 1349.f), vec2(609.f, 1129.f));
		//Doom Shoot(pist)
		auto& anim6 = animController.GetAnimation(5);
		anim6.AddFrame(vec2(739.f, 659.f), vec2(949.f, 450.f));
		anim6.AddFrame(vec2(1080.f, 659.f), vec2(1289.f, 450.f));
		anim6.AddFrame(vec2(61.f, 999.f), vec2(269.f, 789.f));
		anim6.AddFrame(vec2(400.f, 999.f), vec2(610.f, 789.f));
		anim6.AddFrame(vec2(739.f, 659.f), vec2(949.f, 450.f));
		//Doom Guy damage pist
		auto& anim7 = animController.GetAnimation(6);
		anim7.AddFrame(vec2(740.f, 629.f), vec2(950.f, 450.f));
		anim7.AddFrame(vec2(740.f, 969.f), vec2(949.f, 790.f));
		//Doom Guy damage shot
		auto& anim8 = animController.GetAnimation(7);
		anim8.AddFrame(vec2(400.f, 1319.f), vec2(609.f, 1130.f));
		anim8.AddFrame(vec2(740.f, 1319.f), vec2(949.f, 1130.f));
		//Doom Guy Dead
		auto& anim9 = animController.GetAnimation(8);
		anim9.AddFrame(vec2(40.f, 271.f), vec2(310.f, 22.f));
		anim9.AddFrame(vec2(380.f, 271.f), vec2(649.f, 21.f));
		anim9.AddFrame(vec2(1059.f, 279.f), vec2(1329.f, 30.f));
		anim9.AddFrame(vec2(39.f, 619.f), vec2(309.f, 369.f));
		anim9.AddFrame(vec2(380.f, 619.f), vec2(659.f, 369.f));
		//Doom guy hurt (Shot gun)
		auto& anim10 = animController.GetAnimation(9);
		anim10.AddFrame(vec2(400.f, 1319.f), vec2(609.f, 1130.f));
		anim10.AddFrame(vec2(740.f, 1319.f), vec2(949.f, 1130.f));
		//Doom guy hurt (pistol)
		auto& anim11 = animController.GetAnimation(10);
		anim11.AddFrame(vec2(740.f, 629.f), vec2(950.f, 450.f));
		anim11.AddFrame(vec2(740.f, 969.f), vec2(949.f, 790.f));

		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(true);
		anim4.SetRepeating(false);
		anim5.SetRepeating(false);
		anim6.SetRepeating(false);
		anim7.SetRepeating(true);
		anim8.SetRepeating(true);
		anim9.SetRepeating(false);
		anim10.SetRepeating(false);
		anim11.SetRepeating(false);
		//sets time between frames
		anim.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);
		anim5.SetSecPerFrame(0.05f);
		anim6.SetSecPerFrame(0.05f);
		anim7.SetSecPerFrame(0.1667f);
		anim8.SetSecPerFrame(0.1667f);
		anim9.SetSecPerFrame(0.1667f);
		anim10.SetSecPerFrame(0.05f);
		anim11.SetSecPerFrame(0.05f);
		animController.SetActiveAnim(1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 24, 24, true, &animController);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 200.f, 100.f));
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);


		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()/1.2), float(tempSpr.GetHeight()/1.2),
			vec2(0.f, 0.f),
			CollisionIDs::Player(), (CollisionIDs::Environment() | CollisionIDs::Enemy()|CollisionIDs::Pickup()|CollisionIDs::Acid()), true);
		tempPhsBody.SetGravity(false);
		tempPhsBody.SetFriction(1.f);
		tempPhsBody.SetMaxVelo(60.f);
		ECS::GetComponent<HealthArmour>(entity).SetHealth(75);

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
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "acidpool.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 50, 50);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);


		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()-30), float(tempSpr.GetHeight()-30),
			vec2(0.f, 0.f),
			CollisionIDs::Acid(), CollisionIDs::Player(), true);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 0.f, 2.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Acid");
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
		std::string ammo = "ammopickup.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(ammo);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(130.f, 210.f), vec2(200.f, 140.f));
		anim.AddFrame(vec2(470.f, 210.f), vec2(539.f, 140.f));
		anim.AddFrame(vec2(130.f, 210.f), vec2(200.f, 140.f));
		anim.AddFrame(vec2(810.f, 210.f), vec2(879.f, 140.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetAmmo(5, 0, 1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(ammo, 6, 6, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-20.f, 80.f, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Pistam");
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
		std::string ammo = "ammopickup2.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(ammo);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(130.f, 210.f), vec2(200.f, 140.f));
		anim.AddFrame(vec2(470.f, 210.f), vec2(539.f, 140.f));
		anim.AddFrame(vec2(130.f, 210.f), vec2(200.f, 140.f));
		anim.AddFrame(vec2(810.f, 210.f), vec2(879.f, 140.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetAmmo(0, 5, 1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(ammo, 6, 6, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(20.f, 80.f, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Shotam");
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
		std::string chest = "ChestArmor.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(chest);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(120.f, 210.f), vec2(209.f, 110.f));
		anim.AddFrame(vec2(460.f, 210.f), vec2(549.f, 110.f));
		anim.AddFrame(vec2(120.f, 210.f), vec2(209.f, 110.f));
		anim.AddFrame(vec2(800.f, 210.f), vec2(889.f, 110.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetHealth(0, 50);
		ECS::GetComponent<Sprite>(entity).LoadSprite(chest, 10, 12, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-20.f, 40.f, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Chestar");
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
		std::string med = "Medkit.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(med);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(120.f, 209.f), vec2(209.f, 119.f));
		anim.AddFrame(vec2(460.f, 209.f), vec2(549.f, 119.f));
		anim.AddFrame(vec2(120.f, 209.f), vec2(209.f, 119.f));
		anim.AddFrame(vec2(800.f, 209.f), vec2(890.f, 119.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetHealth(50, 0);
		ECS::GetComponent<Sprite>(entity).LoadSprite(med, 10, 12, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-20.f, 20.f, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Medkit");
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
		std::string card = "YellowKeyCard.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(card);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(470.f, 230.f), vec2(539.f, 141.f));
		anim.AddFrame(vec2(214.f, 230.f), vec2(283.f, 141.f));
		anim.AddFrame(vec2(470.f, 230.f), vec2(539.f, 141.f));
		anim.AddFrame(vec2(748.f, 230.f), vec2(817.f, 141.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetLocks(0, 0, 0, 1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(card, 7, 12, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(20.f, 20.f, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Keycard");
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
		anim3.AddFrame(vec2(28.f, 290.f), vec2(298.f, 41.f));
		anim3.AddFrame(vec2(371.f, 290.f), vec2(640.f, 41.f));
		anim3.AddFrame(vec2(711.f, 290.f), vec2(980.f, 41.f));
		anim3.AddFrame(vec2(1051.f, 290.f), vec2(1321.f, 41.f));
		anim3.AddFrame(vec2(1391.f, 290.f), vec2(1660.f, 41.f));


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
		std::string fileName = "Surface.png";
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

		ECS::GetComponent<Pickup>(entity).SetHealth(15, 0);
		ECS::GetComponent<Sprite>(entity).LoadSprite(Potion, 7, 10, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-66.290, -1.043, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Potion");
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
		std::string helm = "HelmetArmor.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(helm);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(130.f, 189.f), vec2(199.f, 130.f));
		anim.AddFrame(vec2(470.f, 189.f), vec2(539.f, 130.f));
		anim.AddFrame(vec2(130.f, 189.f), vec2(199.f, 130.f));
		anim.AddFrame(vec2(810.f, 189.f), vec2(879.f, 130.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetHealth(0, 25);
		ECS::GetComponent<Sprite>(entity).LoadSprite(helm, 8, 8, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(66.290, -1.043, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Helmar");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 70, 128);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 456.f, 0.f));


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
		std::string fileName = "Surface.png";
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
		std::string fileName = "Surface.png";
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
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "acidpool.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 50, 175);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);


		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() - 30), float(tempSpr.GetHeight() - 30),
			vec2(0.f, 0.f),
			CollisionIDs::Acid(), CollisionIDs::Player(), true);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(505.975, 75.523, 2.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Acid");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "acidpool.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 50, 175);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);


		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() - 30), float(tempSpr.GetHeight() - 30),
			vec2(0.f, 0.f),
			CollisionIDs::Acid(), CollisionIDs::Player(), true);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(375.800, 75.523, 2.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Acid");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Pickup>(entity);
		ECS::AttachComponent<PlayerWeapons>(entity);

		//sets up components
		std::string shotgun = "shotgunpickup.png";
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetAmmo(0, 5, 1);
		ECS::GetComponent<PlayerWeapons>(entity).SetHasShotgun(true);
		ECS::GetComponent<Sprite>(entity).LoadSprite(shotgun, 45, 30, false);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(442.450, -21.651, 5.f));

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Shotgun");
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
		std::string ammo = "ammopickup2.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(ammo);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(130.f, 210.f), vec2(200.f, 140.f));
		anim.AddFrame(vec2(470.f, 210.f), vec2(539.f, 140.f));
		anim.AddFrame(vec2(130.f, 210.f), vec2(200.f, 140.f));
		anim.AddFrame(vec2(810.f, 210.f), vec2(879.f, 140.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetAmmo(0, 5, 1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(ammo, 6, 6, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(505.975, -21.651, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Shotam");
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
		std::string ammo = "ammopickup2.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(ammo);
		//Adds first animation
		animController.AddAnimation(Animation());
		//Sets active animation
		animController.SetActiveAnim(0);

		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(130.f, 210.f), vec2(200.f, 140.f));
		anim.AddFrame(vec2(470.f, 210.f), vec2(539.f, 140.f));
		anim.AddFrame(vec2(130.f, 210.f), vec2(200.f, 140.f));
		anim.AddFrame(vec2(810.f, 210.f), vec2(879.f, 140.f));

		//Makes it repeat
		anim.SetRepeating(true);
		//Sets the time between frames
		anim.SetSecPerFrame(0.2f);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Pickup(), CollisionIDs::Player(), false);

		ECS::GetComponent<Pickup>(entity).SetAmmo(0, 5, 1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(ammo, 6, 6, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(375.800, -21.651, 5.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Shotam");
	}


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
		std::string fileName = "Pillar.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-264.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(264.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-264.323, 592.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(264.323, 592.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-244.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(244.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-264.323, 612.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(264.323, 612.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-224.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(224.323, 572.136, 10.f));

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
		std::string fileName = "Pillar.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-264.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(264.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-264.323, 712.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(264.323, 712.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-244.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(244.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-264.323, 692.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(264.323, 692.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-224.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(224.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(204.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-204.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(184.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(164.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-164.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-184.323, 732.609, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-164.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-184.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-204.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(164.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(184.323, 572.136, 10.f));

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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(204.323, 572.136, 10.f));

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
		ECS::GetComponent<Door>(entity).DoorLock(false, false, false, true);
		//Sets up components
		std::string Door = "YellowDoor.png";
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

		ECS::GetComponent<Door>(entity).DoorLock(false, false, false, true);
		//Sets up components
		std::string Door = "YellowDoor.png";
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
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//sets up components
		std::string fileName = "acidpool.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);


		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() - 30), float(tempSpr.GetHeight() - 30),
			vec2(0.f, 0.f),
			CollisionIDs::Acid(), CollisionIDs::Player(), true);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 652.4, 2.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Acid");
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
		anim3.AddFrame(vec2(28.f, 290.f), vec2(298.f, 41.f));
		anim3.AddFrame(vec2(371.f, 290.f), vec2(640.f, 41.f));
		anim3.AddFrame(vec2(711.f, 290.f), vec2(980.f, 41.f));
		anim3.AddFrame(vec2(1051.f, 290.f), vec2(1321.f, 41.f));
		anim3.AddFrame(vec2(1391.f, 290.f), vec2(1660.f, 41.f));


		//Makes it repeat
		anim.SetRepeating(true);
		anim2.SetRepeating(false);
		anim3.SetRepeating(false);
		//Sets the time between frames
		anim.SetSecPerFrame(0.1667f);
		anim2.SetSecPerFrame(0.1667f);
		anim3.SetSecPerFrame(0.1667f);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Demon, 22, 22, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 652.4, 10.f));
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
			| EntityIdentifier::PhysicsBit() | EntityIdentifier::HealthArmourBit() | EntityIdentifier::ImpBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Imp");
	}

	//level 5 starts
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 220, 64);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(450.3f, 651.6f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "hallway5");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 64, 185);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(592.1f, 712.8f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "hallway5");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 116, 57);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(682.1f, 774.9f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "hallway5");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 245, 245);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(862.4f, 868.4f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Floor5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 264, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(492.1, 610.5, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall5");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(460.1, 693.4f, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall5");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(640.1, 813.3, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 249, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(860.3, 736.7, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 157, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(798.5, 1000, 99.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);

		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "LongWall5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 115, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(682.4f, 736.8f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 121, 20);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(996.8f, 1000.f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall5");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(550.f, 753.3f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 147);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(634.1f, 673.3f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 169);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(730.f, 906.3f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 141);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(995.f, 920.3f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall5");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 141);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(995.f, 797.3f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall5");
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


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 58, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(728.4, 775.3, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor5");
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
		
		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth() + 50), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		ECS::GetComponent<Sprite>(entity).LoadSprite(Door, 60, 23, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(906.7f, 1000, 99.f));

		//Sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "RegularDoor5");
	}

	//level 6 starts
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 66.f, 181.f);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(908.2f, 1076.3f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Hallway6");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 211.f, 66.f);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(769.9f, 1134.f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Hallway6");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 66.f, 181.f);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.5f, 875.9f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Hallway6");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 211.f, 66.f);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(559.1f, 1134.1f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Hallway6");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 300.f, 229.f);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(303.9f, 1148.2f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Floor6");
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 66.f, 181.f);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.5f, 1056.9f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Floor6");
	} {
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 187.f, 66.f);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(60.7f, 1180.3f, 0.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Floor6");
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
	// level 8
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "surface.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 120, 108);


		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-814.2f, 651.f, 0.f));



		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "floor8");
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
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 108);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-884.f, 650.8f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfSideWall8");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-833.7f, 587.3f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall8");
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

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-833.7f, 714.8f, 10.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
			vec2(0.f, 0.f),
			CollisionIDs::Environment(), (0x0), false);


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "HalfWall8");
	}

	ECS::GetComponent<VerticalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
	ECS::GetComponent<HorizontalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
}
