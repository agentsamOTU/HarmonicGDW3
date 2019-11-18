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
	m_name = "Hello World";
	m_clearColor = vec4(0.15f, 0.33f, 0.58f, 1.f);

	//Initializes the backend
	BackEnd::InitBackEnd(m_name);

	//Grabs the initialized window
	m_window = BackEnd::GetWindow();

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
	auto& enemLoc = ECS::GetComponent<Transform>(3);
	auto& enemPhs = ECS::GetComponent<PhysicsBody>(3);
	auto& playLoc = ECS::GetComponent<Transform>(EntityIdentifier::MainPlayer());
	vec2 delta =vec2(playLoc.GetPositionX() - enemLoc.GetPositionX(), playLoc.GetPositionY() - enemLoc.GetPositionY());
	m_velocityEn1 = vec2(delta.Normalize())*10.f;
	if (delta.GetMagnitude() < 60)
	{
		printf("He would shoot now\n");
	}
	else if (delta.GetMagnitude() < 150)
	{
		enemPhs.SetVelocity(vec3(m_velocityEn1.x, m_velocityEn1.y, 0.f));
	}
	enemLoc.SetRotationAngleZ(atan2(delta.y, delta.x)+PI/2);
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
		printf("A stroked\n");
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
	vec3 position = m_register->get<Transform>(EntityIdentifier::MainPlayer()).GetPosition();

	vec2 totalForce = vec2(0.f, 0.f);
	if (sticks[0].y > 0.3f)
	{
		if (m_velocity.y >= 0)
		{
			totalForce.y += 50.f;
		}
		else
		{
			totalForce.y += 150.f;
		}
		m_moving = true;
	}
	if (sticks[0].x < -0.3f)
	{
		if (m_velocity.x <= 0)
		{
			totalForce.x += -50.f;
		}
		else
		{
			totalForce.x += -150.f;
		}
		m_moving = true;
	}
	if (sticks[0].x > 0.3f)
	{
		if (m_velocity.x >= 0)
		{
			totalForce.x += 50.f;
		}
		else
		{
			totalForce.x += 150.f;
		}
		m_moving = true;
	}
	if (sticks[0].y < -0.3f)
	{
		if (m_velocity.y <= 0)
		{
			totalForce.y += -50.f;
		}
		else
		{
			totalForce.y += -150.f;
		}
		m_moving = true;
	}
	
	vec2 acceleration = totalForce / m_mass;
	//updates velocity
	if (m_velocity.x < -121.f)
	{
		m_velocity.x = -120.8f;
	}
	else if (m_velocity.x > 121.f)
	{
		m_velocity.x = 120.8f;
	}
	else
	{
		m_velocity.x = m_velocity.x + (acceleration.x * Timer::deltaTime);
	}
	if (m_velocity.y < -121.f)
	{
		m_velocity.y = -120.8f;
	}
	else if (m_velocity.y > 121.f)
	{
		m_velocity.y = 120.8f;
	}
	else
	{
		m_velocity.y = m_velocity.y + (acceleration.y * Timer::deltaTime);
	}
	//updates position
	position = position + (vec3(m_velocity.x, m_velocity.y, 0.f) * Timer::deltaTime)
		+ (vec3(acceleration.x, acceleration.y, 0.f) * 0.5f * (Timer::deltaTime * Timer::deltaTime));
	//sets position
	m_register->get<Transform>(EntityIdentifier::MainPlayer()).SetPosition(position);

	
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

	if (triggers.RT > 0.5f && triggers.RT < 0.8f)
	{
		printf("Half press\n");
	}
	if (triggers.RT > 0.8f)
	{
		printf("Full press\n");
	}
}

void Game::KeyboardHold()
{
	//Keyboard button held
	auto& playPhs = ECS::GetComponent<PhysicsBody>(EntityIdentifier::MainPlayer());


	if (Input::GetKey(Key::W))
	{
		playPhs.ApplyForce(vec3(0.f, 50.f, 0.f));
	}
	if (Input::GetKey(Key::A))
	{
		playPhs.ApplyForce(vec3(-50.f, 0.f, 0.f));
	}
	if (Input::GetKey(Key::S))
	{
		playPhs.ApplyForce(vec3(0.f, -50.f, 0.f));
	}
	if (Input::GetKey(Key::D))
	{
		playPhs.ApplyForce(vec3(50.f, 0.f,0.f));
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
	}

	if (Input::GetKeyUp(Key::K))
	{
		//switches between ken's two animations
		auto& animController = ECS::GetComponent<AnimationController>(EntityIdentifier::MainPlayer());
		if (animController.GetActiveAnim() == 0)
		{
			animController.SetActiveAnim(1);
		}
		else
		{
			animController.SetActiveAnim(0);
		}
	}
	if (Input::GetKeyUp(Key::P))
	{
		PhysicsBody::SetDraw(!PhysicsBody::GetDraw());
	}
	
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
		printf("Left mouse clicked at (%f,%f)\n", float(evnt.x), float(evnt.y));
	}
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		printf("Right mouse clicked at (%f,%f)\n", float(evnt.x), float(evnt.y));
	}
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
	{
		printf("Middle mouse clicked at (%f,%f)\n", float(evnt.x), float(evnt.y));
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
