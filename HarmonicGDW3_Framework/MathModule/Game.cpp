#include "Game.h"

#include <random>


Game::~Game()
{
	//If window isn't equal to nullptr
	if (m_window != nullptr)
	{
		//Delete window
		delete m_window;
		//set window to nullptr
		m_window = nullptr;
	}

	//Goes through the scenes and deletes them
	for (unsigned i = 0; i < m_scenes.size(); i++)
	{
		if (m_scenes[i] != nullptr)
		{
			delete m_scenes[i];
			m_scenes[i] = nullptr;
		}
	}
}

void Game::InitGame()
{
	//Scene names and clear colors
	m_name = "DOOM";
	m_clearColor = vec4(0.57f, 0, 0, 1.f);

	//Initializes the backend
	BackEnd::InitBackEnd(m_name);

	//Grabs the initialized window
	m_window = BackEnd::GetWindow();
	BackEnd::GetWindow()->SetFullscreen(true);
	//creates a new HelloWorld scene
	m_scenes.push_back(new HelloWorld("Horizontal scrolling scene"));
	m_scenes.push_back(new MyScene("My Scene"));
	m_scenes.push_back(new HelloWorld("Second Loaded Scene"));
	m_scenes.push_back(new AssignScene1("Scene for assignment 1"));
	//sets active scene reference to our HelloWOrld scene
	m_activeScene = m_scenes[3];

	m_activeScene->InitScene(float(BackEnd::GetWindowWidth()), float(BackEnd::GetWindowHeight()));

	//sets m_register to point to the register in the active scene
	PhysicsSystem::Init();

	m_register = m_activeScene->GetScene();
}

bool Game::Run()
{
	mciSendString("play assets/sound/d_e1m1.mp3 repeat", NULL, 0, NULL);
	//While window is still open
	while (m_window->isOpen())
	{
		//Clear window with clearColor
		m_window->Clear(m_clearColor);
		//Updates the game
		Update();
		//Draws the game
		BackEnd::Draw(m_register);

		//Draws ImGUI
		if (m_guiActive)
			GUI();
		
		//Flips the windows
		m_window->Flip();
		//Polls events and then checks them
		BackEnd::PollEvents(m_register, &m_close, &m_motion, &m_click, &m_wheel);
		CheckEvents();
		Routines();
		//does the window have keyboard focus?
		if (Input::m_windowFocus)
		{
			//Accept all input
			AcceptInput();
		}
		//hacky but works
		ECS::GetComponent<Camera>(EntityIdentifier::MainCamera()).SetPosition(ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer()).GetPosition());
	}

	return true;
}

void Game::Update()
{
	//Update timer
	Timer::Update();
	//Update the backend
	BackEnd::Update(m_register);

	PhysicsSystem::Update(m_register);
}

void Game::GUI()
{
	UI::Start(BackEnd::GetWindowWidth(), BackEnd::GetWindowHeight());

	ImGui::Text("Place your different tabs below.");

	if (ImGui::BeginTabBar(""))
	{
		BackEnd::GUI(m_register, m_activeScene);

		ImGui::EndTabBar();
	}

	UI::End();
}

void Game::CheckEvents()
{
	if (m_close)
		m_window->Close();

	if (m_motion)
		MouseMotion(BackEnd::GetMotionEvent());

	if (m_click)
		MouseClick(BackEnd::GetClickEvent());

	if (m_wheel)
		MouseWheel(BackEnd::GetWheelEvent());
}

void Game::Routines()
{
	auto& weaps = ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer());
	weaps.AddAcidTime(Timer::deltaTime);
	weaps.AddGunTime(Timer::deltaTime);
	auto& playHealth = ECS::GetComponent<HealthArmour>(EntityIdentifier::MainPlayer());
	auto& playLoc = ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
	auto& playPhys = ECS::GetComponent<PhysicsBody>(EntityIdentifier::MainPlayer());
	
	ECS::GetComponent<Transform>(1).SetPosition(playLoc.GetPosition()+vec3(-75.f,-71.f,0.f));
	ECS::GetComponent<Transform>(2).SetPosition(playLoc.GetPosition() + vec3(-68.f, -71.f, 0.f));
	ECS::GetComponent<Transform>(3).SetPosition(playLoc.GetPosition() + vec3(-75.f, -81.f, 0.f));
	ECS::GetComponent<Transform>(4).SetPosition(playLoc.GetPosition() + vec3(-68.f, -81.f, 0.f));
	ECS::GetComponent<Transform>(5).SetPosition(playLoc.GetPosition() + vec3(-75.f, -91.f, 0.f));
	ECS::GetComponent<Transform>(6).SetPosition(playLoc.GetPosition() + vec3(-68.f, -91.f, 0.f));
	ECS::GetComponent<Transform>(7).SetPosition(playLoc.GetPosition()+vec3(-90.f,-80.f,0.f));
	ECS::GetComponent<Transform>(8).SetPosition(playLoc.GetPosition() + vec3(-83.f, -84.f, 0.f));
	if (playHealth.GetHealth() >= 10)
	{
		std::string temp = std::to_string(playHealth.GetHealth());
		ECS::GetComponent<AnimationController>(1).SetActiveAnim(temp[0]-'0');
		ECS::GetComponent<AnimationController>(2).SetActiveAnim(temp[1] - '0');
	}
	else
	{
		std::string temp = std::to_string(playHealth.GetHealth());
		ECS::GetComponent<AnimationController>(3).SetActiveAnim(0);
		ECS::GetComponent<AnimationController>(4).SetActiveAnim(temp[0] - '0');
	}
	if (playHealth.GetArmour() >= 10)
	{
		std::string temp = std::to_string(playHealth.GetArmour());
		ECS::GetComponent<AnimationController>(3).SetActiveAnim(temp[0] - '0');
		ECS::GetComponent<AnimationController>(4).SetActiveAnim(temp[1] - '0');
	}
	else
	{
		std::string temp = std::to_string(playHealth.GetArmour());
		ECS::GetComponent<AnimationController>(5).SetActiveAnim(0);
		ECS::GetComponent<AnimationController>(6).SetActiveAnim(temp[0] - '0');
	}
	if (weaps.GetAmmo() >= 10)
	{
		std::string temp = std::to_string(weaps.GetAmmo());
		ECS::GetComponent<AnimationController>(5).SetActiveAnim(temp[0] - '0');
		ECS::GetComponent<AnimationController>(6).SetActiveAnim(temp[1] - '0');
	}
	else
	{
		std::string temp = std::to_string(weaps.GetAmmo());
		ECS::GetComponent<AnimationController>(3).SetActiveAnim(0);
		ECS::GetComponent<AnimationController>(4).SetActiveAnim(temp[0] - '0');
	}
	if (weaps.GetWeapon() == 1)
	{
		auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
		if (weaps.GetGunTime() > 0.25f)
		{
			animController.SetActiveAnim(2);
			ECS::GetComponent<Sprite>(EntityIdentifier::MainPlayer()).SetHeight(24);
			ECS::GetComponent<Sprite>(EntityIdentifier::MainPlayer()).SetWidth(24);
			if (playPhys.GetVelocity().GetMagnitude() < 4.f)
			{
				animController.SetActiveAnim(3);
			}
		}
	}
	if (weaps.GetWeapon() == 0)
	{
		auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
		if (weaps.GetGunTime() > 0.25f)
		{
			animController.SetActiveAnim(0);
			ECS::GetComponent<Sprite>(EntityIdentifier::MainPlayer()).SetHeight(24);
			ECS::GetComponent<Sprite>(EntityIdentifier::MainPlayer()).SetWidth(24);
			if (playPhys.GetVelocity().GetMagnitude() < 4.f)
			{
				animController.SetActiveAnim(1);
			}
		}
	}
	if (playHealth.GetDamaged())
	{
		playHealth.TakeDamage(10);
		if (playHealth.GetHealth() <= 0)
		{
			printf("GAMEOVER");
			exit(0);
		}
	}
	auto view = m_register->view<Zombie>();
	for (auto entity : view)
	{
		auto& enemLoc = ECS::GetComponent<Transform>(entity);
		auto& enemPhs = ECS::GetComponent<PhysicsBody>(entity);
		auto& enemAnim = ECS::GetComponent<AnimationController>(entity);
		auto& health = ECS::GetComponent<HealthArmour>(entity);
		auto& zomb = ECS::GetComponent<Zombie>(entity);
		if (health.GetDamaged())
		{
			health.AddHealth(-10);
			health.SetDamaged(false);
			if (health.GetHealth() <= 0)
			{
				mciSendString("play assets/sound/dsdmpain.wav", NULL, 0, NULL);
				zomb.SetActive(false);
				enemPhs.SetBodyID(0x0);
				enemPhs.SetCollideID(0x0);
				enemPhs.SetVelocity(vec3(0.f, 0.f, 0.f));
				ECS::GetComponent<Sprite>(entity).SetHeight(36.f);
				enemAnim.SetActiveAnim(2);

			}
		}
		if (zomb.GetActive())
		{
			if (zomb.GetShoot())
			{
				zomb.AddTime(Timer::deltaTime);
				if (zomb.GetTime() > 0.1f&&!zomb.GetShotDone())
				{
					zomb.Shoot(&enemLoc);
					
					enemAnim.SetActiveAnim(1);
					ECS::GetComponent<Sprite>(entity).SetHeight(28.f);
					

				}
				if (zomb.GetTime() > 1.f)
				{
					zomb.ResetShoot();
					enemAnim.GetAnimation(1).Reset();
					ECS::GetComponent<Sprite>(entity).SetHeight(24.f);
					enemAnim.SetActiveAnim(0);
				}
			}
			else
			{
				vec2 delta = vec2(playLoc.GetPositionX() - enemLoc.GetPositionX(), playLoc.GetPositionY() - enemLoc.GetPositionY());
				vec2 tempDirec = vec2(delta.Normalize()) * 30.f;
				if (delta.GetMagnitude() < 60)
				{
					zomb.SetShoot(true);
					zomb.SetDirection(tempDirec.x, tempDirec.y);
				}
				else if (delta.GetMagnitude() < 150)
				{
					enemPhs.SetVelocity(vec3(tempDirec.x, tempDirec.y, 0.f));
				}
				enemLoc.SetRotationAngleZ(atan2(delta.y, delta.x) + PI / 2);

			}
		}
	}
	auto view2 = m_register->view<Imp>();
	for (auto entity : view2)
	{
		auto& enemLoc = ECS::GetComponent<Transform>(entity);
		auto& enemPhs = ECS::GetComponent<PhysicsBody>(entity);
		auto& enemAnim = ECS::GetComponent<AnimationController>(entity);
		auto& health = ECS::GetComponent<HealthArmour>(entity);
		auto& Im = ECS::GetComponent<Imp>(entity);
		if (health.GetDamaged())
		{
			health.AddHealth(-10);
			health.SetDamaged(false);
			if (health.GetHealth() <= 0)
			{
				mciSendString("play assets/sound/dspopain.wav", NULL, 0, NULL);
				Im.SetActive(false);
				enemPhs.SetBodyID(0x0);
				enemPhs.SetCollideID(0x0);
				enemPhs.SetVelocity(vec3(0.f, 0.f, 0.f));
				ECS::GetComponent<Sprite>(entity).SetHeight(36.f);
				enemAnim.SetActiveAnim(2);

			}
		}
		if (Im.GetActive())
		{
			if (Im.GetShoot())
			{
				Im.AddTime(Timer::deltaTime);
				if (Im.GetTime() > 0.1f && !Im.GetShotDone())
				{
					Im.Shoot(&enemLoc);

					enemAnim.SetActiveAnim(1);
					ECS::GetComponent<Sprite>(entity).SetHeight(22.f);


				}
				if (Im.GetTime() > 0.5f)
				{
					Im.ResetShoot();
					enemAnim.GetAnimation(1).Reset();
					ECS::GetComponent<Sprite>(entity).SetHeight(22.f);
					enemAnim.SetActiveAnim(0);
				}
			}
			else
			{
				vec2 delta = vec2(playLoc.GetPositionX() - enemLoc.GetPositionX(), playLoc.GetPositionY() - enemLoc.GetPositionY());
				vec2 tempDirec = vec2(delta.Normalize()) * 30.f;
				if (delta.GetMagnitude() < 90)
				{
					Im.SetShoot(true);
					Im.SetDirection(tempDirec.x, tempDirec.y);
				}
				else if (delta.GetMagnitude() < 150)
				{
					enemPhs.SetVelocity(vec3(tempDirec.x, tempDirec.y, 0.f));
				}
				enemLoc.SetRotationAngleZ(atan2(delta.y, delta.x) + PI / 2);

			}
		}
	}
}

void Game::AcceptInput()
{
	m_moving = false;
	XInputManager::Update();
	//Just calls all the other input functions 
	GamepadInput();

	KeyboardHold();
	KeyboardDown();
	KeyboardUp();

	//Resets the key flags
	//Must be done once per frame for input to work
	Input::ResetKeys();
}

void Game::GamepadInput()
{
	XInputController* tempCon;
	//gamepad button stroked(pressed)
	for (int i = 0; i < 3; i++)
	{
		if (XInputManager::ControllerConnected(i))
		{
			tempCon = XInputManager::GetController(i);
			tempCon->SetStickDeadZone(0.1f);

			//if the controller is connected we run the different input types
			GamepadStroke(tempCon);
			GamepadUp(tempCon);
			GamepadDown(tempCon);
			GamepadStick(tempCon);
			GamepadTrigger(tempCon);
		}
	}
}

void Game::GamepadStroke(XInputController* con)
{
	//gamepad button press
	if (con->IsButtonStroked(Buttons::A))
	{
		auto view = m_register->view<Door>();
		for (auto entity : view)
		{
			auto& doorLoc = ECS::GetComponent<Transform>(entity);
			auto& doorPhs = ECS::GetComponent<PhysicsBody>(entity);
			auto& doorAnim = ECS::GetComponent<AnimationController>(entity);
			auto& playLoc = ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
			vec2 delta = vec2(playLoc.GetPositionX() - doorLoc.GetPositionX(), playLoc.GetPositionY() - doorLoc.GetPositionY());
			if (delta.GetMagnitude() < 25 && delta.GetMagnitude() > 10)
			{
				if (ECS::GetComponent<Door>(entity).LockCheck())
				{
					ECS::GetComponent<Door>(entity).DoorToggle(&doorPhs, &doorAnim);
				}
			}
		}
	}
	if (con->IsButtonStroked(Buttons::LB))
	{
		ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).ChangeWeapon();
	}
}

void Game::GamepadUp(XInputController* con)
{
	//gamepad button up
	if (con->IsButtonReleased(Buttons::RB))
	{
		//printf("RB released\n");
	}
}

void Game::GamepadDown(XInputController* con)
{
	//gamepad button down
	if (con->IsButtonPressed(Buttons::THUMB_LEFT))
	{
		printf("Left Thumbsticked Clicked In\n");
	}
	if (con->IsButtonPressed(Buttons::DPAD_UP))
	{
		printf("Up press registered\n");
	}
	if (con->IsButtonPressed(Buttons::DPAD_LEFT))
	{
		printf("Left press registered\n");
	}
	if (con->IsButtonPressed(Buttons::DPAD_RIGHT))
	{
		printf("Right press registered\n");
	}
	if (con->IsButtonPressed(Buttons::DPAD_DOWN))
	{
		printf("Down press registered\n");
	}
}

void Game::GamepadStick(XInputController* con)
{
	auto& look = ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
	float angle;
	vec2 friction;
	//Gamepad stick stuffs
	Stick sticks[2];
	con->GetSticks(sticks);
	auto& playPhs = ECS::GetComponent<PhysicsBody>(EntityIdentifier::MainPlayer());

	vec2 totalForce = vec2(0.f, 0.f);
	if (sticks[0].y > 0.3f)
	{
		playPhs.ApplyForce(vec3(0.f, 50.f, 0.f));
	}
	if (sticks[0].x < -0.3f)
	{
		playPhs.ApplyForce(vec3(-50.f, 0.f, 0.f));
	}
	if (sticks[0].x > 0.3f)
	{
		playPhs.ApplyForce(vec3(50.f, 0.f, 0.f));
	}
	if (sticks[0].y < -0.3f)
	{
		playPhs.ApplyForce(vec3(0.f, -50.f, 0.f));
	}
	if (sticks[1].x > 0.3f && sticks[1].y > 0.3f)
	{
		angle = PI - PI/4;
		look.SetRotationAngleZ(angle);
	}
	else if (sticks[1].x < -0.3f && sticks[1].y > 0.3f)
	{
		angle = PI + PI/4;
		look.SetRotationAngleZ(angle);
	}
	else if(sticks[1].y < -0.3f&& sticks[1].x > 0.3f)
	{
		angle = PI/4;
		look.SetRotationAngleZ(angle);
	}
	else if(sticks[1].y < -0.3f&& sticks[1].x < -0.3f)
	{
		angle = 2*PI -PI/4;
		look.SetRotationAngleZ(angle);
	}
	else if (sticks[1].y > 0.3f)
	{
		//printf("Up Pointing\n");
		angle = PI;
		look.SetRotationAngleZ(angle);
	}
	else if (sticks[1].x < -0.3f)
	{
		//printf("Left Pointing\n");
		angle = PI/2 + PI;
		look.SetRotationAngleZ(angle);
	}
	else if (sticks[1].x > 0.3f)
	{
		//printf("Right Pointing\n");
		angle = PI/2;
		look.SetRotationAngleZ(angle);
	}
	else if (sticks[1].y < -0.3f)
	{
		//printf("Down Pointing\n");
		angle = 0;
		look.SetRotationAngleZ(angle);
	}
}

void Game::GamepadTrigger(XInputController* con)
{
	Triggers triggers;
	con->GetTriggers(triggers);

	if (triggers.RT > 0.5f && triggers.RT > 0.8f)
	{
		auto& shot = ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer());
		auto& trans = ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
		if (shot.GetAmmo() > 0)
		{
			shot.Shoot(&trans);
			printf("Player Ammo:%i\n", shot.GetAmmo());
		}
	}
	
}

void Game::KeyboardHold()
{
	//Keyboard button held
	auto& playPhs = ECS::GetComponent<PhysicsBody>(EntityIdentifier::MainPlayer());


	if (Input::GetKey(Key::W))
	{
		playPhs.ApplyForce(vec3(0.f, 100.f, 0.f));
	}
	if (Input::GetKey(Key::A))
	{
		playPhs.ApplyForce(vec3(-100.f, 0.f, 0.f));
	}
	if (Input::GetKey(Key::S))
	{
		playPhs.ApplyForce(vec3(0.f, -100.f, 0.f));
	}
	if (Input::GetKey(Key::D))
	{
		
		playPhs.ApplyForce(vec3(100.f, 0.f, 0.f));	
	}
}

void Game::KeyboardDown()
{
	//Keyboard button down
	if (Input::GetKeyDown(Key::F4))
	{
		printf("F4 key pressed\n");
	}
	if (Input::GetKeyDown(Key::Enter))
	{
		printf("Enter has been pressed");

	}
	if (Input::GetKeyDown(Key::Space))
	{
		auto view = m_register->view<Door>();
		for (auto entity : view)
		{
			auto& doorLoc = ECS::GetComponent<Transform>(entity);
			auto& doorPhs = ECS::GetComponent<PhysicsBody>(entity);
			auto& doorAnim = ECS::GetComponent<AnimationController>(entity);
			auto& playLoc = ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
			vec2 delta = vec2(playLoc.GetPositionX() - doorLoc.GetPositionX(), playLoc.GetPositionY() - doorLoc.GetPositionY());
			if (delta.GetMagnitude() < 25&&delta.GetMagnitude()>10)
			{
				if (ECS::GetComponent<Door>(entity).LockCheck())
				{
					ECS::GetComponent<Door>(entity).DoorToggle(&doorPhs, &doorAnim);
				}
			}
		}
	}
	if (Input::GetKeyDown(Key::Q))
	{
		ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).ChangeWeapon();
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).GetWeapon() == 1)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(3);
		}
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).GetWeapon() == 0)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(1);
		}
	}
}

void Game::KeyboardUp()
{
	if (Input::GetKeyUp(Key::F1))
	{
		if (!UI::m_isInit)
		{
			UI::InitImGUI();
		}
		m_guiActive = !m_guiActive;
	}/*
	if (Input::GetKeyUp(Key::W))
	{
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).curWeap == 1)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(3);
		}
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).curWeap == 0)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(1);
		}
	}
	if (Input::GetKeyUp(Key::A))
	{
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).curWeap == 1)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(3);
		}
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).curWeap == 0)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(1);
		}
	}
	if (Input::GetKeyUp(Key::S))
	{
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).curWeap == 1)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(3);
		}
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).curWeap == 0)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(1);
		}
	}
	if (Input::GetKeyUp(Key::D))
	{	
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).curWeap == 1)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(3);
		}
		if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).curWeap == 0)
		{
			auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
			animController.SetActiveAnim(1);
		}
	}	*/
}

void Game::MouseMotion(SDL_MouseMotionEvent evnt)
{
	//printf("Mouse moved (%f,%f)\n", float(evnt.x) - 350, float(evnt.y) - 350 );
	auto& look = ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
	float angle;
	angle = atan2((float(evnt.y) - BackEnd::GetWindowHeight()/2), (float(evnt.x) - BackEnd::GetWindowWidth() / 2));//fix if want mouse
	look.SetRotationAngleZ(-angle - 3 * PI / 2);
	
	if (m_guiActive)
	{
		ImGui::GetIO().MousePos = ImVec2(float(evnt.x), float(evnt.y));
		

		if (!ImGui::GetIO().WantCaptureMouse)
		{
			
		}
	}

	//Resets the enabled flag
	m_motion = false;
}

void Game::MouseClick(SDL_MouseButtonEvent evnt)
{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		auto& shot=ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer());
		auto& trans= ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
		if (shot.GetAmmo() > 0)
		{
			shot.Shoot(&trans);
			if (shot.GetGunTime() == 0)
			{
				if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).GetWeapon() == 1)
				{
					ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer()).GetAnimation(4).Reset();
					auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
					animController.SetActiveAnim(4);
				}
				if (ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer()).GetWeapon() == 0)
				{
					ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer()).GetAnimation(5).Reset();
					auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
					animController.SetActiveAnim(5);
				}
				ECS::GetComponent<Sprite>(EntityIdentifier::MainPlayer()).SetHeight(28);
				ECS::GetComponent<Sprite>(EntityIdentifier::MainPlayer()).SetWidth(24);
			}
		}
	}
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
	}
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
	{
	}
	if (m_guiActive)
	{
		ImGui::GetIO().MousePos = ImVec2(float(evnt.x), float(evnt.y));
		ImGui::GetIO().MouseDown[0] = (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT));
		ImGui::GetIO().MouseDown[1] = (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT));
		ImGui::GetIO().MouseDown[2] = (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE));
	}

	//Resets the enabled flag
	m_click = false;
}

void Game::MouseWheel(SDL_MouseWheelEvent evnt)
{
	printf("mouse scroll %f\n", float(evnt.y));
	if (m_guiActive)
	{
		ImGui::GetIO().MouseWheel = float(evnt.y);
	}
	//Resets the enabled flag
	m_wheel = false;
}
