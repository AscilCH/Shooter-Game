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
 * \file MLV_text.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les différents prototypes des fonctions permmettant
 *        d'afficher du texte et des boîtes de dialogues.
 */

#ifndef __MLV__MLV_TEXT_H__
#define __MLV__MLV_TEXT_H__

#include "MLV_color.h"
#include "MLV_image.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Énumère les différents types de justification du texte.
 */
typedef enum {
	MLV_TEXT_CENTER, /**< \~french Le texte est justifié au centre. */
	MLV_TEXT_LEFT, /**< \~french Le texte est justifié sur la gauche. */
	MLV_TEXT_RIGHT /**< \~french Le texte est justifié sur la doite. */
} MLV_Text_justification;

/** \~french 
 * \brief Énumère les différents types de position horizontale du texte dans une boîte.
 */
typedef enum {
	MLV_HORIZONTAL_CENTER, /**< \~french Le texte est centrée horizontalement 
	                        * dans la boîte. */
	MLV_HORIZONTAL_LEFT, /**< \~french Le texte est positioné sur la droite de 
	                      * la boîte. */
	MLV_HORIZONTAL_RIGHT /**< \~french Le texte est positioné sur la gauche de
	                      * la boîte. */
} MLV_Horizontal_position;

/** \~french 
 * \brief Énumère les différents types de positions verticales du texte dans une boîte.
 */
typedef enum {
	MLV_VERTICAL_CENTER, /**< \~french Le texte est centré horizonatalement 
	                      * dans la boîte. */
	MLV_VERTICAL_TOP, /**< \~french Le texte est positionné en haut de la
	                   * boîte. */
	MLV_VERTICAL_BOTTOM /**< \~french Le texte est positionné en bas de la 
	                     * boîte. */
} MLV_Vertical_position;

/** \~french 
 * Ce type code une fonte de caractères.
 */
typedef struct _MLV_Font MLV_Font;

/** \~french 
 * \brief Cette fonction charge en mémoire une fonte de caractères de standard 
 *        "TrueType" (fichiers ayant une extension .ttf).
 *
 * La fonte de caractères chargée est configurée avec une taille de fonte 
 * donnée en paramètre.
 *
 * \param file_font Le chemin d'accés où se trouve le fichier contenant la 
 *                  fonte de caractères.
 * \param size La taille de la fonte de caractères.
 * \return La structure de donnée MLV contenant la fonte de caractères. 
 */
MLV_Font* MLV_load_font( const char* file_font, int size );

/** \~french 
 * \brief Cette fonction libère la mémoire d'une fonte de caractères 
 *        précédement chargée.
 *
 * \param font L'adresse de la fonte de caractères à libérer.
 */
void MLV_free_font( MLV_Font* font );

/** \~french 
 * \brief Cette fonction calcule la taille du texte qui sera affiché sur 
 *        l'écran à l'aide de la fonction MLV_draw_text().
 *
 * \param text Le texte qui doit être affiché.
 * \param width La largeur du texte.
 * \param height La hauteur du texte.
 */
void MLV_get_size_of_text( const char *text, int *width, int *height, ... );

/** \~french 
 * \brief Cette fonction calcule la taille du texte qui sera affiché sur 
 *        l'écran à l'aide de la fonction MLV_draw_text_with_font().
 *
 * \param text Le texte qui doit être affiché.
 * \param width La largeur du texte.
 * \param height La hauteur du texte.
 * \param font La fonte de caractères utilisée pour afficher le texte.
 */
void MLV_get_size_of_text_with_font(
	const char *text, int *width, int *height, const MLV_Font* font, ...
);

/** \~french 
 * \brief Imprime un texte donné à une position et une couleur données.
 * 
 * Le texte est imprimé à l'aide de la fonte de caractères par default de la 
 * bibliothèque MLV.
 *
 * \param x Coordonnée en X du coin Nord-Ouest du texte
 * \param y Coordonnée en Y du coin Nord-Ouest du texte
 * \param text texte à afficher
 * \param color couleur du tracé
 */
void MLV_draw_text( int x, int y, const char *text, MLV_Color color, ... );

/** \~french 
 * \brief Écrit du texte sur l'écran en utilisant une couleur et une fonte de 
 *        caractères données en paramètres.
 * 
 * \param x La coordonnée en X du coin Nord-Ouest du texte.
 * \param y La coordonnée en Y du coin Nord-Ouest du texte.
 * \param text Le texte à afficher.
 * \param color La couleur du tracé.
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 */
void MLV_draw_text_with_font(
	int x, int y, const char *text, const MLV_Font* font, MLV_Color color, ...
);

/** \~french 
 * \brief Écrit sur une image un texte donné à une position et une couleur
 *        données.
 * 
 * Le texte est imprimé à l'aide de la fonte de caractères par default de la 
 * bibliothèque MLV.
 *
 * \param x La coordonnée en X du coin Nord-Ouest du texte.
 * \param y La coordonnée en Y du coin Nord-Ouest du texte.
 * \param text Le texte à afficher.
 * \param color La couleur du tracé.
 * \param image L'image sur laquel le texte doit être ecrit.
 */
void MLV_draw_text_on_image(
	int x, int y, const char *text, MLV_Color color, MLV_Image* image, ...
);

/** \~french 
 * \brief Écrit du texte sur une image en utilisant une couleur et une fonte de
 *        caractères données en paramètres.
 * 
 * \param x La coordonnée en X du coin Nord-Ouest du texte.
 * \param y La coordonnée en Y du coin Nord-Ouest du texte.
 * \param text Le texte à afficher.
 * \param color La couleur du tracé.
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 * \param image L'image sur laquel le texte doit être ecrit.
 */
void MLV_draw_text_with_font_on_image(
	int x, int y, const char *text, const MLV_Font* font, MLV_Color color, 
	MLV_Image* image, ...
);

/** \~french 
 * \brief Dessine une boîte contenant du texte.
 *
 * La taille de la boîte dessinée s'adapte à la
 * taille du texte.
 * Les différentes couleurs de la boîte et du texte,
 * ainsi que la taille de l'interligne du texte sont
 * paramétrables.
 *
 * Il est possible de préciser la justification du texte à l'aide du 
 * paramètre "text_justification".
 *
 * \param x La coordonnée en X de la position du coin Nord-Ouest de la boîte.
 * \param y La coordonnée en Y de la position du coin Nord-Ouest de la boîte.
 * \param message Le texte à afficher.
 * \param borderColor La couleur des bordures.
 * \param sizeInterligne La taille de l'interligne.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond de la boîte.
 * \param text_justification La justification du texte.
 */
void MLV_draw_adapted_text_box(
	int x, int y,
	const char* message,
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification, ...
);

/** \~french 
 * \brief Même chose que MLV_draw_adapted_text_box() mis à part que le texte est 
 *        rendu avec une fonte de caractères donnée en paramètre.
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
 */
void MLV_draw_adapted_text_box_on_image(
	int x, int y,
	const char* message,
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Image* image, ...
);

/** \~french 
 * \brief Cette fonction calcule la taille de la boîte de texte qui serait 
 *        obtenue si vous utilisez la fonction : MLV_draw_adapted_text_box().
 *
 * \param message         Le texte qui sera affiché lorsque vous utiliserez 
 *                        MLV_draw_adapted_text_box().
 * \param sizeInterligne  La taille de l'interligne.
 * \param result_width    La largeur de la boîte que vous obtiendrez en 
 *                        utilisant MLV_draw_adapted_text_box().
 * \param result_height   La hauteur de la boîte que vous obtiendrez en 
 *                        utilisant MLV_draw_adapted_text_box().
 *
 * \return La fonction renvoie la taille de la boîte de texte.
 */
int MLV_get_size_of_adapted_text_box(
	const char* message,
	int sizeInterligne,
	int *result_width, int *result_height,
	...
);

/** \~french 
 * \brief Même chose que MLV_draw_adapted_text_box() mis à part que le texte est 
 *        rendu avec une fonte de caractères donnée en paramètre.
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
 */
void MLV_draw_adapted_text_box_with_font(
	int x, int y,
	const char* message,
	const MLV_Font* font, 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification, ...
);

/** \~french 
 * \brief Même chose que MLV_draw_adapted_text_box_with_font() mis à part que 
 *        le texte est rendu sur une image et non directement à l'écran.
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
 */
void MLV_draw_adapted_text_box_with_font_on_image(
	int x, int y,
	const char* message,
	const MLV_Font* font, 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Image* image, ...
);


/** \~french 
 * \brief Cette fonction calcule la taille de la boîte de texte qui serait 
 *        obtenue si vous utilisez la fonction : 
 *        MLV_draw_adapted_text_box_with_font().
 *
 * \param message Le texte qui sera affiché lorsque vous utiliserez 
 *                MLV_draw_adapted_text_box_with_font().
 * \param font La fonte de caractères utilisée pour dessiner le texte.
 * \param sizeInterligne La taille de l'interligne.
 * \param result_width La largeur de la boîte que vous obtiendrez en utilisant 
 *                     MLV_draw_adapted_text_box_with_font().
 * \param result_height La hauteur de la boîte que vous obtiendrez en utilisant 
 *                      MLV_draw_adapted_text_box_with_font().
 *
 * \return La fonction renvoie la taille de la boîte de texte.
 */
int MLV_get_size_of_adapted_text_box_with_font(
	const char* message,
	const MLV_Font* font, 
	int sizeInterligne,
	int *result_width, int *result_height,
	...
);

/** \~french 
 * \brief Dessine une boîte de taille donnée par l'utilisateur et contenant un 
 *        texte donné par l'utilisateur.
 *
* Le texte est déssiné à l'interieur d'une boîte. Le texte est imprimé sur 
* plusieurs lignes en respectant les retours à la ligne présents dans le texte.
 *
 * Les différentes couleurs de la boîte et du texte, ainsi que la taille de 
 * l'interligne du texte sont paramétrables.
 *
 * Il est possible de préciser la justification du texte contenu dans la boîte.
 *
 * De même , il est possible de préciser la position du texte à l'intérieur de 
 * la boîte.
 *                     
 * Cette fonction ne remet pas en forme le texte. Cela veux dire que si le texte
 * est trop grand, alors il dépassera de la boîte et les parties qui depassent 
 * ne seront pas affichées.
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
 */
void MLV_draw_text_box( 
	int x, int y, 
	int width, int height, 
	const char* message , 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Horizontal_position horizontal_position,
	MLV_Vertical_position vertical_position,
	...
);

/** \~french 
 * \brief Même chose que MLV_draw_text_box() mis à part que le texte n'est pas
 *        écrit directement sur l'écran, mais sur une image à la place. 
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
 */
void MLV_draw_text_box_on_image( 
	int x, int y, 
	int width, int height, 
	const char* message , 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Horizontal_position horizontal_position,
	MLV_Vertical_position vertical_position,
	MLV_Image* image,
	...
);

/** \~french 
 * \brief Même chose que la fonction MLV_draw_text_box() mis à part que le texte 
 *        est rendu avec une fonte de caractères donnée en paramètre par 
 *        l'utilisateur.
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
 */
void MLV_draw_text_box_with_font( 
	int x, int y, 
	int width, int height, 
	const char* message , 
	const MLV_Font* font, 
	int sizeInterligne,
	MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor,
	MLV_Text_justification text_justification,
	MLV_Horizontal_position horizontal_position,
	MLV_Vertical_position vertical_position,
	...
);

/** \~french 
 * \brief Même chose que la fonction MLV_draw_text_box_with_font() mis à part que 
 *        le texte n'est pas dessinné directement sur l'ecran, mais sur une
 *        une image.
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
 */
void MLV_draw_text_box_with_font_on_image( 
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
	...
);

/** \~french 
 * \brief Transforme un caractère en format unicode en chaîne de caractères 
 *        compatible avec le codage local (codage utilisé par la machine qui 
 *        exécute le programme).
 *
 * Après utilisation, vous devez libérer l'espace mémoire de la chaîne de 
 * caractères renvoyée par la fonction.
 * 
 * \param unicode Le caractère en format unicode.
 * \return Un pointeur vers une nouvelle chaîne de caractères.
 */
char* MLV_convert_unicode_to_string( int unicode );

#ifdef __cplusplus
}
#endif

#endif

