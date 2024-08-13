/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2010,2011,2012 Adrien Boussicault, Marc Zipstein
 *
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */

/** \~french 
 * \file MLV_keyboard.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les prototypes des fonctions permettant 
 *        d'utiliser le clavier.
 *
 */

#ifndef __MLV__MLV_KEYBOARD_H__
#define __MLV__MLV_KEYBOARD_H__

#ifndef MEMORY_DEBUG
#include <SDL/SDL.h>
#else
#include "memory_debug.h"
#endif

#include "MLV_device_with_buttons.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Énumère l'ensemble des codes des touches du clavier
 */
typedef enum {
	MLV_KEYBOARD_NONE = SDLK_UNKNOWN,
	MLV_KEYBOARD_UNKNOWN = SDLK_UNKNOWN,
	MLV_KEYBOARD_FIRST = SDLK_FIRST,
	MLV_KEYBOARD_BACKSPACE = SDLK_BACKSPACE, 
	MLV_KEYBOARD_TAB = SDLK_TAB, 
	MLV_KEYBOARD_CLEAR = SDLK_CLEAR, 
	MLV_KEYBOARD_RETURN = SDLK_RETURN, 
	MLV_KEYBOARD_PAUSE = SDLK_PAUSE, 
	MLV_KEYBOARD_ESCAPE = SDLK_ESCAPE, 
	MLV_KEYBOARD_SPACE = SDLK_SPACE, 
	MLV_KEYBOARD_EXCLAIM = SDLK_EXCLAIM, 
	MLV_KEYBOARD_QUOTEDBL = SDLK_QUOTEDBL, 
	MLV_KEYBOARD_HASH = SDLK_HASH, 
	MLV_KEYBOARD_DOLLAR = SDLK_DOLLAR, 
	MLV_KEYBOARD_AMPERSAND = SDLK_AMPERSAND, 
	MLV_KEYBOARD_QUOTE = SDLK_QUOTE, 
	MLV_KEYBOARD_LEFTPAREN = SDLK_LEFTPAREN, 
	MLV_KEYBOARD_RIGHTPAREN = SDLK_RIGHTPAREN, 
	MLV_KEYBOARD_ASTERISK = SDLK_ASTERISK, 
	MLV_KEYBOARD_PLUS = SDLK_PLUS, 
	MLV_KEYBOARD_COMMA = SDLK_COMMA, 
	MLV_KEYBOARD_MINUS = SDLK_MINUS, 
	MLV_KEYBOARD_PERIOD = SDLK_PERIOD, 
	MLV_KEYBOARD_SLASH = SDLK_SLASH, 
	MLV_KEYBOARD_0 = SDLK_0, 
	MLV_KEYBOARD_1 = SDLK_1, 
	MLV_KEYBOARD_2 = SDLK_2, 
	MLV_KEYBOARD_3 = SDLK_3, 
	MLV_KEYBOARD_4 = SDLK_4, 
	MLV_KEYBOARD_5 = SDLK_5, 
	MLV_KEYBOARD_6 = SDLK_6, 
	MLV_KEYBOARD_7 = SDLK_7, 
	MLV_KEYBOARD_8 = SDLK_8, 
	MLV_KEYBOARD_9 = SDLK_9, 
	MLV_KEYBOARD_COLON = SDLK_COLON, 
	MLV_KEYBOARD_SEMICOLON = SDLK_SEMICOLON, 
	MLV_KEYBOARD_LESS = SDLK_LESS, 
	MLV_KEYBOARD_EQUALS = SDLK_EQUALS, 
	MLV_KEYBOARD_GREATER = SDLK_GREATER, 
	MLV_KEYBOARD_QUESTION = SDLK_QUESTION, 
	MLV_KEYBOARD_AT = SDLK_AT, 

	MLV_KEYBOARD_LEFTBRACKET = SDLK_LEFTBRACKET, 
	MLV_KEYBOARD_BACKSLASH = SDLK_BACKSLASH, 
	MLV_KEYBOARD_RIGHTBRACKET = SDLK_RIGHTBRACKET, 
	MLV_KEYBOARD_CARET = SDLK_CARET, 
	MLV_KEYBOARD_UNDERSCORE = SDLK_UNDERSCORE, 
	MLV_KEYBOARD_BACKQUOTE = SDLK_BACKQUOTE, 
	MLV_KEYBOARD_a = SDLK_a, 
	MLV_KEYBOARD_b = SDLK_b, 
	MLV_KEYBOARD_c = SDLK_c, 
	MLV_KEYBOARD_d = SDLK_d, 
	MLV_KEYBOARD_e = SDLK_e, 
	MLV_KEYBOARD_f = SDLK_f, 
	MLV_KEYBOARD_g = SDLK_g, 
	MLV_KEYBOARD_h = SDLK_h, 
	MLV_KEYBOARD_i = SDLK_i, 
	MLV_KEYBOARD_j = SDLK_j, 
	MLV_KEYBOARD_k = SDLK_k, 
	MLV_KEYBOARD_l = SDLK_l, 
	MLV_KEYBOARD_m = SDLK_m, 
	MLV_KEYBOARD_n = SDLK_n, 
	MLV_KEYBOARD_o = SDLK_o, 
	MLV_KEYBOARD_p = SDLK_p, 
	MLV_KEYBOARD_q = SDLK_q, 
	MLV_KEYBOARD_r = SDLK_r, 
	MLV_KEYBOARD_s = SDLK_s, 
	MLV_KEYBOARD_t = SDLK_t, 
	MLV_KEYBOARD_u = SDLK_u, 
	MLV_KEYBOARD_v = SDLK_v, 
	MLV_KEYBOARD_w = SDLK_w, 
	MLV_KEYBOARD_x = SDLK_x, 
	MLV_KEYBOARD_y = SDLK_y, 
	MLV_KEYBOARD_z = SDLK_z, 
	MLV_KEYBOARD_DELETE = SDLK_DELETE, 

	MLV_KEYBOARD_WORLD_0 = SDLK_WORLD_0,
	MLV_KEYBOARD_WORLD_1 = SDLK_WORLD_1,
	MLV_KEYBOARD_WORLD_2 = SDLK_WORLD_2,
	MLV_KEYBOARD_WORLD_3 = SDLK_WORLD_3,
	MLV_KEYBOARD_WORLD_4 = SDLK_WORLD_4,
	MLV_KEYBOARD_WORLD_5 = SDLK_WORLD_5,
	MLV_KEYBOARD_WORLD_6 = SDLK_WORLD_6,
	MLV_KEYBOARD_WORLD_7 = SDLK_WORLD_7,
	MLV_KEYBOARD_WORLD_8 = SDLK_WORLD_8,
	MLV_KEYBOARD_WORLD_9 = SDLK_WORLD_9,
	MLV_KEYBOARD_WORLD_10 = SDLK_WORLD_10,
	MLV_KEYBOARD_WORLD_11 = SDLK_WORLD_11,
	MLV_KEYBOARD_WORLD_12 = SDLK_WORLD_12,
	MLV_KEYBOARD_WORLD_13 = SDLK_WORLD_13,
	MLV_KEYBOARD_WORLD_14 = SDLK_WORLD_14,
	MLV_KEYBOARD_WORLD_15 = SDLK_WORLD_15,
	MLV_KEYBOARD_WORLD_16 = SDLK_WORLD_16,
	MLV_KEYBOARD_WORLD_17 = SDLK_WORLD_17,
	MLV_KEYBOARD_WORLD_18 = SDLK_WORLD_18,
	MLV_KEYBOARD_WORLD_19 = SDLK_WORLD_19,
	MLV_KEYBOARD_WORLD_20 = SDLK_WORLD_20,
	MLV_KEYBOARD_WORLD_21 = SDLK_WORLD_21,
	MLV_KEYBOARD_WORLD_22 = SDLK_WORLD_22,
	MLV_KEYBOARD_WORLD_23 = SDLK_WORLD_23,
	MLV_KEYBOARD_WORLD_24 = SDLK_WORLD_24,
	MLV_KEYBOARD_WORLD_25 = SDLK_WORLD_25,
	MLV_KEYBOARD_WORLD_26 = SDLK_WORLD_26,
	MLV_KEYBOARD_WORLD_27 = SDLK_WORLD_27,
	MLV_KEYBOARD_WORLD_28 = SDLK_WORLD_28,
	MLV_KEYBOARD_WORLD_29 = SDLK_WORLD_29,
	MLV_KEYBOARD_WORLD_30 = SDLK_WORLD_30,
	MLV_KEYBOARD_WORLD_31 = SDLK_WORLD_31,
	MLV_KEYBOARD_WORLD_32 = SDLK_WORLD_32,
	MLV_KEYBOARD_WORLD_33 = SDLK_WORLD_33,
	MLV_KEYBOARD_WORLD_34 = SDLK_WORLD_34,
	MLV_KEYBOARD_WORLD_35 = SDLK_WORLD_35,
	MLV_KEYBOARD_WORLD_36 = SDLK_WORLD_36,
	MLV_KEYBOARD_WORLD_37 = SDLK_WORLD_37,
	MLV_KEYBOARD_WORLD_38 = SDLK_WORLD_38,
	MLV_KEYBOARD_WORLD_39 = SDLK_WORLD_39,
	MLV_KEYBOARD_WORLD_40 = SDLK_WORLD_40,
	MLV_KEYBOARD_WORLD_41 = SDLK_WORLD_41,
	MLV_KEYBOARD_WORLD_42 = SDLK_WORLD_42,
	MLV_KEYBOARD_WORLD_43 = SDLK_WORLD_43,
	MLV_KEYBOARD_WORLD_44 = SDLK_WORLD_44,
	MLV_KEYBOARD_WORLD_45 = SDLK_WORLD_45,
	MLV_KEYBOARD_WORLD_46 = SDLK_WORLD_46,
	MLV_KEYBOARD_WORLD_47 = SDLK_WORLD_47,
	MLV_KEYBOARD_WORLD_48 = SDLK_WORLD_48,
	MLV_KEYBOARD_WORLD_49 = SDLK_WORLD_49,
	MLV_KEYBOARD_WORLD_50 = SDLK_WORLD_50,
	MLV_KEYBOARD_WORLD_51 = SDLK_WORLD_51,
	MLV_KEYBOARD_WORLD_52 = SDLK_WORLD_52,
	MLV_KEYBOARD_WORLD_53 = SDLK_WORLD_53,
	MLV_KEYBOARD_WORLD_54 = SDLK_WORLD_54,
	MLV_KEYBOARD_WORLD_55 = SDLK_WORLD_55,
	MLV_KEYBOARD_WORLD_56 = SDLK_WORLD_56,
	MLV_KEYBOARD_WORLD_57 = SDLK_WORLD_57,
	MLV_KEYBOARD_WORLD_58 = SDLK_WORLD_58,
	MLV_KEYBOARD_WORLD_59 = SDLK_WORLD_59,
	MLV_KEYBOARD_WORLD_60 = SDLK_WORLD_60,
	MLV_KEYBOARD_WORLD_61 = SDLK_WORLD_61,
	MLV_KEYBOARD_WORLD_62 = SDLK_WORLD_62,
	MLV_KEYBOARD_WORLD_63 = SDLK_WORLD_63,
	MLV_KEYBOARD_WORLD_64 = SDLK_WORLD_64,
	MLV_KEYBOARD_WORLD_65 = SDLK_WORLD_65,
	MLV_KEYBOARD_WORLD_66 = SDLK_WORLD_66,
	MLV_KEYBOARD_WORLD_67 = SDLK_WORLD_67,
	MLV_KEYBOARD_WORLD_68 = SDLK_WORLD_68,
	MLV_KEYBOARD_WORLD_69 = SDLK_WORLD_69,
	MLV_KEYBOARD_WORLD_70 = SDLK_WORLD_70,
	MLV_KEYBOARD_WORLD_71 = SDLK_WORLD_71,
	MLV_KEYBOARD_WORLD_72 = SDLK_WORLD_72,
	MLV_KEYBOARD_WORLD_73 = SDLK_WORLD_73,
	MLV_KEYBOARD_WORLD_74 = SDLK_WORLD_74,
	MLV_KEYBOARD_WORLD_75 = SDLK_WORLD_75,
	MLV_KEYBOARD_WORLD_76 = SDLK_WORLD_76,
	MLV_KEYBOARD_WORLD_77 = SDLK_WORLD_77,
	MLV_KEYBOARD_WORLD_78 = SDLK_WORLD_78,
	MLV_KEYBOARD_WORLD_79 = SDLK_WORLD_79,
	MLV_KEYBOARD_WORLD_80 = SDLK_WORLD_80,
	MLV_KEYBOARD_WORLD_81 = SDLK_WORLD_81,
	MLV_KEYBOARD_WORLD_82 = SDLK_WORLD_82,
	MLV_KEYBOARD_WORLD_83 = SDLK_WORLD_83,
	MLV_KEYBOARD_WORLD_84 = SDLK_WORLD_84,
	MLV_KEYBOARD_WORLD_85 = SDLK_WORLD_85,
	MLV_KEYBOARD_WORLD_86 = SDLK_WORLD_86,
	MLV_KEYBOARD_WORLD_87 = SDLK_WORLD_87,
	MLV_KEYBOARD_WORLD_88 = SDLK_WORLD_88,
	MLV_KEYBOARD_WORLD_89 = SDLK_WORLD_89,
	MLV_KEYBOARD_WORLD_90 = SDLK_WORLD_90,
	MLV_KEYBOARD_WORLD_91 = SDLK_WORLD_91,
	MLV_KEYBOARD_WORLD_92 = SDLK_WORLD_92,
	MLV_KEYBOARD_WORLD_93 = SDLK_WORLD_93,
	MLV_KEYBOARD_WORLD_94 = SDLK_WORLD_94,
	MLV_KEYBOARD_WORLD_95 = SDLK_WORLD_95,

	MLV_KEYBOARD_KP0 = SDLK_KP0, 
	MLV_KEYBOARD_KP1 = SDLK_KP1, 
	MLV_KEYBOARD_KP2 = SDLK_KP2, 
	MLV_KEYBOARD_KP3 = SDLK_KP3, 
	MLV_KEYBOARD_KP4 = SDLK_KP4, 
	MLV_KEYBOARD_KP5 = SDLK_KP5, 
	MLV_KEYBOARD_KP6 = SDLK_KP6, 
	MLV_KEYBOARD_KP7 = SDLK_KP7, 
	MLV_KEYBOARD_KP8 = SDLK_KP8, 
	MLV_KEYBOARD_KP9 = SDLK_KP9, 
	MLV_KEYBOARD_KP_PERIOD = SDLK_KP_PERIOD, 
	MLV_KEYBOARD_KP_DIVIDE = SDLK_KP_DIVIDE, 
	MLV_KEYBOARD_KP_MULTIPLY = SDLK_KP_MULTIPLY, 
	MLV_KEYBOARD_KP_MINUS = SDLK_KP_MINUS, 
	MLV_KEYBOARD_KP_PLUS = SDLK_KP_PLUS, 
	MLV_KEYBOARD_KP_ENTER = SDLK_KP_ENTER, 
	MLV_KEYBOARD_KP_EQUALS = SDLK_KP_EQUALS, 

	MLV_KEYBOARD_UP = SDLK_UP, 
	MLV_KEYBOARD_DOWN = SDLK_DOWN, 
	MLV_KEYBOARD_RIGHT = SDLK_RIGHT, 
	MLV_KEYBOARD_LEFT = SDLK_LEFT, 
	MLV_KEYBOARD_INSERT = SDLK_INSERT, 
	MLV_KEYBOARD_HOME = SDLK_HOME, 
	MLV_KEYBOARD_END = SDLK_END, 
	MLV_KEYBOARD_PAGEUP = SDLK_PAGEUP, 
	MLV_KEYBOARD_PAGEDOWN = SDLK_PAGEDOWN, 

	MLV_KEYBOARD_F1 = SDLK_F1, 
	MLV_KEYBOARD_F2 = SDLK_F2, 
	MLV_KEYBOARD_F3 = SDLK_F3, 
	MLV_KEYBOARD_F4 = SDLK_F4, 
	MLV_KEYBOARD_F5 = SDLK_F5, 
	MLV_KEYBOARD_F6 = SDLK_F6, 
	MLV_KEYBOARD_F7 = SDLK_F7, 
	MLV_KEYBOARD_F8 = SDLK_F8, 
	MLV_KEYBOARD_F9 = SDLK_F9, 
	MLV_KEYBOARD_F10 = SDLK_F10, 
	MLV_KEYBOARD_F11 = SDLK_F11, 
	MLV_KEYBOARD_F12 = SDLK_F12, 
	MLV_KEYBOARD_F13 = SDLK_F13, 
	MLV_KEYBOARD_F14 = SDLK_F14, 
	MLV_KEYBOARD_F15 = SDLK_F15, 

	MLV_KEYBOARD_NUMLOCK = SDLK_NUMLOCK, 
	MLV_KEYBOARD_CAPSLOCK = SDLK_CAPSLOCK, 
	MLV_KEYBOARD_SCROLLOCK = SDLK_SCROLLOCK, 
	MLV_KEYBOARD_RSHIFT = SDLK_RSHIFT, 
	MLV_KEYBOARD_LSHIFT = SDLK_LSHIFT, 
	MLV_KEYBOARD_RCTRL = SDLK_RCTRL, 
	MLV_KEYBOARD_LCTRL = SDLK_LCTRL, 
	MLV_KEYBOARD_RALT = SDLK_RALT, 
	MLV_KEYBOARD_LALT = SDLK_LALT, 
	MLV_KEYBOARD_RMETA = SDLK_RMETA, 
	MLV_KEYBOARD_LMETA = SDLK_LMETA, 
	MLV_KEYBOARD_LSUPER = SDLK_LSUPER, 
	MLV_KEYBOARD_RSUPER = SDLK_RSUPER, 
	MLV_KEYBOARD_MODE = SDLK_MODE, 
	MLV_KEYBOARD_COMPOSE = SDLK_COMPOSE, 

	MLV_KEYBOARD_HELP = SDLK_HELP, 
	MLV_KEYBOARD_PRINT = SDLK_PRINT, 
	MLV_KEYBOARD_SYSREQ = SDLK_SYSREQ, 
	MLV_KEYBOARD_BREAK = SDLK_BREAK, 
	MLV_KEYBOARD_MENU = SDLK_MENU, 
	MLV_KEYBOARD_POWER = SDLK_POWER, 
	MLV_KEYBOARD_EURO = SDLK_EURO, 
	MLV_KEYBOARD_UNDO = SDLK_UNDO, 

	MLV_KEYBOARD_LAST = SDLK_LAST 
} MLV_Keyboard_button;

/** \~french 
 * \brief Énumère l'ensemble des codes associées aux différents modes du clavier
 */
typedef enum {
	MLV_KEYBOARD_KMOD_NONE = KMOD_NONE, 
	MLV_KEYBOARD_KMOD_LSHIFT = KMOD_LSHIFT, 
	MLV_KEYBOARD_KMOD_RSHIFT = KMOD_RSHIFT, 
	MLV_KEYBOARD_KMOD_LCTRL = KMOD_LCTRL, 
	MLV_KEYBOARD_KMOD_RCTRL = KMOD_RCTRL, 
	MLV_KEYBOARD_KMOD_LALT = KMOD_LALT, 
	MLV_KEYBOARD_KMOD_RALT = KMOD_RALT, 
	MLV_KEYBOARD_KMOD_LMETA = KMOD_LMETA, 
	MLV_KEYBOARD_KMOD_RMETA = KMOD_RMETA, 
	MLV_KEYBOARD_KMOD_NUM = KMOD_NUM, 
	MLV_KEYBOARD_KMOD_CAPS = KMOD_CAPS, 
	MLV_KEYBOARD_KMOD_MODE = KMOD_MODE, 
	MLV_KEYBOARD_KMOD_RESERVED = KMOD_RESERVED 
} MLV_Keyboard_modifier;

/** \~french 
 * \brief Suspend l'exécution jusqu'à ce que l'utilisateur appuie sur une touche
 *        du  clavier.
 * 
 * Lorsque l'utilisateur appuie sur une touche, la fonction remplit le contenu 
 * des trois paramètres sym, mod et unicode correspondant respectivement au 
 * code de la touche, au mode dans lequel se trouve le clavier 
 * (majuscule etc ...) et au caractère unicode obtenu en combinant le mode du 
 * clavier et le code de la touche appuyée.
 *
 * La fonction accepte des valeurs nulles pour les pointeurs sym, mod et 
 * unicode.
 * Dans ce cas la fonction ignore les champs en questions.
 *
 * \bug Voir les bugs de la fonction MLV_get_event().
 *
 * \param sym        Le code de la touche.
 * \param mod        Le mode dans lequel se trouve le clavier.
 * \param unicode    Le caractère codé en unicode de la lettre obtenue en combinant
 *                   le code et le mode précédent.
 */
void MLV_wait_keyboard( MLV_Keyboard_button* sym, MLV_Keyboard_modifier* mod, int* unicode );

/** \~french 
 * \brief Suspend l'exécution jusqu'à ce que l'utilisateur appuie sur une touche
 *        du  clavier ou jusq'à ce q'un nombre de secondes passées en paramètres
 *        soient écoulées.
 * 
 * Pour plus d'informations sur le fonctionnement de cette fonction, veuillez 
 * vous reporter à la documentation de MLV_wait_keyboard().
 *
 * La fonction accepte des valeurs nulles pour les pointeurs sym, mod et 
 * unicode.
 * Dans ce cas la fonction ignore les champs en questions.
 *
 * \bug Voir les bugs de la fonction MLV_get_event().
 *
 * \param sym        Le code de la touche. 
 * \param mod        Le mode dans lequel se trouve le clavier.
 * \param unicode    Le caractère codé en unicode de la lettre obtenue en combinant
 *                   le code et le mode précédent.
 * \param seconds    Le nombre de secondes à attendre.
 * \return Renvoie 1 si l'utilisateur a utilisé le calvier, 0 si le temps s'est
 *         écoulé.
 */
int MLV_wait_keyboard_or_seconds(
	MLV_Keyboard_button* sym, MLV_Keyboard_modifier* mod, int* unicode, int seconds
);


/** \~french
 * \brief Renvoie le code de la touche clavier correspondant au type clavier
 *        passé en paramètre.
 *
 * \param key_string La chaine de caractères codant le type de la touche.
 *
 * \return Le code de la touche clavier.
 */
MLV_Keyboard_button MLV_convert_string_to_keyboard_button( const char* key_string );

/** \~french
 * \brief Renvoie la chaîne de caractères correspondant au code de la touche
 *        passé en paramètre.
 *
 * \param key_code Le code de la touche.
 *
 * \return La chaine de caractères codant le code de la touche.
 */
const char* MLV_convert_keyboard_button_to_string( MLV_Keyboard_button key_code );

/** \~french
 * \brief Renvoie la chaîne de caractères correspondant au mode du clavier
 *        passé en paramètre.
 *
 * \param keymod_code Le code du mode.
 *
 * \return La chaine de caractères codant le mode du clavier.
 */
char* MLV_convert_keyboard_mod_to_string( MLV_Keyboard_modifier keymod_code );


/** \~french
 *
 * \brief Renvoie l'état (préssé ou relaché) d'une touche donnée d'un clavier.
 *
 * \param keyboard_code Le code de la touche dont il faut renvoyer l'état.
 * \return L'état de la touche. 
 */
MLV_Button_state MLV_get_keyboard_state( MLV_Keyboard_button keyboard_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison shift du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison shift a été appuyée.
 */
int MLV_shift_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison shift gauche du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison shift gauche a été appuyée.
 */
int MLV_left_shift_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison shift droit du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison shift droit a été appuyée.
 */
int MLV_right_shift_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison ctrl gauche du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison ctrl gauche a été appuyée.
 */
int MLV_left_ctrl_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison ctrl droit du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison ctrl droit a été appuyée.
 */
int MLV_right_ctrl_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison ctrl du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison ctrl a été appuyée.
 */
int MLV_ctrl_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison alt gauche du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison alt gauche a été appuyée.
 */
int MLV_left_alt_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison alt droit du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison alt droit a été appuyée.
 */
int MLV_right_alt_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison alt du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison alt a été appuyée.
 */
int MLV_alt_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison meta gauche du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison meta gauche a été appuyée.
 */
int MLV_left_meta_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison meta droit du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison meta droit a été appuyée.
 */
int MLV_right_meta_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison meta du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison meta a été appuyée.
 */
int MLV_meta_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison num du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison num a été appuyée.
 */
int MLV_num_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison cpas du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison caps a été appuyée.
 */
int MLV_caps_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison mode du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison mode a été appuyée.
 */
int MLV_mode_key_was_pressed( MLV_Keyboard_modifier modifier_code );


#ifdef __cplusplus
}
#endif

#endif
