/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-timothee.de-boynes
** File description:
** event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

enum Input {
	NO_INPUT = 0,
	ENTER = 257,
	BACKSPACE = 259,
	SPACE = 32,
	ESCAPE = 256,
	UP_ARROW = 265,
	DOWN_ARROW = 264,
	LEFT_ARROW = 263,
	RIGHT_ARROW = 262,
	FACE_UP = 1,
	FACE_RIGHT = 2,
	FACE_DOWN = 3, 
	FACE_LEFT = 4,
	FACE_A = 7,
	A_KEY = 81,
	B_KEY = 66,
	C_KEY = 67,
	D_KEY = 68,
	E_KEY = 69,
	F_KEY = 70,
	G_KEY = 71,
	H_KEY = 72,
	I_KEY = 73,
	J_KEY = 74,
	K_KEY = 75,
	L_KEY = 76,
	M_KEY = 59,
	N_KEY = 78,
	O_KEY = 79,
	P_KEY = 80,
	Q_KEY = 65,
	R_KEY = 82,
	S_KEY = 83,
	T_KEY = 84,
	U_KEY = 85,
	V_KEY = 86,
	W_KEY = 90,
	X_KEY = 88,
	Y_KEY = 89,
	Z_KEY = 87,
	Num_0 = 48,
	Num_1 = 49,
	Num_2 = 50,
	Num_3 = 51,
	Num_4 = 52,
	Num_5 = 53,
	Num_6 = 54,
	Num_7 = 55,
	Num_8 = 56,
	Num_9 = 57,
	F1 = 290,
	F2 = 291,
	F3 = 292,
	F4 = 293,
	F5 = 294,
	F6 = 295,
	F7 = 296,
	F8 = 297,
	F9 = 298,
	F10 = 299,
	F11 = 300,
	F12 = 301,
	PAGE_UP = 266,
	PAGE_DOWN = 267,
	BOT_INPUT,
	TIME_TICK,
};

enum class Action {
	NEUTRAL,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT,
	PUT_BOMB,
	PAUSE,
	EXIT
};

#endif /* !EVENT_HPP_ */
