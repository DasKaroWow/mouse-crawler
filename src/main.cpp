#include <cstdint>
#include <iostream>
#include <windows.h>

auto user_pressed = []() {
    for (int vk = 0x08; vk <= 0xFE; ++vk) {
        SHORT s = GetAsyncKeyState(vk);
        if (s & 0x8000) return true;
    }
    return false;
};

int main() {
	const int32_t left = GetSystemMetrics(SM_XVIRTUALSCREEN);
	const int32_t top = GetSystemMetrics(SM_YVIRTUALSCREEN);
	const int32_t right = left + GetSystemMetrics(SM_CXVIRTUALSCREEN);
	const int32_t bottom = top + GetSystemMetrics(SM_CYVIRTUALSCREEN);

	int32_t speed_x = 1, speed_y = 1;
	POINT position;
	GetCursorPos(&position);

	while (true) {
		// std::cout << position.x << " " << position.y << std::endl;

		position.x += speed_x;
		position.y += speed_y;

		if (position.x <= left) {
			position.x = left;
			speed_x = -speed_x;
		}
		if (position.x >= right - 1) {
			position.x = right - 1;
			speed_x = -speed_x;
		}
		if (position.y <= top) {
			position.y = top;
			speed_y = -speed_y;
		}
		if (position.y >= bottom - 1) {
			position.y = bottom - 1;
			speed_y = -speed_y;
		}

		SetCursorPos(position.x, position.y);

		if (user_pressed()) break;
		Sleep(5);
	}
}
