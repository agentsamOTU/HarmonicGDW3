#include "PhysicsBody.h"

unsigned int CollisionIDs::m_playerID		 = 0x00000001;
unsigned int CollisionIDs::m_environmentID   = 0x00000010;
unsigned int CollisionIDs::m_enemyID         = 0x00000100;
unsigned int CollisionIDs::m_bulletID        = 0x00001000;
unsigned int CollisionIDs::m_pickupID        = 0x00010000;
unsigned int CollisionIDs::m_acidID          = 0x00100000;

unsigned int CollisionIDs::Player()
{
	return m_playerID;
}

unsigned int CollisionIDs::Environment()
{
	return m_environmentID;
}

unsigned int CollisionIDs::Enemy()
{
	return m_enemyID;
}

unsigned int CollisionIDs::Bullet()
{
	return m_bulletID;
}

unsigned int CollisionIDs::Pickup()
{
	return m_pickupID;
}

unsigned int CollisionIDs::Acid()
{
	return m_acidID;
}

vec3 PhysicsBody::m_gravityAcceleration = vec3(0.f, -35.f, 0.f);
bool PhysicsBody::m_drawBodies = false;


void PhysicsBody::SetForce(vec3 force)
{
	m_appliedForce = force;
}

void PhysicsBody::SetAcceleration(vec3 accel)
{
	m_acceleration = accel;
}

void PhysicsBody::SetMaxVelo(float velo)
{
	m_maxVelo = velo;
}

void PhysicsBody::SetVelocity(vec3 velo)
{
	m_velocity = velo;
}

void PhysicsBody::SetFriction(float fric)
{
	m_friction = fric;
}

void PhysicsBody::SetGravityAcceleration(vec3 grav)
{
	m_gravityAcceleration = grav;
}

void PhysicsBody::SetGravity(bool grav)
{
	m_applyGravity = grav;
}

void PhysicsBody::SetMass(float mass)
{
	m_mass = mass;
}

void PhysicsBody::SetBodyType(BodyType type)
{
	m_bodyType = type;
}

void PhysicsBody::SetCenterOffset(vec2 cent)
{
	m_centerOffset = cent;
}

void PhysicsBody::SetBottomLeft(vec2 BL)
{
	m_bottomLeft = BL;
}

void PhysicsBody::SetBottomRight(vec2 BR)
{
	m_bottomRight = BR;
}

void PhysicsBody::SetTopLeft(vec2 TL)
{
	m_topLeft = TL;
}

void PhysicsBody::SetTopRight(vec2 TR)
{
	m_topRight = TR;
}

void PhysicsBody::SetWidth(float width)
{
	m_width = width;
}

void PhysicsBody::SetHeight(float height)
{
	m_height = height;
}

void PhysicsBody::SetRadius(float radius)
{
	m_radius = radius;
}

void PhysicsBody::SetBodyID(unsigned int bodyID)
{
	m_bodyID = bodyID;
}

void PhysicsBody::SetCollideID(unsigned int collideID)
{
	m_collideID = collideID;
}

void PhysicsBody::SetDynamic(bool isDynamic)
{
	m_dynamic = isDynamic;
}

void PhysicsBody::SetDraw(bool drawBodies)
{
	m_drawBodies = drawBodies;
}


PhysicsBody::PhysicsBody(vec2 botLeft, vec2 topRight, vec2 centerOffset, unsigned int objectSpecifier, unsigned int collidesWith, bool isDynamic)
{
	m_bodyType = BodyType::BOX;

	m_bottomLeft = botLeft;
	m_topLeft = vec2(botLeft.x, topRight.y);
	m_topRight = topRight;
	m_bottomRight = vec2(topRight.x, botLeft.y);

	m_width = m_bottomRight.x - m_bottomLeft.x;
	m_height = m_topLeft.y - m_bottomLeft.y;

	m_centerOffset = centerOffset;

	m_bodyID = objectSpecifier;

	m_collideID = collidesWith;
	
	m_dynamic = isDynamic;

	InitBody();
}

PhysicsBody::PhysicsBody(float width, float height, vec2 centerOffset, unsigned int objectSpecifier, unsigned int collidesWith, bool isDynamic)
{
	m_bodyType = BodyType::BOX;

	m_width = width;
	m_height = height;

	m_centerOffset = centerOffset;
	m_bottomLeft = vec2(centerOffset.x - (width/2.f), centerOffset.y - (height/2.f));
	m_bottomRight = vec2(centerOffset.x + (width / 2.f), centerOffset.y - (height / 2.f));
	m_topLeft = vec2(centerOffset.x - (width / 2.f), centerOffset.y + (height / 2.f));
	m_topRight = vec2(centerOffset.x + (width / 2.f), centerOffset.y + (height / 2.f));

	m_collideID = collidesWith;
	m_bodyID = objectSpecifier;

	m_dynamic = isDynamic;

	InitBody();
}

PhysicsBody::PhysicsBody(float radius, vec2 centerOffset, unsigned int objectSpecifier, unsigned int collidesWith, bool isDynamic)
{
	m_bodyType = BodyType::CIRCLE;

	m_radius = radius;
	m_centerOffset = centerOffset;

	m_collideID = collidesWith;
	m_bodyID = objectSpecifier;

	m_dynamic = isDynamic;

	InitBody();
}

void PhysicsBody::Update(Transform* trans, float dt)
{
	//grabs the transform
	vec3 transPosition = trans->GetPosition();

	//if the body is moving
	if (m_velocity.GetMagnitude() > 0.f)
	{
		if (m_applyGravity)
		{
			m_frictionalForce = vec3(-m_velocity.x, 0.f, 0.f) * m_friction;
		}
		else
		{
			m_frictionalForce = -m_velocity * m_friction;
		}
	}

	//sum the forces applied
	m_netForce = m_appliedForce + m_frictionalForce;

	//calculates acceleration
	m_acceleration = (m_netForce / m_mass);

	//if the gravity is enabled
	if (m_applyGravity)
	{
		//if the object is dynamic
		if (m_dynamic)
		{
			m_acceleration = m_acceleration + (m_gravityAcceleration * m_mass);
		}
	}

	m_frictionalForce = vec3(0.f, 0.f, 0.f);
	m_appliedForce = vec3(0.f, 0.f, 0.f);

	//holds old velo
	float tempX = m_velocity.x;
	float tempY = m_velocity.y;
	//calcs velo
	m_velocity = m_velocity + (m_acceleration * dt);

	//caps velo
	if (abs(m_velocity.x) > abs(m_maxVelo))
	{
		m_velocity.x = tempX;
	}
	if (abs(m_velocity.y) > abs(m_maxVelo))
	{
		m_velocity.y = tempY;
	}

	//calcs new pos
	transPosition = transPosition + (m_velocity * dt);

	//puts it into transform
	trans->SetPosition(transPosition);
	
}

void PhysicsBody::InitBody()
{
	m_vao = VertexManager::CreateVAO();
	glBindVertexArray(m_vao);

	//enable slot 0
	glEnableVertexAttribArray(0);    //vertices

	//vbo positions
	m_vboPos = VertexManager::GetPlaneVertVBO();
	//pushes away warning
#pragma warning(push)
#pragma warning(disable : 4312)
	//bind pos biffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vboPos);
	//sets attrib pointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void*>(0));
#pragma warning(pop)

	//unbinds buffers
	glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
	glBindVertexArray(GL_NONE);
}

void PhysicsBody::DrawBody()
{
	//bind vao
	glBindVertexArray(m_vao);
	//draw the points
	glDrawArrays(GL_TRIANGLES, 0, 6);
	//unbind vao
	glBindVertexArray(GL_NONE);
}

void PhysicsBody::ApplyForce(vec3 force)
{
	m_appliedForce = m_appliedForce + force;
}

vec3 PhysicsBody::GetForce() const
{
	return vec3(m_appliedForce);
}

vec3 PhysicsBody::GetAcceleration() const
{
	return vec3(m_acceleration);
}

float PhysicsBody::GetMaxVelo() const
{
	return m_maxVelo;
}

vec3 PhysicsBody::GetVelocity() const
{
	return vec3(m_velocity);
}

float PhysicsBody::GetFriction() const
{
	return m_friction;
}

vec3 PhysicsBody::GetGravityAcceleration()
{
	return vec3(m_gravityAcceleration);
}

bool PhysicsBody::GetGravity() const
{
	return m_applyGravity;
}

float PhysicsBody::GetMass()
{
	return m_mass;
}

BodyType PhysicsBody::GetBodyType() const
{
	return BodyType(m_bodyType);
}

vec2 PhysicsBody::GetCenterOffset() const
{
	return vec2(m_centerOffset);
}

vec2 PhysicsBody::GetBottomLeft() const
{
	return vec2(m_bottomLeft);
}

vec2 PhysicsBody::GetBottomRight() const
{
	return vec2(m_bottomRight);
}

vec2 PhysicsBody::GetTopLeft() const
{
	return vec2(m_topLeft);
}

vec2 PhysicsBody::GetTopRight() const
{
	return vec2(m_topRight);
}

float PhysicsBody::GetWidth() const
{
	return m_width;
}

float PhysicsBody::GetHeight() const
{
	return m_height;
}

float PhysicsBody::GetRadius() const
{
	return m_radius;
}

unsigned int PhysicsBody::GetBodyID() const
{
	return m_bodyID;
}

unsigned int PhysicsBody::GetCollideID() const
{
	return m_collideID;
}

bool PhysicsBody::GetDynamic() const
{
	return m_dynamic;
}

bool PhysicsBody::GetDraw()
{
	return m_drawBodies;
}
