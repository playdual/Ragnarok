#pragma once
class CameraManager
{
public:
	void init();
	void release();
	void update();

	void rectInCamera(UTIL::IRECT& outRect, const UTIL::IRECT& realRect, bool& isOutput);
	void setCameraFocus(int* _targetX, int* _targetY, int _cameraOffsetX, int _cameraOffsetY);

public:
	int m_cameraOffX = 0;
	int m_cameraOffY = 0;
private:
	int m_cameraX;
	int m_cameraY;
	int* m_FocucedCameraX;
	int* m_FocucedCameraY;
	int m_cameraOffsetX_FromTarget;
	int m_cameraOffsetY_FromTarget;

	int m_outputExtra = 100;
	
private:
	DECLARE_SINGLE(CameraManager)
};




#define CAMERAMANAGER CameraManager::GetInst()
