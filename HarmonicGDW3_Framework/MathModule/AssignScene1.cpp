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
		ECS::AttachComponent<Transform>(entity);
		vec4 temp = ECS::GetComponent<Camera>(entity).GetOrthoSize();
		ECS::GetComponent<Camera>(entity).SetWindowSize(vec2(float(windowWidth), float(windowHeight)));
		ECS::GetComponent<Camera>(entity).Orthographic(aspectRatio, temp.x, temp.y, temp.z, temp.w, -100.f, 100.f);
		ECS::GetComponent<VerticalScroll>(entity).SetCam(&ECS::GetComponent<Camera>(entity));
		ECS::GetComponent<VerticalScroll>(entity).SetOffset(15.f);
		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::VertScrollCameraBit() || EntityIdentifier::CameraBit();
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

		//sets up components
		std::string fileName = "megaSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(fileName);
		//adds first animation
		animController.AddAnimation(Animation());
		//sets active animation
		animController.SetActiveAnim(0);
		//gets first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(0.f, 32.f), vec2(31.f, 1.f));
		anim.AddFrame(vec2(35.f, 32.f), vec2(67.f, 1.f));
		anim.AddFrame(vec2(69.f, 32.f), vec2(101.f, 1.f));
		anim.AddFrame(vec2(35.f, 32.f), vec2(67.f, 1.f));
		//makes it repeat
		anim.SetRepeating(true);
		//sets time between frames
		anim.SetSecPerFrame(0.1667f);
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 64, 64, true, &animController);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(50.f, -60.f, 10.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "MegaMan");
	}
	{
		auto attacks = File::LoadJSON("kenAnim.json");
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);

		//sets up components
		std::string fileName = "kenOver.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(fileName);
		//adds first animation
		animController.AddAnimation(attacks["KenIdle"]);
		animController.AddAnimation(attacks["KenHado"]);
		animController.SetActiveAnim(1);
		//gets first animation
		auto& anim = animController.GetAnimation(1);
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 50, 75, true, &animController);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-50.f, -60.f, 10.f));
		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Ken");
		ECS::SetIsMainPlayer(entity, true);
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "redBird.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, 35.f, 30.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Angry Red Bird");
	}

	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "marioWorld.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 111, 120);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(-40.f, 30.f, 40.f));


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Small Mario");
	}
	{
		auto attacks = File::LoadJSON("kenAnim.json");
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);

		//sets up components
		std::string fileName = "contraTopSheet.png";
		auto& animController = ECS::GetComponent<AnimationController>(entity);
		animController.InitUVs(fileName);
		animController.AddAnimation(Animation());
		animController.SetActiveAnim(0);
		//adds first animation
		auto& anim = animController.GetAnimation(0);
		anim.AddFrame(vec2(45.f, 10.f), vec2(72.f, 40.f));
		anim.AddFrame(vec2(73.f, 13.f), vec2(99.f, 40.f));
		anim.AddFrame(vec2(100.f, 13.f), vec2(127.f, 40.f));
		anim.AddFrame(vec2(73.f, 13.f), vec2(99.f, 40.f));
		anim.SetRepeating(true);
		//sets time between frames
		anim.SetSecPerFrame(0.1667f);
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 30, 30, true, &animController);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, -60.f, 10.f));
		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::AnimationBit();
		ECS::SetUpIdentifier(entity, bitHolder, "contra");
		ECS::SetIsMainPlayer(entity, true);
	}
	{
		//creates entity
		auto entity = ECS::CreateEntity();

		//add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);

		//sets up components
		std::string fileName = "TlozBGR1.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 200, 200);

		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, -44.f, -1));
		


		//sets up the identifier
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Dark Background");
	}
	ECS::GetComponent<VerticalScroll>(EntityIdentifier::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()));
}
