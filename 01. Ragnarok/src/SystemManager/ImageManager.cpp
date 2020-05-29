#include "stdafx.h"
#include "ImageManager.h"
DEFINITION_SINGLE(ImageManager)

ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
}

HRESULT ImageManager::init()
{
	return S_OK;
}

void ImageManager::release()
{
	deleteAll();
}

Image * ImageManager::addImage(std::string strKey, int width, int height)
{
	Image* img = findImage(strKey);
	if (img) 
		return img;

	img = new Image;

	if (FAILED(img->init(width, height))) {
		SAFE_DELETE(img);
		return NULL;
	}

	//이미지를 이미지 목록에 추가
	_mImagevector.insert(make_pair(strKey, img));

	return img;
}

Image * ImageManager::addImage(std::string strKey, const char * fileName, int width, int height, bool isTrans, COLORREF transCollor)
{
	Image* img = findImage(strKey);
	if (img)
		return img;

	img = new Image;

	if (FAILED(img->init(fileName, width, height, isTrans, transCollor))) {
		SAFE_DELETE(img);
		return NULL;
	}

	//이미지를 이미지 목록에 추가
	_mImagevector.insert(make_pair(strKey, img));

	return img;
}

Image * ImageManager::addImage(std::string strKey, const char * fileName, int x, int y, int width, int height, bool isTrans, COLORREF transCollor)
{
	Image* img = findImage(strKey);
	if (img)
		return img;

	img = new Image;

	if (FAILED(img->init(fileName, x, y, width, height, 1, 1, isTrans, RGB(255, 0, 255)))) {
		SAFE_DELETE(img);
		return NULL;
	}

	//이미지를 이미지 목록에 추가
	_mImagevector.insert(make_pair(strKey, img));

	return img;
}

Image * ImageManager::addFrameImage(std::string strKey, const char * fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transCollor)
{
	Image* img = findImage(strKey);
	if (img)
		return img;

	img = new Image;

	if (FAILED(img->init(fileName,width, height, frameX, frameY, isTrans, transCollor))) {
		SAFE_DELETE(img);
		return NULL;
	}

	//이미지를 이미지 목록에 추가
	_mImagevector.insert(make_pair(strKey, img));

	return img;
}

Image * ImageManager::addFrameImage(std::string strKey, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transCollor)
{
	Image* img = findImage(strKey);
	if (img)
		return img;

	img = new Image;

	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, isTrans, transCollor))) {
		SAFE_DELETE(img);
		return NULL;
	}

	//이미지를 이미지 목록에 추가
	_mImagevector.insert(make_pair(strKey, img));

	return img;
}


Image * ImageManager::findImage(std::string strkey)
{
	mapImageIter key = _mImagevector.find(strkey);
	if (key != _mImagevector.end())
		return key->second;
	return nullptr;
}

bool ImageManager::deleteImage(std::string strKey)
{
	mapImageIter key = _mImagevector.find(strKey);
	if (key != _mImagevector.end()) {
		key->second->release();
		SAFE_DELETE(key->second);
		_mImagevector.erase(key);
		return true;
	}
	return false;
}

bool ImageManager::deleteAll()
{
	mapImageIter it = _mImagevector.begin();
	for (it; it != _mImagevector.end();) {
		if (it->second != NULL) {
			it->second->release();
			SAFE_DELETE(it->second);
			it = _mImagevector.erase(it);
		}
		else ++it;
	}
	_mImagevector.clear();
	return true;
}

void ImageManager::render(std::string strKey, HDC hdc)
{
	Image* img = findImage(strKey);
	if (img)
		img->render(hdc);
}

void ImageManager::render(std::string strKey, HDC hdc, int destX, int destY)
{
	Image* img = findImage(strKey);
	if (img)
		img->render(hdc, destX, destY);
}

void ImageManager::render(std::string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	Image* img = findImage(strKey);
	if (img)
		img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void ImageManager::frameRender(std::string strKey, HDC hdc, int destX, int destY)
{
	Image* img = findImage(strKey);
	if (img)
		img->frameRender(hdc, destX, destY);
}

void ImageManager::frameRender(std::string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	Image* img = findImage(strKey);
	if (img) 
		img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void ImageManager::loopRender(std::string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	Image* img = findImage(strKey);
	if (img) 
		img->loopRender(hdc, drawArea, offsetX, offsetY);
}

void ImageManager::loopAlphaRender(std::string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
	Image* img = findImage(strKey);
	if (img)
		img->loopAlphaRender(hdc, drawArea, offsetX, offsetY, alpha);
}
