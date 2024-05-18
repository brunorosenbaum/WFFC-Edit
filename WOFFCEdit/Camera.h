
#include <d3d11.h>
#include <SimpleMath.h>
#include "InputCommands.h"
//Dedicated camera class

class Camera
{
public:
	Camera();
	~Camera(); 
	void Update(InputCommands input_);
	DirectX::SimpleMath::Vector3 getPos() { return v3camPos; }
	DirectX::SimpleMath::Matrix getViewMatrix() { return viewMatrix; }

private:
	//functionality
	float fMovespeed;

	//camera vectors
	DirectX::SimpleMath::Vector3		v3camPos;
	DirectX::SimpleMath::Vector3		v3camRot;
	DirectX::SimpleMath::Vector3		v3camLookAt;
	DirectX::SimpleMath::Vector3		v3CamDirection;
	DirectX::SimpleMath::Vector3		v3camRight;
	DirectX::SimpleMath::Matrix viewMatrix; 
	float fcamRotRate; //rotation rate

};

