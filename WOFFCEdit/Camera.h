
#include <d3d11.h>
#include <SimpleMath.h>
#include "InputCommands.h"
//Dedicated camera class
using namespace DirectX::SimpleMath; 
class Camera
{
public:
	Camera();
	~Camera(); 
	void Update(InputCommands input_);
	//Getsetters
	Vector3 getPos() { return v3camPos; }
	Matrix getViewMatrix() { return viewMatrix; }
	//Dedicated methods
	void Focus(Vector3 objectPos);
	void MouseControls(InputCommands& input_commands);
private:
	//functionality
	float fMovespeed;
	Vector2 prevMousePos;

	//camera vectors
	Vector3		v3camPos;
	Vector3		v3camRot;
	Vector3		v3camLookAt;
	Vector3		v3CamDirection;
	Vector3		v3camRight;
	Matrix viewMatrix; 
	float fcamRotRate; //rotation rate

};

