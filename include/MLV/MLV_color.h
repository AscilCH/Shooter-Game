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
 * \file MLV_color.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Définit toutes les couleurs disponibles dans la bibliothèque MLV.
 *
 */

#ifndef __MLV__MLV_COLOR_H__
#define __MLV__MLV_COLOR_H__

#ifndef MEMORY_DEBUG
#include <SDL/SDL.h>
#else
#include "memory_debug.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Définit un type couleur pour la bibliothèque MLV
 *
 * Les couleurs sont définies à l'aide de 4 
 * entiers compris entre 0 et 256 exclu, que l'on appelle composantes : 
 * - la composante Rouge ( R );
 * - la composante Verte ( G );
 * - la composant Blue ( B );
 * - la composante Alpha, c'est la transparence ( A ).
 */
typedef Uint32 MLV_Color;

/** \~french 
 * \brief Énumère les valeurs de transparence et d'opacité (codés sur 8 bits )
 */
enum {
	MLV_ALPHA_TRANSPARENT = SDL_ALPHA_TRANSPARENT,
	MLV_ALPHA_OPAQUE = SDL_ALPHA_OPAQUE
}; 

/** \~french 
 * \brief Type codant la transparence dans MLV
 */
typedef Uint8 MLV_Alpha;


/** \~french 
 * \brief Raccourci vers MLV_Color MLV_get_color_from_rgba.
 *
 * \see MLV_get_color_from_rgba
 *
 * \param red La composante rouge de la couleur
 * \param green La composante verte de la couleur
 * \param blue La composante bleue de la couleur
 * \param alpha La composante alpha (transparence) de la couleur
 * \return La couleur codée sur 32 bits.
 */
MLV_Color MLV_rgba( Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha );

/** \~french 
 * \brief Convertit une couleur codée sur 4 entier de 8 bits représentant les 
 *        composantes rouge, bleue et verte en un entier 32 bits.
 *
 * \param red La composante rouge de la couleur
 * \param green La composante verte de la couleur
 * \param blue La composante bleue de la couleur
 * \param alpha La composante alpha (transparence) de la couleur
 * \return La couleur codée sur 32 bits.
 */
MLV_Color MLV_convert_rgba_to_color(
	Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha
);

/** \~french 
 * \brief Convertit une couleur MLV en une couleur codée sur 4 entier de 8 bits
 *        représentant les composantes rouge, bleue et verte en un entier 32 
 *        bits.
 *
 * \param color La couleur à convertir
 * \param red La composante rouge de la couleur
 * \param green La composante verte de la couleur
 * \param blue La composante bleue de la couleur
 * \param alpha La composante alpha (transparence) de la couleur
 */
void MLV_convert_color_to_rgba(
	MLV_Color color, Uint8* red, Uint8* green, Uint8* blue, Uint8* alpha
);

/** \~french
 * \brief Convertit une couleur en un chaine de caractères.
 *
 * Cette fonction est de complexité lineaire par rapport au nombre de couleurs.
 * ( environ 700 )
 *
 * \param color Le code de la couleur
 * \return La chaîne associée au code de la couleur
 *
 */
const char* MLV_convert_color_to_string( MLV_Color color );

/** \~french
 * \brief Convertit un nom de couleur en son code couleur.
 *
 * Cette fonction est de complexité lineaire par rapport au nombre de couleurs.
 * ( environ 700 )
 *
 * \param color_name Le nom de la couleur
 * \return Le code couleur associée au nom passé en paramètre.
 */
MLV_Color MLV_convert_string_to_color( const char* color_name );

/** \~french 
 * Define the SNOW color.
 *
 */
#define MLV_COLOR_SNOW MLV_rgba(255,250,250,255) 

/** \~french 
 * Define the GHOST_WHITE color.
 *
 */
#define MLV_COLOR_GHOST_WHITE MLV_rgba(248,248,255,255)

/** \~french 
 * Define the GHOSTWHITE color.
 *
 */
#define MLV_COLOR_GHOSTWHITE MLV_rgba(248,248,255,255)

/** \~french 
 * Define the WHITE_SMOKE color.
 *
 */
#define MLV_COLOR_WHITE_SMOKE MLV_rgba(245,245,245,255)

/** \~french 
 * Define the WHITESMOKE color.
 *
 */
#define MLV_COLOR_WHITESMOKE MLV_rgba(245,245,245,255)

/** \~french 
 * Define the GAINSBORO color.
 *
 */
#define MLV_COLOR_GAINSBORO MLV_rgba(220,220,220,255)

/** \~french 
 * Define the FLORAL_WHITE color.
 *
 */
#define MLV_COLOR_FLORAL_WHITE MLV_rgba(255,250,240,255)

/** \~french 
 * Define the FLORALWHITE color.
 *
 */
#define MLV_COLOR_FLORALWHITE MLV_rgba(255,250,240,255)

/** \~french 
 * Define the OLD_LACE color.
 *
 */
#define MLV_COLOR_OLD_LACE MLV_rgba(253,245,230,255)

/** \~french 
 * Define the OLDLACE color.
 *
 */
#define MLV_COLOR_OLDLACE MLV_rgba(253,245,230,255)

/** \~french 
 * Define the LINEN color.
 *
 */
#define MLV_COLOR_LINEN MLV_rgba(250,240,230,255)

/** \~french 
 * Define the ANTIQUE_WHITE color.
 *
 */
#define MLV_COLOR_ANTIQUE_WHITE MLV_rgba(250,235,215,255)

/** \~french 
 * Define the ANTIQUEWHITE color.
 *
 */
#define MLV_COLOR_ANTIQUEWHITE MLV_rgba(250,235,215,255)

/** \~french 
 * Define the PAPAYA_WHIP color.
 *
 */
#define MLV_COLOR_PAPAYA_WHIP MLV_rgba(255,239,213,255)

/** \~french 
 * Define the PAPAYAWHIP color.
 *
 */
#define MLV_COLOR_PAPAYAWHIP MLV_rgba(255,239,213,255)

/** \~french 
 * Define the BLANCHED_ALMOND color.
 *
 */
#define MLV_COLOR_BLANCHED_ALMOND MLV_rgba(255,235,205,255)

/** \~french 
 * Define the BLANCHEDALMOND color.
 *
 */
#define MLV_COLOR_BLANCHEDALMOND MLV_rgba(255,235,205,255)

/** \~french 
 * Define the BISQUE color.
 *
 */
#define MLV_COLOR_BISQUE MLV_rgba(255,228,196,255)

/** \~french 
 * Define the PEACH_PUFF color.
 *
 */
#define MLV_COLOR_PEACH_PUFF MLV_rgba(255,218,185,255)

/** \~french 
 * Define the PEACHPUFF color.
 *
 */
#define MLV_COLOR_PEACHPUFF MLV_rgba(255,218,185,255)

/** \~french 
 * Define the NAVAJO_WHITE color.
 *
 */
#define MLV_COLOR_NAVAJO_WHITE MLV_rgba(255,222,173,255)

/** \~french 
 * Define the NAVAJOWHITE color.
 *
 */
#define MLV_COLOR_NAVAJOWHITE MLV_rgba(255,222,173,255)

/** \~french 
 * Define the MOCCASIN color.
 *
 */
#define MLV_COLOR_MOCCASIN MLV_rgba(255,228,181,255)

/** \~french 
 * Define the CORNSILK color.
 *
 */
#define MLV_COLOR_CORNSILK MLV_rgba(255,248,220,255)

/** \~french 
 * Define the IVORY color.
 *
 */
#define MLV_COLOR_IVORY MLV_rgba(255,255,240,255)

/** \~french 
 * Define the LEMON_CHIFFON color.
 *
 */
#define MLV_COLOR_LEMON_CHIFFON MLV_rgba(255,250,205,255)

/** \~french 
 * Define the LEMONCHIFFON color.
 *
 */
#define MLV_COLOR_LEMONCHIFFON MLV_rgba(255,250,205,255)

/** \~french 
 * Define the SEASHELL color.
 *
 */
#define MLV_COLOR_SEASHELL MLV_rgba(255,245,238,255)

/** \~french 
 * Define the HONEYDEW color.
 *
 */
#define MLV_COLOR_HONEYDEW MLV_rgba(240,255,240,255)

/** \~french 
 * Define the MINT_CREAM color.
 *
 */
#define MLV_COLOR_MINT_CREAM MLV_rgba(245,255,250,255)

/** \~french 
 * Define the MINTCREAM color.
 *
 */
#define MLV_COLOR_MINTCREAM MLV_rgba(245,255,250,255)

/** \~french 
 * Define the AZURE color.
 *
 */
#define MLV_COLOR_AZURE MLV_rgba(240,255,255,255)

/** \~french 
 * Define the ALICE_BLUE color.
 *
 */
#define MLV_COLOR_ALICE_BLUE MLV_rgba(240,248,255,255)

/** \~french 
 * Define the ALICEBLUE color.
 *
 */
#define MLV_COLOR_ALICEBLUE MLV_rgba(240,248,255,255)

/** \~french 
 * Define the LAVENDER color.
 *
 */
#define MLV_COLOR_LAVENDER MLV_rgba(230,230,250,255)

/** \~french 
 * Define the LAVENDER_BLUSH color.
 *
 */
#define MLV_COLOR_LAVENDER_BLUSH MLV_rgba(255,240,245,255)

/** \~french 
 * Define the LAVENDERBLUSH color.
 *
 */
#define MLV_COLOR_LAVENDERBLUSH MLV_rgba(255,240,245,255)

/** \~french 
 * Define the MISTY_ROSE color.
 *
 */
#define MLV_COLOR_MISTY_ROSE MLV_rgba(255,228,225,255)

/** \~french 
 * Define the MISTYROSE color.
 *
 */
#define MLV_COLOR_MISTYROSE MLV_rgba(255,228,225,255)

/** \~french 
 * Define the WHITE color.
 *
 */
#define MLV_COLOR_WHITE MLV_rgba(255,255,255,255)

/** \~french 
 * Define the BLACK color.
 *
 */
#define MLV_COLOR_BLACK MLV_rgba(0,0,0,255)

/** \~french 
 * Define the DARK_SLATE_GRAY color.
 *
 */
#define MLV_COLOR_DARK_SLATE_GRAY MLV_rgba(47,79,79,255)

/** \~french 
 * Define the DARKSLATEGRAY color.
 *
 */
#define MLV_COLOR_DARKSLATEGRAY MLV_rgba(47,79,79,255)

/** \~french 
 * Define the DARK_SLATE_GREY color.
 *
 */
#define MLV_COLOR_DARK_SLATE_GREY MLV_rgba(47,79,79,255)

/** \~french 
 * Define the DARKSLATEGREY color.
 *
 */
#define MLV_COLOR_DARKSLATEGREY MLV_rgba(47,79,79,255)

/** \~french 
 * Define the DIM_GRAY color.
 *
 */
#define MLV_COLOR_DIM_GRAY MLV_rgba(105,105,105,255)

/** \~french 
 * Define the DIMGRAY color.
 *
 */
#define MLV_COLOR_DIMGRAY MLV_rgba(105,105,105,255)

/** \~french 
 * Define the DIM_GREY color.
 *
 */
#define MLV_COLOR_DIM_GREY MLV_rgba(105,105,105,255)

/** \~french 
 * Define the DIMGREY color.
 *
 */
#define MLV_COLOR_DIMGREY MLV_rgba(105,105,105,255)

/** \~french 
 * Define the SLATE_GRAY color.
 *
 */
#define MLV_COLOR_SLATE_GRAY MLV_rgba(112,128,144,255)

/** \~french 
 * Define the SLATEGRAY color.
 *
 */
#define MLV_COLOR_SLATEGRAY MLV_rgba(112,128,144,255)

/** \~french 
 * Define the SLATE_GREY color.
 *
 */
#define MLV_COLOR_SLATE_GREY MLV_rgba(112,128,144,255)

/** \~french 
 * Define the SLATEGREY color.
 *
 */
#define MLV_COLOR_SLATEGREY MLV_rgba(112,128,144,255)

/** \~french 
 * Define the LIGHT_SLATE_GRAY color.
 *
 */
#define MLV_COLOR_LIGHT_SLATE_GRAY MLV_rgba(119,136,153,255)

/** \~french 
 * Define the LIGHTSLATEGRAY color.
 *
 */
#define MLV_COLOR_LIGHTSLATEGRAY MLV_rgba(119,136,153,255)

/** \~french 
 * Define the LIGHT_SLATE_GREY color.
 *
 */
#define MLV_COLOR_LIGHT_SLATE_GREY MLV_rgba(119,136,153,255)

/** \~french 
 * Define the LIGHTSLATEGREY color.
 *
 */
#define MLV_COLOR_LIGHTSLATEGREY MLV_rgba(119,136,153,255)

/** \~french 
 * Define the GRAY color.
 *
 */
#define MLV_COLOR_GRAY MLV_rgba(190,190,190,255)

/** \~french 
 * Define the GREY color.
 *
 */
#define MLV_COLOR_GREY MLV_rgba(190,190,190,255)

/** \~french 
 * Define the LIGHT_GREY color.
 *
 */
#define MLV_COLOR_LIGHT_GREY MLV_rgba(211,211,211,255)

/** \~french 
 * Define the LIGHTGREY color.
 *
 */
#define MLV_COLOR_LIGHTGREY MLV_rgba(211,211,211,255)

/** \~french 
 * Define the LIGHT_GRAY color.
 *
 */
#define MLV_COLOR_LIGHT_GRAY MLV_rgba(211,211,211,255)

/** \~french 
 * Define the LIGHTGRAY color.
 *
 */
#define MLV_COLOR_LIGHTGRAY MLV_rgba(211,211,211,255)

/** \~french 
 * Define the MIDNIGHT_BLUE color.
 *
 */
#define MLV_COLOR_MIDNIGHT_BLUE MLV_rgba(25,25,112,255)

/** \~french 
 * Define the MIDNIGHTBLUE color.
 *
 */
#define MLV_COLOR_MIDNIGHTBLUE MLV_rgba(25,25,112,255)

/** \~french 
 * Define the NAVY color.
 *
 */
#define MLV_COLOR_NAVY MLV_rgba(0,0,128,255)

/** \~french 
 * Define the NAVY_BLUE color.
 *
 */
#define MLV_COLOR_NAVY_BLUE MLV_rgba(0,0,128,255)

/** \~french 
 * Define the NAVYBLUE color.
 *
 */
#define MLV_COLOR_NAVYBLUE MLV_rgba(0,0,128,255)

/** \~french 
 * Define the CORNFLOWER_BLUE color.
 *
 */
#define MLV_COLOR_CORNFLOWER_BLUE MLV_rgba(100,149,237,255)

/** \~french 
 * Define the CORNFLOWERBLUE color.
 *
 */
#define MLV_COLOR_CORNFLOWERBLUE MLV_rgba(100,149,237,255)

/** \~french 
 * Define the DARK_SLATE_BLUE color.
 *
 */
#define MLV_COLOR_DARK_SLATE_BLUE MLV_rgba(72,61,139,255)

/** \~french 
 * Define the DARKSLATEBLUE color.
 *
 */
#define MLV_COLOR_DARKSLATEBLUE MLV_rgba(72,61,139,255)

/** \~french 
 * Define the SLATE_BLUE color.
 *
 */
#define MLV_COLOR_SLATE_BLUE MLV_rgba(106,90,205,255)

/** \~french 
 * Define the SLATEBLUE color.
 *
 */
#define MLV_COLOR_SLATEBLUE MLV_rgba(106,90,205,255)

/** \~french 
 * Define the MEDIUM_SLATE_BLUE color.
 *
 */
#define MLV_COLOR_MEDIUM_SLATE_BLUE MLV_rgba(123,104,238,255)

/** \~french 
 * Define the MEDIUMSLATEBLUE color.
 *
 */
#define MLV_COLOR_MEDIUMSLATEBLUE MLV_rgba(123,104,238,255)

/** \~french 
 * Define the LIGHT_SLATE_BLUE color.
 *
 */
#define MLV_COLOR_LIGHT_SLATE_BLUE MLV_rgba(132,112,255,255)

/** \~french 
 * Define the LIGHTSLATEBLUE color.
 *
 */
#define MLV_COLOR_LIGHTSLATEBLUE MLV_rgba(132,112,255,255)

/** \~french 
 * Define the MEDIUM_BLUE color.
 *
 */
#define MLV_COLOR_MEDIUM_BLUE MLV_rgba(0,0,205,255)

/** \~french 
 * Define the MEDIUMBLUE color.
 *
 */
#define MLV_COLOR_MEDIUMBLUE MLV_rgba(0,0,205,255)

/** \~french 
 * Define the ROYAL_BLUE color.
 *
 */
#define MLV_COLOR_ROYAL_BLUE MLV_rgba(65,105,225,255)

/** \~french 
 * Define the ROYALBLUE color.
 *
 */
#define MLV_COLOR_ROYALBLUE MLV_rgba(65,105,225,255)

/** \~french 
 * Define the BLUE color.
 *
 */
#define MLV_COLOR_BLUE MLV_rgba(0,0,255,255)

/** \~french 
 * Define the DODGER_BLUE color.
 *
 */
#define MLV_COLOR_DODGER_BLUE MLV_rgba(30,144,255,255)

/** \~french 
 * Define the DODGERBLUE color.
 *
 */
#define MLV_COLOR_DODGERBLUE MLV_rgba(30,144,255,255)

/** \~french 
 * Define the DEEP_SKY_BLUE color.
 *
 */
#define MLV_COLOR_DEEP_SKY_BLUE MLV_rgba(0,191,255,255)

/** \~french 
 * Define the DEEPSKYBLUE color.
 *
 */
#define MLV_COLOR_DEEPSKYBLUE MLV_rgba(0,191,255,255)

/** \~french 
 * Define the SKY_BLUE color.
 *
 */
#define MLV_COLOR_SKY_BLUE MLV_rgba(135,206,235,255)

/** \~french 
 * Define the SKYBLUE color.
 *
 */
#define MLV_COLOR_SKYBLUE MLV_rgba(135,206,235,255)

/** \~french 
 * Define the LIGHT_SKY_BLUE color.
 *
 */
#define MLV_COLOR_LIGHT_SKY_BLUE MLV_rgba(135,206,250,255)

/** \~french 
 * Define the LIGHTSKYBLUE color.
 *
 */
#define MLV_COLOR_LIGHTSKYBLUE MLV_rgba(135,206,250,255)

/** \~french 
 * Define the STEEL_BLUE color.
 *
 */
#define MLV_COLOR_STEEL_BLUE MLV_rgba(70,130,180,255)

/** \~french 
 * Define the STEELBLUE color.
 *
 */
#define MLV_COLOR_STEELBLUE MLV_rgba(70,130,180,255)

/** \~french 
 * Define the LIGHT_STEEL_BLUE color.
 *
 */
#define MLV_COLOR_LIGHT_STEEL_BLUE MLV_rgba(176,196,222,255)

/** \~french 
 * Define the LIGHTSTEELBLUE color.
 *
 */
#define MLV_COLOR_LIGHTSTEELBLUE MLV_rgba(176,196,222,255)

/** \~french 
 * Define the LIGHT_BLUE color.
 *
 */
#define MLV_COLOR_LIGHT_BLUE MLV_rgba(173,216,230,255)

/** \~french 
 * Define the LIGHTBLUE color.
 *
 */
#define MLV_COLOR_LIGHTBLUE MLV_rgba(173,216,230,255)

/** \~french 
 * Define the POWDER_BLUE color.
 *
 */
#define MLV_COLOR_POWDER_BLUE MLV_rgba(176,224,230,255)

/** \~french 
 * Define the POWDERBLUE color.
 *
 */
#define MLV_COLOR_POWDERBLUE MLV_rgba(176,224,230,255)

/** \~french 
 * Define the PALE_TURQUOISE color.
 *
 */
#define MLV_COLOR_PALE_TURQUOISE MLV_rgba(175,238,238,255)

/** \~french 
 * Define the PALETURQUOISE color.
 *
 */
#define MLV_COLOR_PALETURQUOISE MLV_rgba(175,238,238,255)

/** \~french 
 * Define the DARK_TURQUOISE color.
 *
 */
#define MLV_COLOR_DARK_TURQUOISE MLV_rgba(0,206,209,255)

/** \~french 
 * Define the DARKTURQUOISE color.
 *
 */
#define MLV_COLOR_DARKTURQUOISE MLV_rgba(0,206,209,255)

/** \~french 
 * Define the MEDIUM_TURQUOISE color.
 *
 */
#define MLV_COLOR_MEDIUM_TURQUOISE MLV_rgba(72,209,204,255)

/** \~french 
 * Define the MEDIUMTURQUOISE color.
 *
 */
#define MLV_COLOR_MEDIUMTURQUOISE MLV_rgba(72,209,204,255)

/** \~french 
 * Define the TURQUOISE color.
 *
 */
#define MLV_COLOR_TURQUOISE MLV_rgba(64,224,208,255)

/** \~french 
 * Define the CYAN color.
 *
 */
#define MLV_COLOR_CYAN MLV_rgba(0,255,255,255)

/** \~french 
 * Define the LIGHT_CYAN color.
 *
 */
#define MLV_COLOR_LIGHT_CYAN MLV_rgba(224,255,255,255)

/** \~french 
 * Define the LIGHTCYAN color.
 *
 */
#define MLV_COLOR_LIGHTCYAN MLV_rgba(224,255,255,255)

/** \~french 
 * Define the CADET_BLUE color.
 *
 */
#define MLV_COLOR_CADET_BLUE MLV_rgba(95,158,160,255)

/** \~french 
 * Define the CADETBLUE color.
 *
 */
#define MLV_COLOR_CADETBLUE MLV_rgba(95,158,160,255)

/** \~french 
 * Define the MEDIUM_AQUAMARINE color.
 *
 */
#define MLV_COLOR_MEDIUM_AQUAMARINE MLV_rgba(102,205,170,255)

/** \~french 
 * Define the MEDIUMAQUAMARINE color.
 *
 */
#define MLV_COLOR_MEDIUMAQUAMARINE MLV_rgba(102,205,170,255)

/** \~french 
 * Define the AQUAMARINE color.
 *
 */
#define MLV_COLOR_AQUAMARINE MLV_rgba(127,255,212,255)

/** \~french 
 * Define the DARK_GREEN color.
 *
 */
#define MLV_COLOR_DARK_GREEN MLV_rgba(0,100,0,255)

/** \~french 
 * Define the DARKGREEN color.
 *
 */
#define MLV_COLOR_DARKGREEN MLV_rgba(0,100,0,255)

/** \~french 
 * Define the DARK_OLIVE_GREEN color.
 *
 */
#define MLV_COLOR_DARK_OLIVE_GREEN MLV_rgba(85,107,47,255)

/** \~french 
 * Define the DARKOLIVEGREEN color.
 *
 */
#define MLV_COLOR_DARKOLIVEGREEN MLV_rgba(85,107,47,255)

/** \~french 
 * Define the DARK_SEA_GREEN color.
 *
 */
#define MLV_COLOR_DARK_SEA_GREEN MLV_rgba(143,188,143,255)

/** \~french 
 * Define the DARKSEAGREEN color.
 *
 */
#define MLV_COLOR_DARKSEAGREEN MLV_rgba(143,188,143,255)

/** \~french 
 * Define the SEA_GREEN color.
 *
 */
#define MLV_COLOR_SEA_GREEN MLV_rgba(46,139,87,255)

/** \~french 
 * Define the SEAGREEN color.
 *
 */
#define MLV_COLOR_SEAGREEN MLV_rgba(46,139,87,255)

/** \~french 
 * Define the MEDIUM_SEA_GREEN color.
 *
 */
#define MLV_COLOR_MEDIUM_SEA_GREEN MLV_rgba(60,179,113,255)

/** \~french 
 * Define the MEDIUMSEAGREEN color.
 *
 */
#define MLV_COLOR_MEDIUMSEAGREEN MLV_rgba(60,179,113,255)

/** \~french 
 * Define the LIGHT_SEA_GREEN color.
 *
 */
#define MLV_COLOR_LIGHT_SEA_GREEN MLV_rgba(32,178,170,255)

/** \~french 
 * Define the LIGHTSEAGREEN color.
 *
 */
#define MLV_COLOR_LIGHTSEAGREEN MLV_rgba(32,178,170,255)

/** \~french 
 * Define the PALE_GREEN color.
 *
 */
#define MLV_COLOR_PALE_GREEN MLV_rgba(152,251,152,255)

/** \~french 
 * Define the PALEGREEN color.
 *
 */
#define MLV_COLOR_PALEGREEN MLV_rgba(152,251,152,255)

/** \~french 
 * Define the SPRING_GREEN color.
 *
 */
#define MLV_COLOR_SPRING_GREEN MLV_rgba(0,255,127,255)

/** \~french 
 * Define the SPRINGGREEN color.
 *
 */
#define MLV_COLOR_SPRINGGREEN MLV_rgba(0,255,127,255)

/** \~french 
 * Define the LAWN_GREEN color.
 *
 */
#define MLV_COLOR_LAWN_GREEN MLV_rgba(124,252,0,255)

/** \~french 
 * Define the LAWNGREEN color.
 *
 */
#define MLV_COLOR_LAWNGREEN MLV_rgba(124,252,0,255)

/** \~french 
 * Define the GREEN color.
 *
 */
#define MLV_COLOR_GREEN MLV_rgba(0,255,0,255)

/** \~french 
 * Define the CHARTREUSE color.
 *
 */
#define MLV_COLOR_CHARTREUSE MLV_rgba(127,255,0,255)

/** \~french 
 * Define the MEDIUM_SPRING_GREEN color.
 *
 */
#define MLV_COLOR_MEDIUM_SPRING_GREEN MLV_rgba(0,250,154,255)

/** \~french 
 * Define the MEDIUMSPRINGGREEN color.
 *
 */
#define MLV_COLOR_MEDIUMSPRINGGREEN MLV_rgba(0,250,154,255)

/** \~french 
 * Define the GREEN_YELLOW color.
 *
 */
#define MLV_COLOR_GREEN_YELLOW MLV_rgba(173,255,47,255)

/** \~french 
 * Define the GREENYELLOW color.
 *
 */
#define MLV_COLOR_GREENYELLOW MLV_rgba(173,255,47,255)

/** \~french 
 * Define the LIME_GREEN color.
 *
 */
#define MLV_COLOR_LIME_GREEN MLV_rgba(50,205,50,255)

/** \~french 
 * Define the LIMEGREEN color.
 *
 */
#define MLV_COLOR_LIMEGREEN MLV_rgba(50,205,50,255)

/** \~french 
 * Define the YELLOW_GREEN color.
 *
 */
#define MLV_COLOR_YELLOW_GREEN MLV_rgba(154,205,50,255)

/** \~french 
 * Define the YELLOWGREEN color.
 *
 */
#define MLV_COLOR_YELLOWGREEN MLV_rgba(154,205,50,255)

/** \~french 
 * Define the FOREST_GREEN color.
 *
 */
#define MLV_COLOR_FOREST_GREEN MLV_rgba(34,139,34,255)

/** \~french 
 * Define the FORESTGREEN color.
 *
 */
#define MLV_COLOR_FORESTGREEN MLV_rgba(34,139,34,255)

/** \~french 
 * Define the OLIVE_DRAB color.
 *
 */
#define MLV_COLOR_OLIVE_DRAB MLV_rgba(107,142,35,255)

/** \~french 
 * Define the OLIVEDRAB color.
 *
 */
#define MLV_COLOR_OLIVEDRAB MLV_rgba(107,142,35,255)

/** \~french 
 * Define the DARK_KHAKI color.
 *
 */
#define MLV_COLOR_DARK_KHAKI MLV_rgba(189,183,107,255)

/** \~french 
 * Define the DARKKHAKI color.
 *
 */
#define MLV_COLOR_DARKKHAKI MLV_rgba(189,183,107,255)

/** \~french 
 * Define the KHAKI color.
 *
 */
#define MLV_COLOR_KHAKI MLV_rgba(240,230,140,255)

/** \~french 
 * Define the PALE_GOLDENROD color.
 *
 */
#define MLV_COLOR_PALE_GOLDENROD MLV_rgba(238,232,170,255)

/** \~french 
 * Define the PALEGOLDENROD color.
 *
 */
#define MLV_COLOR_PALEGOLDENROD MLV_rgba(238,232,170,255)

/** \~french 
 * Define the LIGHT_GOLDENROD_YELLOW color.
 *
 */
#define MLV_COLOR_LIGHT_GOLDENROD_YELLOW MLV_rgba(250,250,210,255)

/** \~french 
 * Define the LIGHTGOLDENRODYELLOW color.
 *
 */
#define MLV_COLOR_LIGHTGOLDENRODYELLOW MLV_rgba(250,250,210,255)

/** \~french 
 * Define the LIGHT_YELLOW color.
 *
 */
#define MLV_COLOR_LIGHT_YELLOW MLV_rgba(255,255,224,255)

/** \~french 
 * Define the LIGHTYELLOW color.
 *
 */
#define MLV_COLOR_LIGHTYELLOW MLV_rgba(255,255,224,255)

/** \~french 
 * Define the YELLOW color.
 *
 */
#define MLV_COLOR_YELLOW MLV_rgba(255,255,0,255)

/** \~french 
 * Define the GOLD color.
 *
 */
#define MLV_COLOR_GOLD MLV_rgba(255,215,0,255)

/** \~french 
 * Define the LIGHT_GOLDENROD color.
 *
 */
#define MLV_COLOR_LIGHT_GOLDENROD MLV_rgba(238,221,130,255)

/** \~french 
 * Define the LIGHTGOLDENROD color.
 *
 */
#define MLV_COLOR_LIGHTGOLDENROD MLV_rgba(238,221,130,255)

/** \~french 
 * Define the GOLDENROD color.
 *
 */
#define MLV_COLOR_GOLDENROD MLV_rgba(218,165,32,255)

/** \~french 
 * Define the DARK_GOLDENROD color.
 *
 */
#define MLV_COLOR_DARK_GOLDENROD MLV_rgba(184,134,11,255)

/** \~french 
 * Define the DARKGOLDENROD color.
 *
 */
#define MLV_COLOR_DARKGOLDENROD MLV_rgba(184,134,11,255)

/** \~french 
 * Define the ROSY_BROWN color.
 *
 */
#define MLV_COLOR_ROSY_BROWN MLV_rgba(188,143,143,255)

/** \~french 
 * Define the ROSYBROWN color.
 *
 */
#define MLV_COLOR_ROSYBROWN MLV_rgba(188,143,143,255)

/** \~french 
 * Define the INDIAN_RED color.
 *
 */
#define MLV_COLOR_INDIAN_RED MLV_rgba(205,92,92,255)

/** \~french 
 * Define the INDIANRED color.
 *
 */
#define MLV_COLOR_INDIANRED MLV_rgba(205,92,92,255)

/** \~french 
 * Define the SADDLE_BROWN color.
 *
 */
#define MLV_COLOR_SADDLE_BROWN MLV_rgba(139,69,19,255)

/** \~french 
 * Define the SADDLEBROWN color.
 *
 */
#define MLV_COLOR_SADDLEBROWN MLV_rgba(139,69,19,255)

/** \~french 
 * Define the SIENNA color.
 *
 */
#define MLV_COLOR_SIENNA MLV_rgba(160,82,45,255)

/** \~french 
 * Define the PERU color.
 *
 */
#define MLV_COLOR_PERU MLV_rgba(205,133,63,255)

/** \~french 
 * Define the BURLYWOOD color.
 *
 */
#define MLV_COLOR_BURLYWOOD MLV_rgba(222,184,135,255)

/** \~french 
 * Define the BEIGE color.
 *
 */
#define MLV_COLOR_BEIGE MLV_rgba(245,245,220,255)

/** \~french 
 * Define the WHEAT color.
 *
 */
#define MLV_COLOR_WHEAT MLV_rgba(245,222,179,255)

/** \~french 
 * Define the SANDY_BROWN color.
 *
 */
#define MLV_COLOR_SANDY_BROWN MLV_rgba(244,164,96,255)

/** \~french 
 * Define the SANDYBROWN color.
 *
 */
#define MLV_COLOR_SANDYBROWN MLV_rgba(244,164,96,255)

/** \~french 
 * Define the TAN color.
 *
 */
#define MLV_COLOR_TAN MLV_rgba(210,180,140,255)

/** \~french 
 * Define the CHOCOLATE color.
 *
 */
#define MLV_COLOR_CHOCOLATE MLV_rgba(210,105,30,255)

/** \~french 
 * Define the FIREBRICK color.
 *
 */
#define MLV_COLOR_FIREBRICK MLV_rgba(178,34,34,255)

/** \~french 
 * Define the BROWN color.
 *
 */
#define MLV_COLOR_BROWN MLV_rgba(165,42,42,255)

/** \~french 
 * Define the DARK_SALMON color.
 *
 */
#define MLV_COLOR_DARK_SALMON MLV_rgba(233,150,122,255)

/** \~french 
 * Define the DARKSALMON color.
 *
 */
#define MLV_COLOR_DARKSALMON MLV_rgba(233,150,122,255)

/** \~french 
 * Define the SALMON color.
 *
 */
#define MLV_COLOR_SALMON MLV_rgba(250,128,114,255)

/** \~french 
 * Define the LIGHT_SALMON color.
 *
 */
#define MLV_COLOR_LIGHT_SALMON MLV_rgba(255,160,122,255)

/** \~french 
 * Define the LIGHTSALMON color.
 *
 */
#define MLV_COLOR_LIGHTSALMON MLV_rgba(255,160,122,255)

/** \~french 
 * Define the ORANGE color.
 *
 */
#define MLV_COLOR_ORANGE MLV_rgba(255,165,0,255)

/** \~french 
 * Define the DARK_ORANGE color.
 *
 */
#define MLV_COLOR_DARK_ORANGE MLV_rgba(255,140,0,255)

/** \~french 
 * Define the DARKORANGE color.
 *
 */
#define MLV_COLOR_DARKORANGE MLV_rgba(255,140,0,255)

/** \~french 
 * Define the CORAL color.
 *
 */
#define MLV_COLOR_CORAL MLV_rgba(255,127,80,255)

/** \~french 
 * Define the LIGHT_CORAL color.
 *
 */
#define MLV_COLOR_LIGHT_CORAL MLV_rgba(240,128,128,255)

/** \~french 
 * Define the LIGHTCORAL color.
 *
 */
#define MLV_COLOR_LIGHTCORAL MLV_rgba(240,128,128,255)

/** \~french 
 * Define the TOMATO color.
 *
 */
#define MLV_COLOR_TOMATO MLV_rgba(255,99,71,255)

/** \~french 
 * Define the ORANGE_RED color.
 *
 */
#define MLV_COLOR_ORANGE_RED MLV_rgba(255,69,0,255)

/** \~french 
 * Define the ORANGERED color.
 *
 */
#define MLV_COLOR_ORANGERED MLV_rgba(255,69,0,255)

/** \~french 
 * Define the RED color.
 *
 */
#define MLV_COLOR_RED MLV_rgba(255,0,0,255)

/** \~french 
 * Define the HOT_PINK color.
 *
 */
#define MLV_COLOR_HOT_PINK MLV_rgba(255,105,180,255)

/** \~french 
 * Define the HOTPINK color.
 *
 */
#define MLV_COLOR_HOTPINK MLV_rgba(255,105,180,255)

/** \~french 
 * Define the DEEP_PINK color.
 *
 */
#define MLV_COLOR_DEEP_PINK MLV_rgba(255,20,147,255)

/** \~french 
 * Define the DEEPPINK color.
 *
 */
#define MLV_COLOR_DEEPPINK MLV_rgba(255,20,147,255)

/** \~french 
 * Define the PINK color.
 *
 */
#define MLV_COLOR_PINK MLV_rgba(255,192,203,255)

/** \~french 
 * Define the LIGHT_PINK color.
 *
 */
#define MLV_COLOR_LIGHT_PINK MLV_rgba(255,182,193,255)

/** \~french 
 * Define the LIGHTPINK color.
 *
 */
#define MLV_COLOR_LIGHTPINK MLV_rgba(255,182,193,255)

/** \~french 
 * Define the PALE_VIOLET_RED color.
 *
 */
#define MLV_COLOR_PALE_VIOLET_RED MLV_rgba(219,112,147,255)

/** \~french 
 * Define the PALEVIOLETRED color.
 *
 */
#define MLV_COLOR_PALEVIOLETRED MLV_rgba(219,112,147,255)

/** \~french 
 * Define the MAROON color.
 *
 */
#define MLV_COLOR_MAROON MLV_rgba(176,48,96,255)

/** \~french 
 * Define the MEDIUM_VIOLET_RED color.
 *
 */
#define MLV_COLOR_MEDIUM_VIOLET_RED MLV_rgba(199,21,133,255)

/** \~french 
 * Define the MEDIUMVIOLETRED color.
 *
 */
#define MLV_COLOR_MEDIUMVIOLETRED MLV_rgba(199,21,133,255)

/** \~french 
 * Define the VIOLET_RED color.
 *
 */
#define MLV_COLOR_VIOLET_RED MLV_rgba(208,32,144,255)

/** \~french 
 * Define the VIOLETRED color.
 *
 */
#define MLV_COLOR_VIOLETRED MLV_rgba(208,32,144,255)

/** \~french 
 * Define the MAGENTA color.
 *
 */
#define MLV_COLOR_MAGENTA MLV_rgba(255,0,255,255)

/** \~french 
 * Define the VIOLET color.
 *
 */
#define MLV_COLOR_VIOLET MLV_rgba(238,130,238,255)

/** \~french 
 * Define the PLUM color.
 *
 */
#define MLV_COLOR_PLUM MLV_rgba(221,160,221,255)

/** \~french 
 * Define the ORCHID color.
 *
 */
#define MLV_COLOR_ORCHID MLV_rgba(218,112,214,255)

/** \~french 
 * Define the MEDIUM_ORCHID color.
 *
 */
#define MLV_COLOR_MEDIUM_ORCHID MLV_rgba(186,85,211,255)

/** \~french 
 * Define the MEDIUMORCHID color.
 *
 */
#define MLV_COLOR_MEDIUMORCHID MLV_rgba(186,85,211,255)

/** \~french 
 * Define the DARK_ORCHID color.
 *
 */
#define MLV_COLOR_DARK_ORCHID MLV_rgba(153,50,204,255)

/** \~french 
 * Define the DARKORCHID color.
 *
 */
#define MLV_COLOR_DARKORCHID MLV_rgba(153,50,204,255)

/** \~french 
 * Define the DARK_VIOLET color.
 *
 */
#define MLV_COLOR_DARK_VIOLET MLV_rgba(148,0,211,255)

/** \~french 
 * Define the DARKVIOLET color.
 *
 */
#define MLV_COLOR_DARKVIOLET MLV_rgba(148,0,211,255)

/** \~french 
 * Define the BLUE_VIOLET color.
 *
 */
#define MLV_COLOR_BLUE_VIOLET MLV_rgba(138,43,226,255)

/** \~french 
 * Define the BLUEVIOLET color.
 *
 */
#define MLV_COLOR_BLUEVIOLET MLV_rgba(138,43,226,255)

/** \~french 
 * Define the PURPLE color.
 *
 */
#define MLV_COLOR_PURPLE MLV_rgba(160,32,240,255)

/** \~french 
 * Define the MEDIUM_PURPLE color.
 *
 */
#define MLV_COLOR_MEDIUM_PURPLE MLV_rgba(147,112,219,255)

/** \~french 
 * Define the MEDIUMPURPLE color.
 *
 */
#define MLV_COLOR_MEDIUMPURPLE MLV_rgba(147,112,219,255)

/** \~french 
 * Define the THISTLE color.
 *
 */
#define MLV_COLOR_THISTLE MLV_rgba(216,191,216,255)

/** \~french 
 * Define the SNOW1 color.
 *
 */
#define MLV_COLOR_SNOW1 MLV_rgba(255,250,250,255)

/** \~french 
 * Define the SNOW2 color.
 *
 */
#define MLV_COLOR_SNOW2 MLV_rgba(238,233,233,255)

/** \~french 
 * Define the SNOW3 color.
 *
 */
#define MLV_COLOR_SNOW3 MLV_rgba(205,201,201,255)

/** \~french 
 * Define the SNOW4 color.
 *
 */
#define MLV_COLOR_SNOW4 MLV_rgba(139,137,137,255)

/** \~french 
 * Define the SEASHELL1 color.
 *
 */
#define MLV_COLOR_SEASHELL1 MLV_rgba(255,245,238,255)

/** \~french 
 * Define the SEASHELL2 color.
 *
 */
#define MLV_COLOR_SEASHELL2 MLV_rgba(238,229,222,255)

/** \~french 
 * Define the SEASHELL3 color.
 *
 */
#define MLV_COLOR_SEASHELL3 MLV_rgba(205,197,191,255)

/** \~french 
 * Define the SEASHELL4 color.
 *
 */
#define MLV_COLOR_SEASHELL4 MLV_rgba(139,134,130,255)

/** \~french 
 * Define the ANTIQUEWHITE1 color.
 *
 */
#define MLV_COLOR_ANTIQUEWHITE1 MLV_rgba(255,239,219,255)

/** \~french 
 * Define the ANTIQUEWHITE2 color.
 *
 */
#define MLV_COLOR_ANTIQUEWHITE2 MLV_rgba(238,223,204,255)

/** \~french 
 * Define the ANTIQUEWHITE3 color.
 *
 */
#define MLV_COLOR_ANTIQUEWHITE3 MLV_rgba(205,192,176,255)

/** \~french 
 * Define the ANTIQUEWHITE4 color.
 *
 */
#define MLV_COLOR_ANTIQUEWHITE4 MLV_rgba(139,131,120,255)

/** \~french 
 * Define the BISQUE1 color.
 *
 */
#define MLV_COLOR_BISQUE1 MLV_rgba(255,228,196,255)

/** \~french 
 * Define the BISQUE2 color.
 *
 */
#define MLV_COLOR_BISQUE2 MLV_rgba(238,213,183,255)

/** \~french 
 * Define the BISQUE3 color.
 *
 */
#define MLV_COLOR_BISQUE3 MLV_rgba(205,183,158,255)

/** \~french 
 * Define the BISQUE4 color.
 *
 */
#define MLV_COLOR_BISQUE4 MLV_rgba(139,125,107,255)

/** \~french 
 * Define the PEACHPUFF1 color.
 *
 */
#define MLV_COLOR_PEACHPUFF1 MLV_rgba(255,218,185,255)

/** \~french 
 * Define the PEACHPUFF2 color.
 *
 */
#define MLV_COLOR_PEACHPUFF2 MLV_rgba(238,203,173,255)

/** \~french 
 * Define the PEACHPUFF3 color.
 *
 */
#define MLV_COLOR_PEACHPUFF3 MLV_rgba(205,175,149,255)

/** \~french 
 * Define the PEACHPUFF4 color.
 *
 */
#define MLV_COLOR_PEACHPUFF4 MLV_rgba(139,119,101,255)

/** \~french 
 * Define the NAVAJOWHITE1 color.
 *
 */
#define MLV_COLOR_NAVAJOWHITE1 MLV_rgba(255,222,173,255)

/** \~french 
 * Define the NAVAJOWHITE2 color.
 *
 */
#define MLV_COLOR_NAVAJOWHITE2 MLV_rgba(238,207,161,255)

/** \~french 
 * Define the NAVAJOWHITE3 color.
 *
 */
#define MLV_COLOR_NAVAJOWHITE3 MLV_rgba(205,179,139,255)

/** \~french 
 * Define the NAVAJOWHITE4 color.
 *
 */
#define MLV_COLOR_NAVAJOWHITE4 MLV_rgba(139,121,94,255)

/** \~french 
 * Define the LEMONCHIFFON1 color.
 *
 */
#define MLV_COLOR_LEMONCHIFFON1 MLV_rgba(255,250,205,255)

/** \~french 
 * Define the LEMONCHIFFON2 color.
 *
 */
#define MLV_COLOR_LEMONCHIFFON2 MLV_rgba(238,233,191,255)

/** \~french 
 * Define the LEMONCHIFFON3 color.
 *
 */
#define MLV_COLOR_LEMONCHIFFON3 MLV_rgba(205,201,165,255)

/** \~french 
 * Define the LEMONCHIFFON4 color.
 *
 */
#define MLV_COLOR_LEMONCHIFFON4 MLV_rgba(139,137,112,255)

/** \~french 
 * Define the CORNSILK1 color.
 *
 */
#define MLV_COLOR_CORNSILK1 MLV_rgba(255,248,220,255)

/** \~french 
 * Define the CORNSILK2 color.
 *
 */
#define MLV_COLOR_CORNSILK2 MLV_rgba(238,232,205,255)

/** \~french 
 * Define the CORNSILK3 color.
 *
 */
#define MLV_COLOR_CORNSILK3 MLV_rgba(205,200,177,255)

/** \~french 
 * Define the CORNSILK4 color.
 *
 */
#define MLV_COLOR_CORNSILK4 MLV_rgba(139,136,120,255)

/** \~french 
 * Define the IVORY1 color.
 *
 */
#define MLV_COLOR_IVORY1 MLV_rgba(255,255,240,255)

/** \~french 
 * Define the IVORY2 color.
 *
 */
#define MLV_COLOR_IVORY2 MLV_rgba(238,238,224,255)

/** \~french 
 * Define the IVORY3 color.
 *
 */
#define MLV_COLOR_IVORY3 MLV_rgba(205,205,193,255)

/** \~french 
 * Define the IVORY4 color.
 *
 */
#define MLV_COLOR_IVORY4 MLV_rgba(139,139,131,255)

/** \~french 
 * Define the HONEYDEW1 color.
 *
 */
#define MLV_COLOR_HONEYDEW1 MLV_rgba(240,255,240,255)

/** \~french 
 * Define the HONEYDEW2 color.
 *
 */
#define MLV_COLOR_HONEYDEW2 MLV_rgba(224,238,224,255)

/** \~french 
 * Define the HONEYDEW3 color.
 *
 */
#define MLV_COLOR_HONEYDEW3 MLV_rgba(193,205,193,255)

/** \~french 
 * Define the HONEYDEW4 color.
 *
 */
#define MLV_COLOR_HONEYDEW4 MLV_rgba(131,139,131,255)

/** \~french 
 * Define the LAVENDERBLUSH1 color.
 *
 */
#define MLV_COLOR_LAVENDERBLUSH1 MLV_rgba(255,240,245,255)

/** \~french 
 * Define the LAVENDERBLUSH2 color.
 *
 */
#define MLV_COLOR_LAVENDERBLUSH2 MLV_rgba(238,224,229,255)

/** \~french 
 * Define the LAVENDERBLUSH3 color.
 *
 */
#define MLV_COLOR_LAVENDERBLUSH3 MLV_rgba(205,193,197,255)

/** \~french 
 * Define the LAVENDERBLUSH4 color.
 *
 */
#define MLV_COLOR_LAVENDERBLUSH4 MLV_rgba(139,131,134,255)

/** \~french 
 * Define the MISTYROSE1 color.
 *
 */
#define MLV_COLOR_MISTYROSE1 MLV_rgba(255,228,225,255)

/** \~french 
 * Define the MISTYROSE2 color.
 *
 */
#define MLV_COLOR_MISTYROSE2 MLV_rgba(238,213,210,255)

/** \~french 
 * Define the MISTYROSE3 color.
 *
 */
#define MLV_COLOR_MISTYROSE3 MLV_rgba(205,183,181,255)

/** \~french 
 * Define the MISTYROSE4 color.
 *
 */
#define MLV_COLOR_MISTYROSE4 MLV_rgba(139,125,123,255)

/** \~french 
 * Define the AZURE1 color.
 *
 */
#define MLV_COLOR_AZURE1 MLV_rgba(240,255,255,255)

/** \~french 
 * Define the AZURE2 color.
 *
 */
#define MLV_COLOR_AZURE2 MLV_rgba(224,238,238,255)

/** \~french 
 * Define the AZURE3 color.
 *
 */
#define MLV_COLOR_AZURE3 MLV_rgba(193,205,205,255)

/** \~french 
 * Define the AZURE4 color.
 *
 */
#define MLV_COLOR_AZURE4 MLV_rgba(131,139,139,255)

/** \~french 
 * Define the SLATEBLUE1 color.
 *
 */
#define MLV_COLOR_SLATEBLUE1 MLV_rgba(131,111,255,255)

/** \~french 
 * Define the SLATEBLUE2 color.
 *
 */
#define MLV_COLOR_SLATEBLUE2 MLV_rgba(122,103,238,255)

/** \~french 
 * Define the SLATEBLUE3 color.
 *
 */
#define MLV_COLOR_SLATEBLUE3 MLV_rgba(105,89,205,255)

/** \~french 
 * Define the SLATEBLUE4 color.
 *
 */
#define MLV_COLOR_SLATEBLUE4 MLV_rgba(71,60,139,255)

/** \~french 
 * Define the ROYALBLUE1 color.
 *
 */
#define MLV_COLOR_ROYALBLUE1 MLV_rgba(72,118,255,255)

/** \~french 
 * Define the ROYALBLUE2 color.
 *
 */
#define MLV_COLOR_ROYALBLUE2 MLV_rgba(67,110,238,255)

/** \~french 
 * Define the ROYALBLUE3 color.
 *
 */
#define MLV_COLOR_ROYALBLUE3 MLV_rgba(58,95,205,255)

/** \~french 
 * Define the ROYALBLUE4 color.
 *
 */
#define MLV_COLOR_ROYALBLUE4 MLV_rgba(39,64,139,255)

/** \~french 
 * Define the BLUE1 color.
 *
 */
#define MLV_COLOR_BLUE1 MLV_rgba(0,0,255,255)

/** \~french 
 * Define the BLUE2 color.
 *
 */
#define MLV_COLOR_BLUE2 MLV_rgba(0,0,238,255)

/** \~french 
 * Define the BLUE3 color.
 *
 */
#define MLV_COLOR_BLUE3 MLV_rgba(0,0,205,255)

/** \~french 
 * Define the BLUE4 color.
 *
 */
#define MLV_COLOR_BLUE4 MLV_rgba(0,0,139,255)

/** \~french 
 * Define the DODGERBLUE1 color.
 *
 */
#define MLV_COLOR_DODGERBLUE1 MLV_rgba(30,144,255,255)

/** \~french 
 * Define the DODGERBLUE2 color.
 *
 */
#define MLV_COLOR_DODGERBLUE2 MLV_rgba(28,134,238,255)

/** \~french 
 * Define the DODGERBLUE3 color.
 *
 */
#define MLV_COLOR_DODGERBLUE3 MLV_rgba(24,116,205,255)

/** \~french 
 * Define the DODGERBLUE4 color.
 *
 */
#define MLV_COLOR_DODGERBLUE4 MLV_rgba(16,78,139,255)

/** \~french 
 * Define the STEELBLUE1 color.
 *
 */
#define MLV_COLOR_STEELBLUE1 MLV_rgba(99,184,255,255)

/** \~french 
 * Define the STEELBLUE2 color.
 *
 */
#define MLV_COLOR_STEELBLUE2 MLV_rgba(92,172,238,255)

/** \~french 
 * Define the STEELBLUE3 color.
 *
 */
#define MLV_COLOR_STEELBLUE3 MLV_rgba(79,148,205,255)

/** \~french 
 * Define the STEELBLUE4 color.
 *
 */
#define MLV_COLOR_STEELBLUE4 MLV_rgba(54,100,139,255)

/** \~french 
 * Define the DEEPSKYBLUE1 color.
 *
 */
#define MLV_COLOR_DEEPSKYBLUE1 MLV_rgba(0,191,255,255)

/** \~french 
 * Define the DEEPSKYBLUE2 color.
 *
 */
#define MLV_COLOR_DEEPSKYBLUE2 MLV_rgba(0,178,238,255)

/** \~french 
 * Define the DEEPSKYBLUE3 color.
 *
 */
#define MLV_COLOR_DEEPSKYBLUE3 MLV_rgba(0,154,205,255)

/** \~french 
 * Define the DEEPSKYBLUE4 color.
 *
 */
#define MLV_COLOR_DEEPSKYBLUE4 MLV_rgba(0,104,139,255)

/** \~french 
 * Define the SKYBLUE1 color.
 *
 */
#define MLV_COLOR_SKYBLUE1 MLV_rgba(135,206,255,255)

/** \~french 
 * Define the SKYBLUE2 color.
 *
 */
#define MLV_COLOR_SKYBLUE2 MLV_rgba(126,192,238,255)

/** \~french 
 * Define the SKYBLUE3 color.
 *
 */
#define MLV_COLOR_SKYBLUE3 MLV_rgba(108,166,205,255)

/** \~french 
 * Define the SKYBLUE4 color.
 *
 */
#define MLV_COLOR_SKYBLUE4 MLV_rgba(74,112,139,255)

/** \~french 
 * Define the LIGHTSKYBLUE1 color.
 *
 */
#define MLV_COLOR_LIGHTSKYBLUE1 MLV_rgba(176,226,255,255)

/** \~french 
 * Define the LIGHTSKYBLUE2 color.
 *
 */
#define MLV_COLOR_LIGHTSKYBLUE2 MLV_rgba(164,211,238,255)

/** \~french 
 * Define the LIGHTSKYBLUE3 color.
 *
 */
#define MLV_COLOR_LIGHTSKYBLUE3 MLV_rgba(141,182,205,255)

/** \~french 
 * Define the LIGHTSKYBLUE4 color.
 *
 */
#define MLV_COLOR_LIGHTSKYBLUE4 MLV_rgba(96,123,139,255)

/** \~french 
 * Define the SLATEGRAY1 color.
 *
 */
#define MLV_COLOR_SLATEGRAY1 MLV_rgba(198,226,255,255)

/** \~french 
 * Define the SLATEGRAY2 color.
 *
 */
#define MLV_COLOR_SLATEGRAY2 MLV_rgba(185,211,238,255)

/** \~french 
 * Define the SLATEGRAY3 color.
 *
 */
#define MLV_COLOR_SLATEGRAY3 MLV_rgba(159,182,205,255)

/** \~french 
 * Define the SLATEGRAY4 color.
 *
 */
#define MLV_COLOR_SLATEGRAY4 MLV_rgba(108,123,139,255)

/** \~french 
 * Define the LIGHTSTEELBLUE1 color.
 *
 */
#define MLV_COLOR_LIGHTSTEELBLUE1 MLV_rgba(202,225,255,255)

/** \~french 
 * Define the LIGHTSTEELBLUE2 color.
 *
 */
#define MLV_COLOR_LIGHTSTEELBLUE2 MLV_rgba(188,210,238,255)

/** \~french 
 * Define the LIGHTSTEELBLUE3 color.
 *
 */
#define MLV_COLOR_LIGHTSTEELBLUE3 MLV_rgba(162,181,205,255)

/** \~french 
 * Define the LIGHTSTEELBLUE4 color.
 *
 */
#define MLV_COLOR_LIGHTSTEELBLUE4 MLV_rgba(110,123,139,255)

/** \~french 
 * Define the LIGHTBLUE1 color.
 *
 */
#define MLV_COLOR_LIGHTBLUE1 MLV_rgba(191,239,255,255)

/** \~french 
 * Define the LIGHTBLUE2 color.
 *
 */
#define MLV_COLOR_LIGHTBLUE2 MLV_rgba(178,223,238,255)

/** \~french 
 * Define the LIGHTBLUE3 color.
 *
 */
#define MLV_COLOR_LIGHTBLUE3 MLV_rgba(154,192,205,255)

/** \~french 
 * Define the LIGHTBLUE4 color.
 *
 */
#define MLV_COLOR_LIGHTBLUE4 MLV_rgba(104,131,139,255)

/** \~french 
 * Define the LIGHTCYAN1 color.
 *
 */
#define MLV_COLOR_LIGHTCYAN1 MLV_rgba(224,255,255,255)

/** \~french 
 * Define the LIGHTCYAN2 color.
 *
 */
#define MLV_COLOR_LIGHTCYAN2 MLV_rgba(209,238,238,255)

/** \~french 
 * Define the LIGHTCYAN3 color.
 *
 */
#define MLV_COLOR_LIGHTCYAN3 MLV_rgba(180,205,205,255)

/** \~french 
 * Define the LIGHTCYAN4 color.
 *
 */
#define MLV_COLOR_LIGHTCYAN4 MLV_rgba(122,139,139,255)

/** \~french 
 * Define the PALETURQUOISE1 color.
 *
 */
#define MLV_COLOR_PALETURQUOISE1 MLV_rgba(187,255,255,255)

/** \~french 
 * Define the PALETURQUOISE2 color.
 *
 */
#define MLV_COLOR_PALETURQUOISE2 MLV_rgba(174,238,238,255)

/** \~french 
 * Define the PALETURQUOISE3 color.
 *
 */
#define MLV_COLOR_PALETURQUOISE3 MLV_rgba(150,205,205,255)

/** \~french 
 * Define the PALETURQUOISE4 color.
 *
 */
#define MLV_COLOR_PALETURQUOISE4 MLV_rgba(102,139,139,255)

/** \~french 
 * Define the CADETBLUE1 color.
 *
 */
#define MLV_COLOR_CADETBLUE1 MLV_rgba(152,245,255,255)

/** \~french 
 * Define the CADETBLUE2 color.
 *
 */
#define MLV_COLOR_CADETBLUE2 MLV_rgba(142,229,238,255)

/** \~french 
 * Define the CADETBLUE3 color.
 *
 */
#define MLV_COLOR_CADETBLUE3 MLV_rgba(122,197,205,255)

/** \~french 
 * Define the CADETBLUE4 color.
 *
 */
#define MLV_COLOR_CADETBLUE4 MLV_rgba(83,134,139,255)

/** \~french 
 * Define the TURQUOISE1 color.
 *
 */
#define MLV_COLOR_TURQUOISE1 MLV_rgba(0,245,255,255)

/** \~french 
 * Define the TURQUOISE2 color.
 *
 */
#define MLV_COLOR_TURQUOISE2 MLV_rgba(0,229,238,255)

/** \~french 
 * Define the TURQUOISE3 color.
 *
 */
#define MLV_COLOR_TURQUOISE3 MLV_rgba(0,197,205,255)

/** \~french 
 * Define the TURQUOISE4 color.
 *
 */
#define MLV_COLOR_TURQUOISE4 MLV_rgba(0,134,139,255)

/** \~french 
 * Define the CYAN1 color.
 *
 */
#define MLV_COLOR_CYAN1 MLV_rgba(0,255,255,255)

/** \~french 
 * Define the CYAN2 color.
 *
 */
#define MLV_COLOR_CYAN2 MLV_rgba(0,238,238,255)

/** \~french 
 * Define the CYAN3 color.
 *
 */
#define MLV_COLOR_CYAN3 MLV_rgba(0,205,205,255)

/** \~french 
 * Define the CYAN4 color.
 *
 */
#define MLV_COLOR_CYAN4 MLV_rgba(0,139,139,255)

/** \~french 
 * Define the DARKSLATEGRAY1 color.
 *
 */
#define MLV_COLOR_DARKSLATEGRAY1 MLV_rgba(151,255,255,255)

/** \~french 
 * Define the DARKSLATEGRAY2 color.
 *
 */
#define MLV_COLOR_DARKSLATEGRAY2 MLV_rgba(141,238,238,255)

/** \~french 
 * Define the DARKSLATEGRAY3 color.
 *
 */
#define MLV_COLOR_DARKSLATEGRAY3 MLV_rgba(121,205,205,255)

/** \~french 
 * Define the DARKSLATEGRAY4 color.
 *
 */
#define MLV_COLOR_DARKSLATEGRAY4 MLV_rgba(82,139,139,255)

/** \~french 
 * Define the AQUAMARINE1 color.
 *
 */
#define MLV_COLOR_AQUAMARINE1 MLV_rgba(127,255,212,255)

/** \~french 
 * Define the AQUAMARINE2 color.
 *
 */
#define MLV_COLOR_AQUAMARINE2 MLV_rgba(118,238,198,255)

/** \~french 
 * Define the AQUAMARINE3 color.
 *
 */
#define MLV_COLOR_AQUAMARINE3 MLV_rgba(102,205,170,255)

/** \~french 
 * Define the AQUAMARINE4 color.
 *
 */
#define MLV_COLOR_AQUAMARINE4 MLV_rgba(69,139,116,255)

/** \~french 
 * Define the DARKSEAGREEN1 color.
 *
 */
#define MLV_COLOR_DARKSEAGREEN1 MLV_rgba(193,255,193,255)

/** \~french 
 * Define the DARKSEAGREEN2 color.
 *
 */
#define MLV_COLOR_DARKSEAGREEN2 MLV_rgba(180,238,180,255)

/** \~french 
 * Define the DARKSEAGREEN3 color.
 *
 */
#define MLV_COLOR_DARKSEAGREEN3 MLV_rgba(155,205,155,255)

/** \~french 
 * Define the DARKSEAGREEN4 color.
 *
 */
#define MLV_COLOR_DARKSEAGREEN4 MLV_rgba(105,139,105,255)

/** \~french 
 * Define the SEAGREEN1 color.
 *
 */
#define MLV_COLOR_SEAGREEN1 MLV_rgba(84,255,159,255)

/** \~french 
 * Define the SEAGREEN2 color.
 *
 */
#define MLV_COLOR_SEAGREEN2 MLV_rgba(78,238,148,255)

/** \~french 
 * Define the SEAGREEN3 color.
 *
 */
#define MLV_COLOR_SEAGREEN3 MLV_rgba(67,205,128,255)

/** \~french 
 * Define the SEAGREEN4 color.
 *
 */
#define MLV_COLOR_SEAGREEN4 MLV_rgba(46,139,87,255)

/** \~french 
 * Define the PALEGREEN1 color.
 *
 */
#define MLV_COLOR_PALEGREEN1 MLV_rgba(154,255,154,255)

/** \~french 
 * Define the PALEGREEN2 color.
 *
 */
#define MLV_COLOR_PALEGREEN2 MLV_rgba(144,238,144,255)

/** \~french 
 * Define the PALEGREEN3 color.
 *
 */
#define MLV_COLOR_PALEGREEN3 MLV_rgba(124,205,124,255)

/** \~french 
 * Define the PALEGREEN4 color.
 *
 */
#define MLV_COLOR_PALEGREEN4 MLV_rgba(84,139,84,255)

/** \~french 
 * Define the SPRINGGREEN1 color.
 *
 */
#define MLV_COLOR_SPRINGGREEN1 MLV_rgba(0,255,127,255)

/** \~french 
 * Define the SPRINGGREEN2 color.
 *
 */
#define MLV_COLOR_SPRINGGREEN2 MLV_rgba(0,238,118,255)

/** \~french 
 * Define the SPRINGGREEN3 color.
 *
 */
#define MLV_COLOR_SPRINGGREEN3 MLV_rgba(0,205,102,255)

/** \~french 
 * Define the SPRINGGREEN4 color.
 *
 */
#define MLV_COLOR_SPRINGGREEN4 MLV_rgba(0,139,69,255)

/** \~french 
 * Define the GREEN1 color.
 *
 */
#define MLV_COLOR_GREEN1 MLV_rgba(0,255,0,255)

/** \~french 
 * Define the GREEN2 color.
 *
 */
#define MLV_COLOR_GREEN2 MLV_rgba(0,238,0,255)

/** \~french 
 * Define the GREEN3 color.
 *
 */
#define MLV_COLOR_GREEN3 MLV_rgba(0,205,0,255)

/** \~french 
 * Define the GREEN4 color.
 *
 */
#define MLV_COLOR_GREEN4 MLV_rgba(0,139,0,255)

/** \~french 
 * Define the CHARTREUSE1 color.
 *
 */
#define MLV_COLOR_CHARTREUSE1 MLV_rgba(127,255,0,255)

/** \~french 
 * Define the CHARTREUSE2 color.
 *
 */
#define MLV_COLOR_CHARTREUSE2 MLV_rgba(118,238,0,255)

/** \~french 
 * Define the CHARTREUSE3 color.
 *
 */
#define MLV_COLOR_CHARTREUSE3 MLV_rgba(102,205,0,255)

/** \~french 
 * Define the CHARTREUSE4 color.
 *
 */
#define MLV_COLOR_CHARTREUSE4 MLV_rgba(69,139,0,255)

/** \~french 
 * Define the OLIVEDRAB1 color.
 *
 */
#define MLV_COLOR_OLIVEDRAB1 MLV_rgba(192,255,62,255)

/** \~french 
 * Define the OLIVEDRAB2 color.
 *
 */
#define MLV_COLOR_OLIVEDRAB2 MLV_rgba(179,238,58,255)

/** \~french 
 * Define the OLIVEDRAB3 color.
 *
 */
#define MLV_COLOR_OLIVEDRAB3 MLV_rgba(154,205,50,255)

/** \~french 
 * Define the OLIVEDRAB4 color.
 *
 */
#define MLV_COLOR_OLIVEDRAB4 MLV_rgba(105,139,34,255)

/** \~french 
 * Define the DARKOLIVEGREEN1 color.
 *
 */
#define MLV_COLOR_DARKOLIVEGREEN1 MLV_rgba(202,255,112,255)

/** \~french 
 * Define the DARKOLIVEGREEN2 color.
 *
 */
#define MLV_COLOR_DARKOLIVEGREEN2 MLV_rgba(188,238,104,255)

/** \~french 
 * Define the DARKOLIVEGREEN3 color.
 *
 */
#define MLV_COLOR_DARKOLIVEGREEN3 MLV_rgba(162,205,90,255)

/** \~french 
 * Define the DARKOLIVEGREEN4 color.
 *
 */
#define MLV_COLOR_DARKOLIVEGREEN4 MLV_rgba(110,139,61,255)

/** \~french 
 * Define the KHAKI1 color.
 *
 */
#define MLV_COLOR_KHAKI1 MLV_rgba(255,246,143,255)

/** \~french 
 * Define the KHAKI2 color.
 *
 */
#define MLV_COLOR_KHAKI2 MLV_rgba(238,230,133,255)

/** \~french 
 * Define the KHAKI3 color.
 *
 */
#define MLV_COLOR_KHAKI3 MLV_rgba(205,198,115,255)

/** \~french 
 * Define the KHAKI4 color.
 *
 */
#define MLV_COLOR_KHAKI4 MLV_rgba(139,134,78,255)

/** \~french 
 * Define the LIGHTGOLDENROD1 color.
 *
 */
#define MLV_COLOR_LIGHTGOLDENROD1 MLV_rgba(255,236,139,255)

/** \~french 
 * Define the LIGHTGOLDENROD2 color.
 *
 */
#define MLV_COLOR_LIGHTGOLDENROD2 MLV_rgba(238,220,130,255)

/** \~french 
 * Define the LIGHTGOLDENROD3 color.
 *
 */
#define MLV_COLOR_LIGHTGOLDENROD3 MLV_rgba(205,190,112,255)

/** \~french 
 * Define the LIGHTGOLDENROD4 color.
 *
 */
#define MLV_COLOR_LIGHTGOLDENROD4 MLV_rgba(139,129,76,255)

/** \~french 
 * Define the LIGHTYELLOW1 color.
 *
 */
#define MLV_COLOR_LIGHTYELLOW1 MLV_rgba(255,255,224,255)

/** \~french 
 * Define the LIGHTYELLOW2 color.
 *
 */
#define MLV_COLOR_LIGHTYELLOW2 MLV_rgba(238,238,209,255)

/** \~french 
 * Define the LIGHTYELLOW3 color.
 *
 */
#define MLV_COLOR_LIGHTYELLOW3 MLV_rgba(205,205,180,255)

/** \~french 
 * Define the LIGHTYELLOW4 color.
 *
 */
#define MLV_COLOR_LIGHTYELLOW4 MLV_rgba(139,139,122,255)

/** \~french 
 * Define the YELLOW1 color.
 *
 */
#define MLV_COLOR_YELLOW1 MLV_rgba(255,255,0,255)

/** \~french 
 * Define the YELLOW2 color.
 *
 */
#define MLV_COLOR_YELLOW2 MLV_rgba(238,238,0,255)

/** \~french 
 * Define the YELLOW3 color.
 *
 */
#define MLV_COLOR_YELLOW3 MLV_rgba(205,205,0,255)

/** \~french 
 * Define the YELLOW4 color.
 *
 */
#define MLV_COLOR_YELLOW4 MLV_rgba(139,139,0,255)

/** \~french 
 * Define the GOLD1 color.
 *
 */
#define MLV_COLOR_GOLD1 MLV_rgba(255,215,0,255)

/** \~french 
 * Define the GOLD2 color.
 *
 */
#define MLV_COLOR_GOLD2 MLV_rgba(238,201,0,255)

/** \~french 
 * Define the GOLD3 color.
 *
 */
#define MLV_COLOR_GOLD3 MLV_rgba(205,173,0,255)

/** \~french 
 * Define the GOLD4 color.
 *
 */
#define MLV_COLOR_GOLD4 MLV_rgba(139,117,0,255)

/** \~french 
 * Define the GOLDENROD1 color.
 *
 */
#define MLV_COLOR_GOLDENROD1 MLV_rgba(255,193,37,255)

/** \~french 
 * Define the GOLDENROD2 color.
 *
 */
#define MLV_COLOR_GOLDENROD2 MLV_rgba(238,180,34,255)

/** \~french 
 * Define the GOLDENROD3 color.
 *
 */
#define MLV_COLOR_GOLDENROD3 MLV_rgba(205,155,29,255)

/** \~french 
 * Define the GOLDENROD4 color.
 *
 */
#define MLV_COLOR_GOLDENROD4 MLV_rgba(139,105,20,255)

/** \~french 
 * Define the DARKGOLDENROD1 color.
 *
 */
#define MLV_COLOR_DARKGOLDENROD1 MLV_rgba(255,185,15,255)

/** \~french 
 * Define the DARKGOLDENROD2 color.
 *
 */
#define MLV_COLOR_DARKGOLDENROD2 MLV_rgba(238,173,14,255)

/** \~french 
 * Define the DARKGOLDENROD3 color.
 *
 */
#define MLV_COLOR_DARKGOLDENROD3 MLV_rgba(205,149,12,255)

/** \~french 
 * Define the DARKGOLDENROD4 color.
 *
 */
#define MLV_COLOR_DARKGOLDENROD4 MLV_rgba(139,101,8,255)

/** \~french 
 * Define the ROSYBROWN1 color.
 *
 */
#define MLV_COLOR_ROSYBROWN1 MLV_rgba(255,193,193,255)

/** \~french 
 * Define the ROSYBROWN2 color.
 *
 */
#define MLV_COLOR_ROSYBROWN2 MLV_rgba(238,180,180,255)

/** \~french 
 * Define the ROSYBROWN3 color.
 *
 */
#define MLV_COLOR_ROSYBROWN3 MLV_rgba(205,155,155,255)

/** \~french 
 * Define the ROSYBROWN4 color.
 *
 */
#define MLV_COLOR_ROSYBROWN4 MLV_rgba(139,105,105,255)

/** \~french 
 * Define the INDIANRED1 color.
 *
 */
#define MLV_COLOR_INDIANRED1 MLV_rgba(255,106,106,255)

/** \~french 
 * Define the INDIANRED2 color.
 *
 */
#define MLV_COLOR_INDIANRED2 MLV_rgba(238,99,99,255)

/** \~french 
 * Define the INDIANRED3 color.
 *
 */
#define MLV_COLOR_INDIANRED3 MLV_rgba(205,85,85,255)

/** \~french 
 * Define the INDIANRED4 color.
 *
 */
#define MLV_COLOR_INDIANRED4 MLV_rgba(139,58,58,255)

/** \~french 
 * Define the SIENNA1 color.
 *
 */
#define MLV_COLOR_SIENNA1 MLV_rgba(255,130,71,255)

/** \~french 
 * Define the SIENNA2 color.
 *
 */
#define MLV_COLOR_SIENNA2 MLV_rgba(238,121,66,255)

/** \~french 
 * Define the SIENNA3 color.
 *
 */
#define MLV_COLOR_SIENNA3 MLV_rgba(205,104,57,255)

/** \~french 
 * Define the SIENNA4 color.
 *
 */
#define MLV_COLOR_SIENNA4 MLV_rgba(139,71,38,255)

/** \~french 
 * Define the BURLYWOOD1 color.
 *
 */
#define MLV_COLOR_BURLYWOOD1 MLV_rgba(255,211,155,255)

/** \~french 
 * Define the BURLYWOOD2 color.
 *
 */
#define MLV_COLOR_BURLYWOOD2 MLV_rgba(238,197,145,255)

/** \~french 
 * Define the BURLYWOOD3 color.
 *
 */
#define MLV_COLOR_BURLYWOOD3 MLV_rgba(205,170,125,255)

/** \~french 
 * Define the BURLYWOOD4 color.
 *
 */
#define MLV_COLOR_BURLYWOOD4 MLV_rgba(139,115,85,255)

/** \~french 
 * Define the WHEAT1 color.
 *
 */
#define MLV_COLOR_WHEAT1 MLV_rgba(255,231,186,255)

/** \~french 
 * Define the WHEAT2 color.
 *
 */
#define MLV_COLOR_WHEAT2 MLV_rgba(238,216,174,255)

/** \~french 
 * Define the WHEAT3 color.
 *
 */
#define MLV_COLOR_WHEAT3 MLV_rgba(205,186,150,255)

/** \~french 
 * Define the WHEAT4 color.
 *
 */
#define MLV_COLOR_WHEAT4 MLV_rgba(139,126,102,255)

/** \~french 
 * Define the TAN1 color.
 *
 */
#define MLV_COLOR_TAN1 MLV_rgba(255,165,79,255)

/** \~french 
 * Define the TAN2 color.
 *
 */
#define MLV_COLOR_TAN2 MLV_rgba(238,154,73,255)

/** \~french 
 * Define the TAN3 color.
 *
 */
#define MLV_COLOR_TAN3 MLV_rgba(205,133,63,255)

/** \~french 
 * Define the TAN4 color.
 *
 */
#define MLV_COLOR_TAN4 MLV_rgba(139,90,43,255)

/** \~french 
 * Define the CHOCOLATE1 color.
 *
 */
#define MLV_COLOR_CHOCOLATE1 MLV_rgba(255,127,36,255)

/** \~french 
 * Define the CHOCOLATE2 color.
 *
 */
#define MLV_COLOR_CHOCOLATE2 MLV_rgba(238,118,33,255)

/** \~french 
 * Define the CHOCOLATE3 color.
 *
 */
#define MLV_COLOR_CHOCOLATE3 MLV_rgba(205,102,29,255)

/** \~french 
 * Define the CHOCOLATE4 color.
 *
 */
#define MLV_COLOR_CHOCOLATE4 MLV_rgba(139,69,19,255)

/** \~french 
 * Define the FIREBRICK1 color.
 *
 */
#define MLV_COLOR_FIREBRICK1 MLV_rgba(255,48,48,255)

/** \~french 
 * Define the FIREBRICK2 color.
 *
 */
#define MLV_COLOR_FIREBRICK2 MLV_rgba(238,44,44,255)

/** \~french 
 * Define the FIREBRICK3 color.
 *
 */
#define MLV_COLOR_FIREBRICK3 MLV_rgba(205,38,38,255)

/** \~french 
 * Define the FIREBRICK4 color.
 *
 */
#define MLV_COLOR_FIREBRICK4 MLV_rgba(139,26,26,255)

/** \~french 
 * Define the BROWN1 color.
 *
 */
#define MLV_COLOR_BROWN1 MLV_rgba(255,64,64,255)

/** \~french 
 * Define the BROWN2 color.
 *
 */
#define MLV_COLOR_BROWN2 MLV_rgba(238,59,59,255)

/** \~french 
 * Define the BROWN3 color.
 *
 */
#define MLV_COLOR_BROWN3 MLV_rgba(205,51,51,255)

/** \~french 
 * Define the BROWN4 color.
 *
 */
#define MLV_COLOR_BROWN4 MLV_rgba(139,35,35,255)

/** \~french 
 * Define the SALMON1 color.
 *
 */
#define MLV_COLOR_SALMON1 MLV_rgba(255,140,105,255)

/** \~french 
 * Define the SALMON2 color.
 *
 */
#define MLV_COLOR_SALMON2 MLV_rgba(238,130,98,255)

/** \~french 
 * Define the SALMON3 color.
 *
 */
#define MLV_COLOR_SALMON3 MLV_rgba(205,112,84,255)

/** \~french 
 * Define the SALMON4 color.
 *
 */
#define MLV_COLOR_SALMON4 MLV_rgba(139,76,57,255)

/** \~french 
 * Define the LIGHTSALMON1 color.
 *
 */
#define MLV_COLOR_LIGHTSALMON1 MLV_rgba(255,160,122,255)

/** \~french 
 * Define the LIGHTSALMON2 color.
 *
 */
#define MLV_COLOR_LIGHTSALMON2 MLV_rgba(238,149,114,255)

/** \~french 
 * Define the LIGHTSALMON3 color.
 *
 */
#define MLV_COLOR_LIGHTSALMON3 MLV_rgba(205,129,98,255)

/** \~french 
 * Define the LIGHTSALMON4 color.
 *
 */
#define MLV_COLOR_LIGHTSALMON4 MLV_rgba(139,87,66,255)

/** \~french 
 * Define the ORANGE1 color.
 *
 */
#define MLV_COLOR_ORANGE1 MLV_rgba(255,165,0,255)

/** \~french 
 * Define the ORANGE2 color.
 *
 */
#define MLV_COLOR_ORANGE2 MLV_rgba(238,154,0,255)

/** \~french 
 * Define the ORANGE3 color.
 *
 */
#define MLV_COLOR_ORANGE3 MLV_rgba(205,133,0,255)

/** \~french 
 * Define the ORANGE4 color.
 *
 */
#define MLV_COLOR_ORANGE4 MLV_rgba(139,90,0,255)

/** \~french 
 * Define the DARKORANGE1 color.
 *
 */
#define MLV_COLOR_DARKORANGE1 MLV_rgba(255,127,0,255)

/** \~french 
 * Define the DARKORANGE2 color.
 *
 */
#define MLV_COLOR_DARKORANGE2 MLV_rgba(238,118,0,255)

/** \~french 
 * Define the DARKORANGE3 color.
 *
 */
#define MLV_COLOR_DARKORANGE3 MLV_rgba(205,102,0,255)

/** \~french 
 * Define the DARKORANGE4 color.
 *
 */
#define MLV_COLOR_DARKORANGE4 MLV_rgba(139,69,0,255)

/** \~french 
 * Define the CORAL1 color.
 *
 */
#define MLV_COLOR_CORAL1 MLV_rgba(255,114,86,255)

/** \~french 
 * Define the CORAL2 color.
 *
 */
#define MLV_COLOR_CORAL2 MLV_rgba(238,106,80,255)

/** \~french 
 * Define the CORAL3 color.
 *
 */
#define MLV_COLOR_CORAL3 MLV_rgba(205,91,69,255)

/** \~french 
 * Define the CORAL4 color.
 *
 */
#define MLV_COLOR_CORAL4 MLV_rgba(139,62,47,255)

/** \~french 
 * Define the TOMATO1 color.
 *
 */
#define MLV_COLOR_TOMATO1 MLV_rgba(255,99,71,255)

/** \~french 
 * Define the TOMATO2 color.
 *
 */
#define MLV_COLOR_TOMATO2 MLV_rgba(238,92,66,255)

/** \~french 
 * Define the TOMATO3 color.
 *
 */
#define MLV_COLOR_TOMATO3 MLV_rgba(205,79,57,255)

/** \~french 
 * Define the TOMATO4 color.
 *
 */
#define MLV_COLOR_TOMATO4 MLV_rgba(139,54,38,255)

/** \~french 
 * Define the ORANGERED1 color.
 *
 */
#define MLV_COLOR_ORANGERED1 MLV_rgba(255,69,0,255)

/** \~french 
 * Define the ORANGERED2 color.
 *
 */
#define MLV_COLOR_ORANGERED2 MLV_rgba(238,64,0,255)

/** \~french 
 * Define the ORANGERED3 color.
 *
 */
#define MLV_COLOR_ORANGERED3 MLV_rgba(205,55,0,255)

/** \~french 
 * Define the ORANGERED4 color.
 *
 */
#define MLV_COLOR_ORANGERED4 MLV_rgba(139,37,0,255)

/** \~french 
 * Define the RED1 color.
 *
 */
#define MLV_COLOR_RED1 MLV_rgba(255,0,0,255)

/** \~french 
 * Define the RED2 color.
 *
 */
#define MLV_COLOR_RED2 MLV_rgba(238,0,0,255)

/** \~french 
 * Define the RED3 color.
 *
 */
#define MLV_COLOR_RED3 MLV_rgba(205,0,0,255)

/** \~french 
 * Define the RED4 color.
 *
 */
#define MLV_COLOR_RED4 MLV_rgba(139,0,0,255)

/** \~french 
 * Define the DEEPPINK1 color.
 *
 */
#define MLV_COLOR_DEEPPINK1 MLV_rgba(255,20,147,255)

/** \~french 
 * Define the DEEPPINK2 color.
 *
 */
#define MLV_COLOR_DEEPPINK2 MLV_rgba(238,18,137,255)

/** \~french 
 * Define the DEEPPINK3 color.
 *
 */
#define MLV_COLOR_DEEPPINK3 MLV_rgba(205,16,118,255)

/** \~french 
 * Define the DEEPPINK4 color.
 *
 */
#define MLV_COLOR_DEEPPINK4 MLV_rgba(139,10,80,255)

/** \~french 
 * Define the HOTPINK1 color.
 *
 */
#define MLV_COLOR_HOTPINK1 MLV_rgba(255,110,180,255)

/** \~french 
 * Define the HOTPINK2 color.
 *
 */
#define MLV_COLOR_HOTPINK2 MLV_rgba(238,106,167,255)

/** \~french 
 * Define the HOTPINK3 color.
 *
 */
#define MLV_COLOR_HOTPINK3 MLV_rgba(205,96,144,255)

/** \~french 
 * Define the HOTPINK4 color.
 *
 */
#define MLV_COLOR_HOTPINK4 MLV_rgba(139,58,98,255)

/** \~french 
 * Define the PINK1 color.
 *
 */
#define MLV_COLOR_PINK1 MLV_rgba(255,181,197,255)

/** \~french 
 * Define the PINK2 color.
 *
 */
#define MLV_COLOR_PINK2 MLV_rgba(238,169,184,255)

/** \~french 
 * Define the PINK3 color.
 *
 */
#define MLV_COLOR_PINK3 MLV_rgba(205,145,158,255)

/** \~french 
 * Define the PINK4 color.
 *
 */
#define MLV_COLOR_PINK4 MLV_rgba(139,99,108,255)

/** \~french 
 * Define the LIGHTPINK1 color.
 *
 */
#define MLV_COLOR_LIGHTPINK1 MLV_rgba(255,174,185,255)

/** \~french 
 * Define the LIGHTPINK2 color.
 *
 */
#define MLV_COLOR_LIGHTPINK2 MLV_rgba(238,162,173,255)

/** \~french 
 * Define the LIGHTPINK3 color.
 *
 */
#define MLV_COLOR_LIGHTPINK3 MLV_rgba(205,140,149,255)

/** \~french 
 * Define the LIGHTPINK4 color.
 *
 */
#define MLV_COLOR_LIGHTPINK4 MLV_rgba(139,95,101,255)

/** \~french 
 * Define the PALEVIOLETRED1 color.
 *
 */
#define MLV_COLOR_PALEVIOLETRED1 MLV_rgba(255,130,171,255)

/** \~french 
 * Define the PALEVIOLETRED2 color.
 *
 */
#define MLV_COLOR_PALEVIOLETRED2 MLV_rgba(238,121,159,255)

/** \~french 
 * Define the PALEVIOLETRED3 color.
 *
 */
#define MLV_COLOR_PALEVIOLETRED3 MLV_rgba(205,104,137,255)

/** \~french 
 * Define the PALEVIOLETRED4 color.
 *
 */
#define MLV_COLOR_PALEVIOLETRED4 MLV_rgba(139,71,93,255)

/** \~french 
 * Define the MAROON1 color.
 *
 */
#define MLV_COLOR_MAROON1 MLV_rgba(255,52,179,255)

/** \~french 
 * Define the MAROON2 color.
 *
 */
#define MLV_COLOR_MAROON2 MLV_rgba(238,48,167,255)

/** \~french 
 * Define the MAROON3 color.
 *
 */
#define MLV_COLOR_MAROON3 MLV_rgba(205,41,144,255)

/** \~french 
 * Define the MAROON4 color.
 *
 */
#define MLV_COLOR_MAROON4 MLV_rgba(139,28,98,255)

/** \~french 
 * Define the VIOLETRED1 color.
 *
 */
#define MLV_COLOR_VIOLETRED1 MLV_rgba(255,62,150,255)

/** \~french 
 * Define the VIOLETRED2 color.
 *
 */
#define MLV_COLOR_VIOLETRED2 MLV_rgba(238,58,140,255)

/** \~french 
 * Define the VIOLETRED3 color.
 *
 */
#define MLV_COLOR_VIOLETRED3 MLV_rgba(205,50,120,255)

/** \~french 
 * Define the VIOLETRED4 color.
 *
 */
#define MLV_COLOR_VIOLETRED4 MLV_rgba(139,34,82,255)

/** \~french 
 * Define the MAGENTA1 color.
 *
 */
#define MLV_COLOR_MAGENTA1 MLV_rgba(255,0,255,255)

/** \~french 
 * Define the MAGENTA2 color.
 *
 */
#define MLV_COLOR_MAGENTA2 MLV_rgba(238,0,238,255)

/** \~french 
 * Define the MAGENTA3 color.
 *
 */
#define MLV_COLOR_MAGENTA3 MLV_rgba(205,0,205,255)

/** \~french 
 * Define the MAGENTA4 color.
 *
 */
#define MLV_COLOR_MAGENTA4 MLV_rgba(139,0,139,255)

/** \~french 
 * Define the ORCHID1 color.
 *
 */
#define MLV_COLOR_ORCHID1 MLV_rgba(255,131,250,255)

/** \~french 
 * Define the ORCHID2 color.
 *
 */
#define MLV_COLOR_ORCHID2 MLV_rgba(238,122,233,255)

/** \~french 
 * Define the ORCHID3 color.
 *
 */
#define MLV_COLOR_ORCHID3 MLV_rgba(205,105,201,255)

/** \~french 
 * Define the ORCHID4 color.
 *
 */
#define MLV_COLOR_ORCHID4 MLV_rgba(139,71,137,255)

/** \~french 
 * Define the PLUM1 color.
 *
 */
#define MLV_COLOR_PLUM1 MLV_rgba(255,187,255,255)

/** \~french 
 * Define the PLUM2 color.
 *
 */
#define MLV_COLOR_PLUM2 MLV_rgba(238,174,238,255)

/** \~french 
 * Define the PLUM3 color.
 *
 */
#define MLV_COLOR_PLUM3 MLV_rgba(205,150,205,255)

/** \~french 
 * Define the PLUM4 color.
 *
 */
#define MLV_COLOR_PLUM4 MLV_rgba(139,102,139,255)

/** \~french 
 * Define the MEDIUMORCHID1 color.
 *
 */
#define MLV_COLOR_MEDIUMORCHID1 MLV_rgba(224,102,255,255)

/** \~french 
 * Define the MEDIUMORCHID2 color.
 *
 */
#define MLV_COLOR_MEDIUMORCHID2 MLV_rgba(209,95,238,255)

/** \~french 
 * Define the MEDIUMORCHID3 color.
 *
 */
#define MLV_COLOR_MEDIUMORCHID3 MLV_rgba(180,82,205,255)

/** \~french 
 * Define the MEDIUMORCHID4 color.
 *
 */
#define MLV_COLOR_MEDIUMORCHID4 MLV_rgba(122,55,139,255)

/** \~french 
 * Define the DARKORCHID1 color.
 *
 */
#define MLV_COLOR_DARKORCHID1 MLV_rgba(191,62,255,255)

/** \~french 
 * Define the DARKORCHID2 color.
 *
 */
#define MLV_COLOR_DARKORCHID2 MLV_rgba(178,58,238,255)

/** \~french 
 * Define the DARKORCHID3 color.
 *
 */
#define MLV_COLOR_DARKORCHID3 MLV_rgba(154,50,205,255)

/** \~french 
 * Define the DARKORCHID4 color.
 *
 */
#define MLV_COLOR_DARKORCHID4 MLV_rgba(104,34,139,255)

/** \~french 
 * Define the PURPLE1 color.
 *
 */
#define MLV_COLOR_PURPLE1 MLV_rgba(155,48,255,255)

/** \~french 
 * Define the PURPLE2 color.
 *
 */
#define MLV_COLOR_PURPLE2 MLV_rgba(145,44,238,255)

/** \~french 
 * Define the PURPLE3 color.
 *
 */
#define MLV_COLOR_PURPLE3 MLV_rgba(125,38,205,255)

/** \~french 
 * Define the PURPLE4 color.
 *
 */
#define MLV_COLOR_PURPLE4 MLV_rgba(85,26,139,255)

/** \~french 
 * Define the MEDIUMPURPLE1 color.
 *
 */
#define MLV_COLOR_MEDIUMPURPLE1 MLV_rgba(171,130,255,255)

/** \~french 
 * Define the MEDIUMPURPLE2 color.
 *
 */
#define MLV_COLOR_MEDIUMPURPLE2 MLV_rgba(159,121,238,255)

/** \~french 
 * Define the MEDIUMPURPLE3 color.
 *
 */
#define MLV_COLOR_MEDIUMPURPLE3 MLV_rgba(137,104,205,255)

/** \~french 
 * Define the MEDIUMPURPLE4 color.
 *
 */
#define MLV_COLOR_MEDIUMPURPLE4 MLV_rgba(93,71,139,255)

/** \~french 
 * Define the THISTLE1 color.
 *
 */
#define MLV_COLOR_THISTLE1 MLV_rgba(255,225,255,255)

/** \~french 
 * Define the THISTLE2 color.
 *
 */
#define MLV_COLOR_THISTLE2 MLV_rgba(238,210,238,255)

/** \~french 
 * Define the THISTLE3 color.
 *
 */
#define MLV_COLOR_THISTLE3 MLV_rgba(205,181,205,255)

/** \~french 
 * Define the THISTLE4 color.
 *
 */
#define MLV_COLOR_THISTLE4 MLV_rgba(139,123,139,255)

/** \~french 
 * Define the GRAY0 color.
 *
 */
#define MLV_COLOR_GRAY0 MLV_rgba(0,0,0,255)

/** \~french 
 * Define the GREY0 color.
 *
 */
#define MLV_COLOR_GREY0 MLV_rgba(0,0,0,255)

/** \~french 
 * Define the GRAY1 color.
 *
 */
#define MLV_COLOR_GRAY1 MLV_rgba(3,3,3,255)

/** \~french 
 * Define the GREY1 color.
 *
 */
#define MLV_COLOR_GREY1 MLV_rgba(3,3,3,255)

/** \~french 
 * Define the GRAY2 color.
 *
 */
#define MLV_COLOR_GRAY2 MLV_rgba(5,5,5,255)

/** \~french 
 * Define the GREY2 color.
 *
 */
#define MLV_COLOR_GREY2 MLV_rgba(5,5,5,255)

/** \~french 
 * Define the GRAY3 color.
 *
 */
#define MLV_COLOR_GRAY3 MLV_rgba(8,8,8,255)

/** \~french 
 * Define the GREY3 color.
 *
 */
#define MLV_COLOR_GREY3 MLV_rgba(8,8,8,255)

/** \~french 
 * Define the GRAY4 color.
 *
 */
#define MLV_COLOR_GRAY4 MLV_rgba(10,10,10,255)

/** \~french 
 * Define the GREY4 color.
 *
 */
#define MLV_COLOR_GREY4 MLV_rgba(10,10,10,255)

/** \~french 
 * Define the GRAY5 color.
 *
 */
#define MLV_COLOR_GRAY5 MLV_rgba(13,13,13,255)

/** \~french 
 * Define the GREY5 color.
 *
 */
#define MLV_COLOR_GREY5 MLV_rgba(13,13,13,255)

/** \~french 
 * Define the GRAY6 color.
 *
 */
#define MLV_COLOR_GRAY6 MLV_rgba(15,15,15,255)

/** \~french 
 * Define the GREY6 color.
 *
 */
#define MLV_COLOR_GREY6 MLV_rgba(15,15,15,255)

/** \~french 
 * Define the GRAY7 color.
 *
 */
#define MLV_COLOR_GRAY7 MLV_rgba(18,18,18,255)

/** \~french 
 * Define the GREY7 color.
 *
 */
#define MLV_COLOR_GREY7 MLV_rgba(18,18,18,255)

/** \~french 
 * Define the GRAY8 color.
 *
 */
#define MLV_COLOR_GRAY8 MLV_rgba(20,20,20,255)

/** \~french 
 * Define the GREY8 color.
 *
 */
#define MLV_COLOR_GREY8 MLV_rgba(20,20,20,255)

/** \~french 
 * Define the GRAY9 color.
 *
 */
#define MLV_COLOR_GRAY9 MLV_rgba(23,23,23,255)

/** \~french 
 * Define the GREY9 color.
 *
 */
#define MLV_COLOR_GREY9 MLV_rgba(23,23,23,255)

/** \~french 
 * Define the GRAY10 color.
 *
 */
#define MLV_COLOR_GRAY10 MLV_rgba(26,26,26,255)

/** \~french 
 * Define the GREY10 color.
 *
 */
#define MLV_COLOR_GREY10 MLV_rgba(26,26,26,255)

/** \~french 
 * Define the GRAY11 color.
 *
 */
#define MLV_COLOR_GRAY11 MLV_rgba(28,28,28,255)

/** \~french 
 * Define the GREY11 color.
 *
 */
#define MLV_COLOR_GREY11 MLV_rgba(28,28,28,255)

/** \~french 
 * Define the GRAY12 color.
 *
 */
#define MLV_COLOR_GRAY12 MLV_rgba(31,31,31,255)

/** \~french 
 * Define the GREY12 color.
 *
 */
#define MLV_COLOR_GREY12 MLV_rgba(31,31,31,255)

/** \~french 
 * Define the GRAY13 color.
 *
 */
#define MLV_COLOR_GRAY13 MLV_rgba(33,33,33,255)

/** \~french 
 * Define the GREY13 color.
 *
 */
#define MLV_COLOR_GREY13 MLV_rgba(33,33,33,255)

/** \~french 
 * Define the GRAY14 color.
 *
 */
#define MLV_COLOR_GRAY14 MLV_rgba(36,36,36,255)

/** \~french 
 * Define the GREY14 color.
 *
 */
#define MLV_COLOR_GREY14 MLV_rgba(36,36,36,255)

/** \~french 
 * Define the GRAY15 color.
 *
 */
#define MLV_COLOR_GRAY15 MLV_rgba(38,38,38,255)

/** \~french 
 * Define the GREY15 color.
 *
 */
#define MLV_COLOR_GREY15 MLV_rgba(38,38,38,255)

/** \~french 
 * Define the GRAY16 color.
 *
 */
#define MLV_COLOR_GRAY16 MLV_rgba(41,41,41,255)

/** \~french 
 * Define the GREY16 color.
 *
 */
#define MLV_COLOR_GREY16 MLV_rgba(41,41,41,255)

/** \~french 
 * Define the GRAY17 color.
 *
 */
#define MLV_COLOR_GRAY17 MLV_rgba(43,43,43,255)

/** \~french 
 * Define the GREY17 color.
 *
 */
#define MLV_COLOR_GREY17 MLV_rgba(43,43,43,255)

/** \~french 
 * Define the GRAY18 color.
 *
 */
#define MLV_COLOR_GRAY18 MLV_rgba(46,46,46,255)

/** \~french 
 * Define the GREY18 color.
 *
 */
#define MLV_COLOR_GREY18 MLV_rgba(46,46,46,255)

/** \~french 
 * Define the GRAY19 color.
 *
 */
#define MLV_COLOR_GRAY19 MLV_rgba(48,48,48,255)

/** \~french 
 * Define the GREY19 color.
 *
 */
#define MLV_COLOR_GREY19 MLV_rgba(48,48,48,255)

/** \~french 
 * Define the GRAY20 color.
 *
 */
#define MLV_COLOR_GRAY20 MLV_rgba(51,51,51,255)

/** \~french 
 * Define the GREY20 color.
 *
 */
#define MLV_COLOR_GREY20 MLV_rgba(51,51,51,255)

/** \~french 
 * Define the GRAY21 color.
 *
 */
#define MLV_COLOR_GRAY21 MLV_rgba(54,54,54,255)

/** \~french 
 * Define the GREY21 color.
 *
 */
#define MLV_COLOR_GREY21 MLV_rgba(54,54,54,255)

/** \~french 
 * Define the GRAY22 color.
 *
 */
#define MLV_COLOR_GRAY22 MLV_rgba(56,56,56,255)

/** \~french 
 * Define the GREY22 color.
 *
 */
#define MLV_COLOR_GREY22 MLV_rgba(56,56,56,255)

/** \~french 
 * Define the GRAY23 color.
 *
 */
#define MLV_COLOR_GRAY23 MLV_rgba(59,59,59,255)

/** \~french 
 * Define the GREY23 color.
 *
 */
#define MLV_COLOR_GREY23 MLV_rgba(59,59,59,255)

/** \~french 
 * Define the GRAY24 color.
 *
 */
#define MLV_COLOR_GRAY24 MLV_rgba(61,61,61,255)

/** \~french 
 * Define the GREY24 color.
 *
 */
#define MLV_COLOR_GREY24 MLV_rgba(61,61,61,255)

/** \~french 
 * Define the GRAY25 color.
 *
 */
#define MLV_COLOR_GRAY25 MLV_rgba(64,64,64,255)

/** \~french 
 * Define the GREY25 color.
 *
 */
#define MLV_COLOR_GREY25 MLV_rgba(64,64,64,255)

/** \~french 
 * Define the GRAY26 color.
 *
 */
#define MLV_COLOR_GRAY26 MLV_rgba(66,66,66,255)

/** \~french 
 * Define the GREY26 color.
 *
 */
#define MLV_COLOR_GREY26 MLV_rgba(66,66,66,255)

/** \~french 
 * Define the GRAY27 color.
 *
 */
#define MLV_COLOR_GRAY27 MLV_rgba(69,69,69,255)

/** \~french 
 * Define the GREY27 color.
 *
 */
#define MLV_COLOR_GREY27 MLV_rgba(69,69,69,255)

/** \~french 
 * Define the GRAY28 color.
 *
 */
#define MLV_COLOR_GRAY28 MLV_rgba(71,71,71,255)

/** \~french 
 * Define the GREY28 color.
 *
 */
#define MLV_COLOR_GREY28 MLV_rgba(71,71,71,255)

/** \~french 
 * Define the GRAY29 color.
 *
 */
#define MLV_COLOR_GRAY29 MLV_rgba(74,74,74,255)

/** \~french 
 * Define the GREY29 color.
 *
 */
#define MLV_COLOR_GREY29 MLV_rgba(74,74,74,255)

/** \~french 
 * Define the GRAY30 color.
 *
 */
#define MLV_COLOR_GRAY30 MLV_rgba(77,77,77,255)

/** \~french 
 * Define the GREY30 color.
 *
 */
#define MLV_COLOR_GREY30 MLV_rgba(77,77,77,255)

/** \~french 
 * Define the GRAY31 color.
 *
 */
#define MLV_COLOR_GRAY31 MLV_rgba(79,79,79,255)

/** \~french 
 * Define the GREY31 color.
 *
 */
#define MLV_COLOR_GREY31 MLV_rgba(79,79,79,255)

/** \~french 
 * Define the GRAY32 color.
 *
 */
#define MLV_COLOR_GRAY32 MLV_rgba(82,82,82,255)

/** \~french 
 * Define the GREY32 color.
 *
 */
#define MLV_COLOR_GREY32 MLV_rgba(82,82,82,255)

/** \~french 
 * Define the GRAY33 color.
 *
 */
#define MLV_COLOR_GRAY33 MLV_rgba(84,84,84,255)

/** \~french 
 * Define the GREY33 color.
 *
 */
#define MLV_COLOR_GREY33 MLV_rgba(84,84,84,255)

/** \~french 
 * Define the GRAY34 color.
 *
 */
#define MLV_COLOR_GRAY34 MLV_rgba(87,87,87,255)

/** \~french 
 * Define the GREY34 color.
 *
 */
#define MLV_COLOR_GREY34 MLV_rgba(87,87,87,255)

/** \~french 
 * Define the GRAY35 color.
 *
 */
#define MLV_COLOR_GRAY35 MLV_rgba(89,89,89,255)

/** \~french 
 * Define the GREY35 color.
 *
 */
#define MLV_COLOR_GREY35 MLV_rgba(89,89,89,255)

/** \~french 
 * Define the GRAY36 color.
 *
 */
#define MLV_COLOR_GRAY36 MLV_rgba(92,92,92,255)

/** \~french 
 * Define the GREY36 color.
 *
 */
#define MLV_COLOR_GREY36 MLV_rgba(92,92,92,255)

/** \~french 
 * Define the GRAY37 color.
 *
 */
#define MLV_COLOR_GRAY37 MLV_rgba(94,94,94,255)

/** \~french 
 * Define the GREY37 color.
 *
 */
#define MLV_COLOR_GREY37 MLV_rgba(94,94,94,255)

/** \~french 
 * Define the GRAY38 color.
 *
 */
#define MLV_COLOR_GRAY38 MLV_rgba(97,97,97,255)

/** \~french 
 * Define the GREY38 color.
 *
 */
#define MLV_COLOR_GREY38 MLV_rgba(97,97,97,255)

/** \~french 
 * Define the GRAY39 color.
 *
 */
#define MLV_COLOR_GRAY39 MLV_rgba(99,99,99,255)

/** \~french 
 * Define the GREY39 color.
 *
 */
#define MLV_COLOR_GREY39 MLV_rgba(99,99,99,255)

/** \~french 
 * Define the GRAY40 color.
 *
 */
#define MLV_COLOR_GRAY40 MLV_rgba(102,102,102,255)

/** \~french 
 * Define the GREY40 color.
 *
 */
#define MLV_COLOR_GREY40 MLV_rgba(102,102,102,255)

/** \~french 
 * Define the GRAY41 color.
 *
 */
#define MLV_COLOR_GRAY41 MLV_rgba(105,105,105,255)

/** \~french 
 * Define the GREY41 color.
 *
 */
#define MLV_COLOR_GREY41 MLV_rgba(105,105,105,255)

/** \~french 
 * Define the GRAY42 color.
 *
 */
#define MLV_COLOR_GRAY42 MLV_rgba(107,107,107,255)

/** \~french 
 * Define the GREY42 color.
 *
 */
#define MLV_COLOR_GREY42 MLV_rgba(107,107,107,255)

/** \~french 
 * Define the GRAY43 color.
 *
 */
#define MLV_COLOR_GRAY43 MLV_rgba(110,110,110,255)

/** \~french 
 * Define the GREY43 color.
 *
 */
#define MLV_COLOR_GREY43 MLV_rgba(110,110,110,255)

/** \~french 
 * Define the GRAY44 color.
 *
 */
#define MLV_COLOR_GRAY44 MLV_rgba(112,112,112,255)

/** \~french 
 * Define the GREY44 color.
 *
 */
#define MLV_COLOR_GREY44 MLV_rgba(112,112,112,255)

/** \~french 
 * Define the GRAY45 color.
 *
 */
#define MLV_COLOR_GRAY45 MLV_rgba(115,115,115,255)

/** \~french 
 * Define the GREY45 color.
 *
 */
#define MLV_COLOR_GREY45 MLV_rgba(115,115,115,255)

/** \~french 
 * Define the GRAY46 color.
 *
 */
#define MLV_COLOR_GRAY46 MLV_rgba(117,117,117,255)

/** \~french 
 * Define the GREY46 color.
 *
 */
#define MLV_COLOR_GREY46 MLV_rgba(117,117,117,255)

/** \~french 
 * Define the GRAY47 color.
 *
 */
#define MLV_COLOR_GRAY47 MLV_rgba(120,120,120,255)

/** \~french 
 * Define the GREY47 color.
 *
 */
#define MLV_COLOR_GREY47 MLV_rgba(120,120,120,255)

/** \~french 
 * Define the GRAY48 color.
 *
 */
#define MLV_COLOR_GRAY48 MLV_rgba(122,122,122,255)

/** \~french 
 * Define the GREY48 color.
 *
 */
#define MLV_COLOR_GREY48 MLV_rgba(122,122,122,255)

/** \~french 
 * Define the GRAY49 color.
 *
 */
#define MLV_COLOR_GRAY49 MLV_rgba(125,125,125,255)

/** \~french 
 * Define the GREY49 color.
 *
 */
#define MLV_COLOR_GREY49 MLV_rgba(125,125,125,255)

/** \~french 
 * Define the GRAY50 color.
 *
 */
#define MLV_COLOR_GRAY50 MLV_rgba(127,127,127,255)

/** \~french 
 * Define the GREY50 color.
 *
 */
#define MLV_COLOR_GREY50 MLV_rgba(127,127,127,255)

/** \~french 
 * Define the GRAY51 color.
 *
 */
#define MLV_COLOR_GRAY51 MLV_rgba(130,130,130,255)

/** \~french 
 * Define the GREY51 color.
 *
 */
#define MLV_COLOR_GREY51 MLV_rgba(130,130,130,255)

/** \~french 
 * Define the GRAY52 color.
 *
 */
#define MLV_COLOR_GRAY52 MLV_rgba(133,133,133,255)

/** \~french 
 * Define the GREY52 color.
 *
 */
#define MLV_COLOR_GREY52 MLV_rgba(133,133,133,255)

/** \~french 
 * Define the GRAY53 color.
 *
 */
#define MLV_COLOR_GRAY53 MLV_rgba(135,135,135,255)

/** \~french 
 * Define the GREY53 color.
 *
 */
#define MLV_COLOR_GREY53 MLV_rgba(135,135,135,255)

/** \~french 
 * Define the GRAY54 color.
 *
 */
#define MLV_COLOR_GRAY54 MLV_rgba(138,138,138,255)

/** \~french 
 * Define the GREY54 color.
 *
 */
#define MLV_COLOR_GREY54 MLV_rgba(138,138,138,255)

/** \~french 
 * Define the GRAY55 color.
 *
 */
#define MLV_COLOR_GRAY55 MLV_rgba(140,140,140,255)

/** \~french 
 * Define the GREY55 color.
 *
 */
#define MLV_COLOR_GREY55 MLV_rgba(140,140,140,255)

/** \~french 
 * Define the GRAY56 color.
 *
 */
#define MLV_COLOR_GRAY56 MLV_rgba(143,143,143,255)

/** \~french 
 * Define the GREY56 color.
 *
 */
#define MLV_COLOR_GREY56 MLV_rgba(143,143,143,255)

/** \~french 
 * Define the GRAY57 color.
 *
 */
#define MLV_COLOR_GRAY57 MLV_rgba(145,145,145,255)

/** \~french 
 * Define the GREY57 color.
 *
 */
#define MLV_COLOR_GREY57 MLV_rgba(145,145,145,255)

/** \~french 
 * Define the GRAY58 color.
 *
 */
#define MLV_COLOR_GRAY58 MLV_rgba(148,148,148,255)

/** \~french 
 * Define the GREY58 color.
 *
 */
#define MLV_COLOR_GREY58 MLV_rgba(148,148,148,255)

/** \~french 
 * Define the GRAY59 color.
 *
 */
#define MLV_COLOR_GRAY59 MLV_rgba(150,150,150,255)

/** \~french 
 * Define the GREY59 color.
 *
 */
#define MLV_COLOR_GREY59 MLV_rgba(150,150,150,255)

/** \~french 
 * Define the GRAY60 color.
 *
 */
#define MLV_COLOR_GRAY60 MLV_rgba(153,153,153,255)

/** \~french 
 * Define the GREY60 color.
 *
 */
#define MLV_COLOR_GREY60 MLV_rgba(153,153,153,255)

/** \~french 
 * Define the GRAY61 color.
 *
 */
#define MLV_COLOR_GRAY61 MLV_rgba(156,156,156,255)

/** \~french 
 * Define the GREY61 color.
 *
 */
#define MLV_COLOR_GREY61 MLV_rgba(156,156,156,255)

/** \~french 
 * Define the GRAY62 color.
 *
 */
#define MLV_COLOR_GRAY62 MLV_rgba(158,158,158,255)

/** \~french 
 * Define the GREY62 color.
 *
 */
#define MLV_COLOR_GREY62 MLV_rgba(158,158,158,255)

/** \~french 
 * Define the GRAY63 color.
 *
 */
#define MLV_COLOR_GRAY63 MLV_rgba(161,161,161,255)

/** \~french 
 * Define the GREY63 color.
 *
 */
#define MLV_COLOR_GREY63 MLV_rgba(161,161,161,255)

/** \~french 
 * Define the GRAY64 color.
 *
 */
#define MLV_COLOR_GRAY64 MLV_rgba(163,163,163,255)

/** \~french 
 * Define the GREY64 color.
 *
 */
#define MLV_COLOR_GREY64 MLV_rgba(163,163,163,255)

/** \~french 
 * Define the GRAY65 color.
 *
 */
#define MLV_COLOR_GRAY65 MLV_rgba(166,166,166,255)

/** \~french 
 * Define the GREY65 color.
 *
 */
#define MLV_COLOR_GREY65 MLV_rgba(166,166,166,255)

/** \~french 
 * Define the GRAY66 color.
 *
 */
#define MLV_COLOR_GRAY66 MLV_rgba(168,168,168,255)

/** \~french 
 * Define the GREY66 color.
 *
 */
#define MLV_COLOR_GREY66 MLV_rgba(168,168,168,255)

/** \~french 
 * Define the GRAY67 color.
 *
 */
#define MLV_COLOR_GRAY67 MLV_rgba(171,171,171,255)

/** \~french 
 * Define the GREY67 color.
 *
 */
#define MLV_COLOR_GREY67 MLV_rgba(171,171,171,255)

/** \~french 
 * Define the GRAY68 color.
 *
 */
#define MLV_COLOR_GRAY68 MLV_rgba(173,173,173,255)

/** \~french 
 * Define the GREY68 color.
 *
 */
#define MLV_COLOR_GREY68 MLV_rgba(173,173,173,255)

/** \~french 
 * Define the GRAY69 color.
 *
 */
#define MLV_COLOR_GRAY69 MLV_rgba(176,176,176,255)

/** \~french 
 * Define the GREY69 color.
 *
 */
#define MLV_COLOR_GREY69 MLV_rgba(176,176,176,255)

/** \~french 
 * Define the GRAY70 color.
 *
 */
#define MLV_COLOR_GRAY70 MLV_rgba(179,179,179,255)

/** \~french 
 * Define the GREY70 color.
 *
 */
#define MLV_COLOR_GREY70 MLV_rgba(179,179,179,255)

/** \~french 
 * Define the GRAY71 color.
 *
 */
#define MLV_COLOR_GRAY71 MLV_rgba(181,181,181,255)

/** \~french 
 * Define the GREY71 color.
 *
 */
#define MLV_COLOR_GREY71 MLV_rgba(181,181,181,255)

/** \~french 
 * Define the GRAY72 color.
 *
 */
#define MLV_COLOR_GRAY72 MLV_rgba(184,184,184,255)

/** \~french 
 * Define the GREY72 color.
 *
 */
#define MLV_COLOR_GREY72 MLV_rgba(184,184,184,255)

/** \~french 
 * Define the GRAY73 color.
 *
 */
#define MLV_COLOR_GRAY73 MLV_rgba(186,186,186,255)

/** \~french 
 * Define the GREY73 color.
 *
 */
#define MLV_COLOR_GREY73 MLV_rgba(186,186,186,255)

/** \~french 
 * Define the GRAY74 color.
 *
 */
#define MLV_COLOR_GRAY74 MLV_rgba(189,189,189,255)

/** \~french 
 * Define the GREY74 color.
 *
 */
#define MLV_COLOR_GREY74 MLV_rgba(189,189,189,255)

/** \~french 
 * Define the GRAY75 color.
 *
 */
#define MLV_COLOR_GRAY75 MLV_rgba(191,191,191,255)

/** \~french 
 * Define the GREY75 color.
 *
 */
#define MLV_COLOR_GREY75 MLV_rgba(191,191,191,255)

/** \~french 
 * Define the GRAY76 color.
 *
 */
#define MLV_COLOR_GRAY76 MLV_rgba(194,194,194,255)

/** \~french 
 * Define the GREY76 color.
 *
 */
#define MLV_COLOR_GREY76 MLV_rgba(194,194,194,255)

/** \~french 
 * Define the GRAY77 color.
 *
 */
#define MLV_COLOR_GRAY77 MLV_rgba(196,196,196,255)

/** \~french 
 * Define the GREY77 color.
 *
 */
#define MLV_COLOR_GREY77 MLV_rgba(196,196,196,255)

/** \~french 
 * Define the GRAY78 color.
 *
 */
#define MLV_COLOR_GRAY78 MLV_rgba(199,199,199,255)

/** \~french 
 * Define the GREY78 color.
 *
 */
#define MLV_COLOR_GREY78 MLV_rgba(199,199,199,255)

/** \~french 
 * Define the GRAY79 color.
 *
 */
#define MLV_COLOR_GRAY79 MLV_rgba(201,201,201,255)

/** \~french 
 * Define the GREY79 color.
 *
 */
#define MLV_COLOR_GREY79 MLV_rgba(201,201,201,255)

/** \~french 
 * Define the GRAY80 color.
 *
 */
#define MLV_COLOR_GRAY80 MLV_rgba(204,204,204,255)

/** \~french 
 * Define the GREY80 color.
 *
 */
#define MLV_COLOR_GREY80 MLV_rgba(204,204,204,255)

/** \~french 
 * Define the GRAY81 color.
 *
 */
#define MLV_COLOR_GRAY81 MLV_rgba(207,207,207,255)

/** \~french 
 * Define the GREY81 color.
 *
 */
#define MLV_COLOR_GREY81 MLV_rgba(207,207,207,255)

/** \~french 
 * Define the GRAY82 color.
 *
 */
#define MLV_COLOR_GRAY82 MLV_rgba(209,209,209,255)

/** \~french 
 * Define the GREY82 color.
 *
 */
#define MLV_COLOR_GREY82 MLV_rgba(209,209,209,255)

/** \~french 
 * Define the GRAY83 color.
 *
 */
#define MLV_COLOR_GRAY83 MLV_rgba(212,212,212,255)

/** \~french 
 * Define the GREY83 color.
 *
 */
#define MLV_COLOR_GREY83 MLV_rgba(212,212,212,255)

/** \~french 
 * Define the GRAY84 color.
 *
 */
#define MLV_COLOR_GRAY84 MLV_rgba(214,214,214,255)

/** \~french 
 * Define the GREY84 color.
 *
 */
#define MLV_COLOR_GREY84 MLV_rgba(214,214,214,255)

/** \~french 
 * Define the GRAY85 color.
 *
 */
#define MLV_COLOR_GRAY85 MLV_rgba(217,217,217,255)

/** \~french 
 * Define the GREY85 color.
 *
 */
#define MLV_COLOR_GREY85 MLV_rgba(217,217,217,255)

/** \~french 
 * Define the GRAY86 color.
 *
 */
#define MLV_COLOR_GRAY86 MLV_rgba(219,219,219,255)

/** \~french 
 * Define the GREY86 color.
 *
 */
#define MLV_COLOR_GREY86 MLV_rgba(219,219,219,255)

/** \~french 
 * Define the GRAY87 color.
 *
 */
#define MLV_COLOR_GRAY87 MLV_rgba(222,222,222,255)

/** \~french 
 * Define the GREY87 color.
 *
 */
#define MLV_COLOR_GREY87 MLV_rgba(222,222,222,255)

/** \~french 
 * Define the GRAY88 color.
 *
 */
#define MLV_COLOR_GRAY88 MLV_rgba(224,224,224,255)

/** \~french 
 * Define the GREY88 color.
 *
 */
#define MLV_COLOR_GREY88 MLV_rgba(224,224,224,255)

/** \~french 
 * Define the GRAY89 color.
 *
 */
#define MLV_COLOR_GRAY89 MLV_rgba(227,227,227,255)

/** \~french 
 * Define the GREY89 color.
 *
 */
#define MLV_COLOR_GREY89 MLV_rgba(227,227,227,255)

/** \~french 
 * Define the GRAY90 color.
 *
 */
#define MLV_COLOR_GRAY90 MLV_rgba(229,229,229,255)

/** \~french 
 * Define the GREY90 color.
 *
 */
#define MLV_COLOR_GREY90 MLV_rgba(229,229,229,255)

/** \~french 
 * Define the GRAY91 color.
 *
 */
#define MLV_COLOR_GRAY91 MLV_rgba(232,232,232,255)

/** \~french 
 * Define the GREY91 color.
 *
 */
#define MLV_COLOR_GREY91 MLV_rgba(232,232,232,255)

/** \~french 
 * Define the GRAY92 color.
 *
 */
#define MLV_COLOR_GRAY92 MLV_rgba(235,235,235,255)

/** \~french 
 * Define the GREY92 color.
 *
 */
#define MLV_COLOR_GREY92 MLV_rgba(235,235,235,255)

/** \~french 
 * Define the GRAY93 color.
 *
 */
#define MLV_COLOR_GRAY93 MLV_rgba(237,237,237,255)

/** \~french 
 * Define the GREY93 color.
 *
 */
#define MLV_COLOR_GREY93 MLV_rgba(237,237,237,255)

/** \~french 
 * Define the GRAY94 color.
 *
 */
#define MLV_COLOR_GRAY94 MLV_rgba(240,240,240,255)

/** \~french 
 * Define the GREY94 color.
 *
 */
#define MLV_COLOR_GREY94 MLV_rgba(240,240,240,255)

/** \~french 
 * Define the GRAY95 color.
 *
 */
#define MLV_COLOR_GRAY95 MLV_rgba(242,242,242,255)

/** \~french 
 * Define the GREY95 color.
 *
 */
#define MLV_COLOR_GREY95 MLV_rgba(242,242,242,255)

/** \~french 
 * Define the GRAY96 color.
 *
 */
#define MLV_COLOR_GRAY96 MLV_rgba(245,245,245,255)

/** \~french 
 * Define the GREY96 color.
 *
 */
#define MLV_COLOR_GREY96 MLV_rgba(245,245,245,255)

/** \~french 
 * Define the GRAY97 color.
 *
 */
#define MLV_COLOR_GRAY97 MLV_rgba(247,247,247,255)

/** \~french 
 * Define the GREY97 color.
 *
 */
#define MLV_COLOR_GREY97 MLV_rgba(247,247,247,255)

/** \~french 
 * Define the GRAY98 color.
 *
 */
#define MLV_COLOR_GRAY98 MLV_rgba(250,250,250,255)

/** \~french 
 * Define the GREY98 color.
 *
 */
#define MLV_COLOR_GREY98 MLV_rgba(250,250,250,255)

/** \~french 
 * Define the GRAY99 color.
 *
 */
#define MLV_COLOR_GRAY99 MLV_rgba(252,252,252,255)

/** \~french 
 * Define the GREY99 color.
 *
 */
#define MLV_COLOR_GREY99 MLV_rgba(252,252,252,255)

/** \~french 
 * Define the GRAY100 color.
 *
 */
#define MLV_COLOR_GRAY100 MLV_rgba(255,255,255,255)

/** \~french 
 * Define the GREY100 color.
 *
 */
#define MLV_COLOR_GREY100 MLV_rgba(255,255,255,255)

/** \~french 
 * Define the DARK_GREY color.
 *
 */
#define MLV_COLOR_DARK_GREY MLV_rgba(169,169,169,255)

/** \~french 
 * Define the DARKGREY color.
 *
 */
#define MLV_COLOR_DARKGREY MLV_rgba(169,169,169,255)

/** \~french 
 * Define the DARK_GRAY color.
 *
 */
#define MLV_COLOR_DARK_GRAY MLV_rgba(169,169,169,255)

/** \~french 
 * Define the DARKGRAY color.
 *
 */
#define MLV_COLOR_DARKGRAY MLV_rgba(169,169,169,255)

/** \~french 
 * Define the DARK_BLUE color.
 *
 */
#define MLV_COLOR_DARK_BLUE MLV_rgba(0,0,139,255)

/** \~french 
 * Define the DARKBLUE color.
 *
 */
#define MLV_COLOR_DARKBLUE MLV_rgba(0,0,139,255)

/** \~french 
 * Define the DARK_CYAN color.
 *
 */
#define MLV_COLOR_DARK_CYAN MLV_rgba(0,139,139,255)

/** \~french 
 * Define the DARKCYAN color.
 *
 */
#define MLV_COLOR_DARKCYAN MLV_rgba(0,139,139,255)

/** \~french 
 * Define the DARK_MAGENTA color.
 *
 */
#define MLV_COLOR_DARK_MAGENTA MLV_rgba(139,0,139,255)

/** \~french 
 * Define the DARKMAGENTA color.
 *
 */
#define MLV_COLOR_DARKMAGENTA MLV_rgba(139,0,139,255)

/** \~french 
 * Define the DARK_RED color.
 *
 */
#define MLV_COLOR_DARK_RED MLV_rgba(139,0,0,255)

/** \~french 
 * Define the DARKRED color.
 *
 */
#define MLV_COLOR_DARKRED MLV_rgba(139,0,0,255)

/** \~french 
 * Define the LIGHT_GREEN color.
 *
 */
#define MLV_COLOR_LIGHT_GREEN MLV_rgba(144,238,144,255)

/** \~french 
 * Define the LIGHTGREEN color.
 *
 */
#define MLV_COLOR_LIGHTGREEN MLV_rgba(144,238,144,255)


#ifdef __cplusplus
}
#endif

#endif
