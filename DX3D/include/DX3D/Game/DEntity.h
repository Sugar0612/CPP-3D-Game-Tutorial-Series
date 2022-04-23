/*MIT License

C++ 3D Game Tutorial Series (https://github.com/PardCode/CPP-3D-Game-Tutorial-Series)

Copyright (c) 2019-2022, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#pragma once

#include <DX3D/Math/DRect.h>
#include <DX3D/Math/DMat4.h>
#include <DX3D/Math/DVec3.h>
#include <DX3D/Window/DWindow.h>
#include <vector>

class DGame;
class DEntity
{
public:
	DEntity();
	virtual ~DEntity();

public:
	size_t getId();
	void getWorldMatrix(DMat4& world);
	void setPosition(const DVec3& position);
	void setRotation(const DVec3& rotation);
	void setScale(const DVec3& scale);

	DVec3 getPosition();
	DVec3 getScale();

	virtual void onCreate() {}
	virtual void onUpdate(f32 deltaTime) {}
	virtual void release();
protected:
	void processWorldMatrix();
protected:
	DMat4 m_world;

	DVec3 m_position;
	DVec3 m_rotation;
	DVec3 m_scale = DVec3(1,1,1);

	size_t m_id = 0;

	DGame* m_game = nullptr;

	friend class DGame;
};
