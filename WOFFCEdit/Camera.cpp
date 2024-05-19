#include "Camera.h"
#define PI 3.1416

Camera::Camera()
{
	//functional
	fMovespeed = 0.30;
	fcamRotRate = 3.0;

	//camera
	v3camPos = DirectX::XMFLOAT3(0.0f, 3.7f, -3.5f);
	v3camRot = DirectX::XMFLOAT3(0, 0, 0);
	v3camLookAt = DirectX::XMFLOAT3(0, 0, 0);
	v3CamDirection = DirectX::XMFLOAT3(0, 0, 0);
	v3camRight = DirectX::XMFLOAT3(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update(InputCommands input_)
{
	DirectX::SimpleMath::Vector3 planarMotionVector = v3CamDirection;
	planarMotionVector.y = 0.0;

	if (input_.rotRight)
	{
		v3camRot.y -= fcamRotRate;
	}
	if (input_.rotLeft)
	{
		v3camRot.y += fcamRotRate;
	}

	//create look direction from Euler angles in m_camOrientation
	v3CamDirection.x = sin((v3camRot.y) * PI / 180);
	v3CamDirection.z = cos((v3camRot.y) * PI / 180);
	v3CamDirection.Normalize();

	//create right vector from look Direction
	v3CamDirection.Cross(DirectX::SimpleMath::Vector3::UnitY, v3camRight);

	//process input and update stuff
	if (input_.forward)
	{
		v3camPos += v3CamDirection * fMovespeed;
	}
	if (input_.back)
	{
		v3camPos -= v3CamDirection * fMovespeed;
	}
	if (input_.right)
	{
		v3camPos += v3camRight * fMovespeed;
	}
	if (input_.left)
	{
		v3camPos -= v3camRight * fMovespeed;
	}
	//Need to do up and down

	//update lookat point
	v3camLookAt = v3camPos + v3CamDirection;

	//apply camera vectors
	viewMatrix = DirectX::SimpleMath::Matrix::CreateLookAt(v3camPos, v3camLookAt, DirectX::SimpleMath::Vector3::UnitY);

}

void Camera::Focus(Vector3 objectPos)
{
	//Move camera to focus on object
	v3camPos.x = objectPos.x; //to center
	v3camPos.y = objectPos.y + 1; //y is 
	v3camPos.z = objectPos.z - 2;

	//Change cameras orientation to look at object
	//Coord differences
	Vector3 d = Vector3(objectPos.x - v3camPos.x,
		objectPos.y - v3camPos.y,
		objectPos.z - v3camPos.z);

	//Yaw 
	v3camRot.y = atan2(d.x, d.z) * (180.0f / PI);

	//Pitch 
	float distance = sqrt(d.x * d.x + d.z * d.z);
	v3camRot.x = -atan2(d.y, distance) * (180.0f / PI);
}
