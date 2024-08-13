/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2013-2014 Adrien Boussicault, Marc Zipstein
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
 * \file MLV_text_va.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit différents prototypes des fonctions permmettant
 *        d'afficher du texte et des boîtes de dialogues.
 */

#ifndef __MLV__MLV_TEXT_VA_H__
#define __MLV__MLV_TEXT_VA_H__

#include "MLV_color.h"
#include "MLV_image.h"
#include "MLV_text.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Imprime un texte donné à une position et une couleur données.
 *
 * Cette fonction est équivalente à la fonction MLV_draw_text() à l'exception
 * qu'elle est apellée avec un paramètre de type va_list à la place d'une 
 * nombre variable d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_text() 
 *
 * \param x Coordonnée en X du coin Nord-Ouest du texte
 * \param y Coordonnée en Y du coin Nord-Ouest du texte
 * \param text texte à afficher
 * \param color couleur du tracé
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_text_va(
	int x, int y, const char *text, MLV_Color color, va_list pile
);


/** \~french 
 * \brief Écrit du texte sur l'écran en utilisant une couleur et une fonte de 
 *        caractères données en paramètres.
 *
 * Cette fonction est équivalente à la fonction MLV_draw_text_wih_font() à 
 * l'exception qu'elle est apellée avec un paramètre de type va_list à la 
 * place d'une nombre variable d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_text_with_font() 
 * 
 * \param x La coordonnée en X du coin Nord-Ouest du texte.
 * \param y La coordonnée en Y du coin Nord-Ouest du texte.
 * \param text Le texte à afficher.
 * \param color La couleur du tracé.
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_text_with_font_va(
	int x, int y, const char *text, const MLV_Font* font, MLV_Color color, 
	va_list pile
);

/** \~french 
 * \brief Écrit du texte sur une image en utilisant une couleur et une fonte de
 *        caractères données en paramètres.
 * 
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_text_with_font_on_image() à l'exception qu'elle est apellée 
 * avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_text_with_font_on_image() 
 * 
 * \param x La coordonnée en X du coin Nord-Ouest du texte.
 * \param y La coordonnée en Y du coin Nord-Ouest du texte.
 * \param text Le texte à afficher.
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 * \param color La couleur du tracé.
 * \param image L'image sur laquel le texte doit être ecrit.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_text_with_font_on_image_va(
	int x, int y, const char *text, const MLV_Font* font, MLV_Color color, 
	MLV_Image* image, va_list pile
);

/** \~french 
 * \brief Cette fonction calcule la taille du texte qui sera affiché sur 
 *        l'écran à l'aide de la fonction MLV_draw_text().
 * 
 * Cette fonction est équivalente à la fonction 
 * MLV_get_size_of_text() à l'exception qu'elle est apellée 
 * avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_get_size_of_text() 
 *
 * \param text Le texte qui doit être affiché.
 * \param width La largeur du texte.
 * \param height La hauteur du texte.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_get_size_of_text_va(
	const char *text, int *width, int *height, va_list pile
);

/** \~french 
 * \brief Cette fonction calcule la taille du texte qui sera affiché sur 
 *        l'écran à l'aide de la fonction MLV_draw_text_with_font().
 * 
 * Cette fonction est équivalente à la fonction 
 * MLV_get_size_of_text_with_font() à l'exception qu'elle est apellée 
 * avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_get_size_of_text_with_font() 
 *
 * \param text Le texte qui doit être affiché.
 * \param width La largeur du texte.
 * \param height La hauteur du texte.
 * \param font La fonte de caractères utilisée pour afficher le texte.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_get_size_of_text_with_font_va(
	const char *text, int *width, int *height, const MLV_Font* font, 
	va_list pile
);


/** \~french 
 * \brief Même chose que MLV_draw_adapted_text_box() mis à part que le texte est 
 *        rendu avec une fonte de caractères donnée en paramètre.
 * 
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_adapted_text_box_with_font() à l'exception qu'elle est apellée 
 * avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_adapted_text_box_with_font() 
 *
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param message Le texte à afficher.
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 * \param borderColor La couleur des bordures.
 * \param sizeInterligne La taille de l'interligne.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_adapted_text_box_with_font_va(
	int x, int y,
	const char* message,
	const MLV_Font* font, 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	va_list pile
);

/** \~french 
 * \brief Dessine une boîte contenant du texte.
 * 
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_adapted_text_box() à l'exception qu'elle est apellée 
 * avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_adapted_text_box() 
 *
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param message Le texte à afficher.
 * \param borderColor La couleur des bordures.
 * \param sizeInterligne La taille de l'interligne.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_adapted_text_box_va(
	int x, int y,
	const char* message,
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification, va_list pile
);

/** \~french 
 * \brief Même chose que MLV_draw_adapted_text_box() mis à part que le texte est 
 *        rendu avec une fonte de caractères donnée en paramètre.
 * 
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_adapted_text_box_on_image() à l'exception qu'elle est apellée 
 * avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_adapted_text_box_on_image() 
 *
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param message Le texte à afficher.
 * \param borderColor La couleur des bordures.
 * \param sizeInterligne La taille de l'interligne.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 * \param image L'image sur laquel le texte doit être ecrit.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_adapted_text_box_on_image_va(
	int x, int y,
	const char* message,
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Image* image, va_list pile
);

/** \~french 
 * \brief Même chose que MLV_draw_adapted_text_box_with_font() mis à part que 
 *        le texte est rendu sur une image et non directement à l'écran.
 * 
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_adapted_text_box_with_font_on_image() à l'exception qu'elle est 
 * apellée avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_adapted_text_box_with_font_on_image() 
 *
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param message Le texte à afficher.
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 * \param borderColor La couleur des bordures.
 * \param sizeInterligne Le taille de l'interligne.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 * \param image L'image sur laquel le texte doit être ecrit.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_adapted_text_box_with_font_on_image_va(
	int x, int y,
	const char* message,
	const MLV_Font* font, 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Image* image, va_list pile
);

/** \~french 
 * \brief Cette fonction calcule la taille de la boîte de texte qui serait 
 *        obtenue si vous utilisez la fonction : MLV_draw_adapted_text_box().
 * 
 * Cette fonction est équivalente à la fonction 
 * MLV_get_size_of_adapted_text_box() à l'exception qu'elle est 
 * apellée avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_get_size_of_adapted_text_box() 
 *
 * \param message         Le texte qui sera affiché lorsque vous utiliserez 
 *                        MLV_draw_adapted_text_box().
 * \param sizeInterligne  La taille de l'interligne.
 * \param result_width    La largeur de la boîte que vous obtiendrez en 
 *                        utilisant MLV_draw_adapted_text_box().
 * \param result_height   La hauteur de la boîte que vous obtiendrez en 
 *                        utilisant MLV_draw_adapted_text_box().
 * \param pile Une liste d'arguments supplémentaires
 *
 * \return La fonction renvoie la taille de la boîte de texte.
 */
int MLV_get_size_of_adapted_text_box_va(
	const char* message,
	int sizeInterligne,
	int *result_width, int *result_height,
	va_list pile
);

/** \~french 
 * \brief Cette fonction calcule la taille de la boîte de texte qui serait 
 *        obtenue si vous utilisez la fonction : 
 *        MLV_draw_adapted_text_box_with_font().
 *
 * Cette fonction est équivalente à la fonction 
 * MLV_get_size_of_adapted_text_box_with_font() à l'exception qu'elle est 
 * apellée avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_get_size_of_adapted_text_box_with_font() 
 *
 * \param message Le texte qui sera affiché lorsque vous utiliserez 
 *                MLV_draw_adapted_text_box_with_font().
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 * \param sizeInterligne La taille de l'interligne.
 * \param result_width La largeur de la boîte que vous obtiendrez en utilisant 
 *                     MLV_draw_adapted_text_box_with_font().
 * \param result_height La hauteur de la boîte que vous obtiendrez en utilisant 
 *                      MLV_draw_adapted_text_box_with_font().
 * \param pile Une liste d'arguments supplémentaires
 *
 * \return La fonction renvoie la taille de la boîte de texte.
 */
int MLV_get_size_of_adapted_text_box_with_font_va(
	const char* message,
	const MLV_Font* font, 
	int sizeInterligne,
	int *result_width, int *result_height,
	va_list pile
);


/** \~french 
 * \brief Même chose que la fonction MLV_draw_text_box() mis à part que le texte 
 *        est rendu avec une fonte de caractères donnée en paramètre par 
 *        l'utilisateur.
 *
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_text_box_with_font() à l'exception qu'elle est 
 * apellée avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_text_box_with_font() 
 * 
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param width La largeur de la boîte.
 * \param height La hauteur de la boîte.
 * \param message Le texte à afficher.
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 * \param sizeInterligne La taille de l'interligne.
 * \param borderColor La couleur des bordures.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 * \param horizontal_position La position horizontale du texte dans la boîte.
 * \param vertical_position La position verticale du texte dans la boîte.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_text_box_with_font_va( 
	int x, int y, 
	int width, int height, 
	const char* message , 
	const MLV_Font* font, 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Horizontal_position horizontal_position,
	MLV_Vertical_position vertical_position,
	va_list pile
);

/** \~french 
 * \brief Dessine une boîte de taille donnée par l'utilisateur et contenant un 
 *        texte donné par l'utilisateur.
 *
 *
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_text_box() à l'exception qu'elle est 
 * apellée avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_text_box() 
 *
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param width La largeur de la boîte.
 * \param height La hauteur de la boîte.
 * \param message Le texte à afficher.
 * \param sizeInterligne La taille de l'interligne.
 * \param borderColor La couleur des bordures.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 * \param horizontal_position La position horizontale du texte dans la boîte.
 * \param vertical_position La position verticale du texte dans la boîte.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_text_box_va( 
	int x, int y, 
	int width, int height, 
	const char* message , 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Horizontal_position horizontal_position,
	MLV_Vertical_position vertical_position,
	va_list pile
);

/** \~french 
 * \brief Même chose que la fonction MLV_draw_text_box_with_font() mis à part que 
 *        le texte n'est pas dessinné directement sur l'ecran, mais sur une
 *        une image.
 *
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_text_box_with_font_on_image() à l'exception qu'elle est 
 * apellée avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_text_box_with_font_on_image() 
 * 
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param width La largeur de la boîte.
 * \param height La hauteur de la boîte.
 * \param message Le texte à afficher.
 * \param font La fonte caractères utilisée pour dessiner le texte.
 * \param sizeInterligne La taille de l'interligne.
 * \param borderColor La couleur des bordures.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 * \param horizontal_position La position horizontale du texte dans la boîte.
 * \param vertical_position La position verticale du texte dans la boîte.
 * \param image L'image sur laquel le texte doit être ecrit.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_text_box_with_font_on_image_va( 
	int x, int y, 
	int width, int height, 
	const char* message , 
	MLV_Font* font, 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Horizontal_position horizontal_position,
	MLV_Vertical_position vertical_position,
	MLV_Image* image,
	va_list pile
);

/** \~french 
 * \brief Même chose que MLV_draw_text_box() mis à part que le texte n'est pas
 *        écrit directement sur l'écran, mais sur une image à la place. 
 *
 * Cette fonction est équivalente à la fonction 
 * MLV_draw_text_box_on_image() à l'exception qu'elle est 
 * apellée avec un paramètre de type va_list à la place d'une nombre variable 
 * d'arguments.
 *
 * Pour plus de détail sur la fonction, aller voir la documentation de 
 * MLV_draw_text_box_on_image() 
 *
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param width La largeur de la boîte.
 * \param height La hauteur de la boîte.
 * \param message Le texte à afficher.
 * \param sizeInterligne La taille de l'interligne.
 * \param borderColor La couleur des bordures.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 * \param horizontal_position La position horizontale du texte dans la boîte.
 * \param vertical_position La position verticale du texte dans la boîte.
 * \param image L'image sur laquel le texte doit être ecrit.
 * \param pile Une liste d'arguments supplémentaires
 */
void MLV_draw_text_box_on_image_va( 
	int x, int y, 
	int width, int height, 
	const char* message , 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Horizontal_position horizontal_position,
	MLV_Vertical_position vertical_position,
	MLV_Image* image,
	va_list pile
);

#ifdef __cplusplus
}
#endif

#endif

