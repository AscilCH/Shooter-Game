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
 * \file MLV_shape.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit tout les prototypes des fonctions permettant de 
 *        dessiner des figures.
 *
 *
 */

#ifndef __MLV__MLV_FIGURES_H__
#define __MLV__MLV_FIGURES_H__

#include "MLV_color.h"
#include "MLV_image.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Dessine un cercle à une position et un rayon spécifiés en paramètres.
 **
 * \param x La coordonnée en X du centre.
 * \param y La coordonnée en Y du centre.
 * \param radius Le rayon du cercle.
 * \param color La couleur du tracé.
 */
void MLV_draw_circle(int x, int y, int radius, MLV_Color color);

/** \~french 
 * \brief Dessine un disque plein dont le centre et le rayon sont passés en 
 *        paramètres.
 *
 * \param x La coordonnée en X du centre.
 * \param y La coordonnée en Y du centre.
 * \param radius Le rayon du cercle.
 * \param color La couleur du tracé.
 */
void MLV_draw_filled_circle(int x, int y, int radius, MLV_Color color);

/** \~french 
 * \brief Dessine une ellipse.
 *
 * \param x La coordonnée en X du centre de l'ellipse.
 * \param y La coordonnée en Y du centre de l'ellipse.
 * \param radius_x Le rayon en X de l'ellipse.
 * \param radius_y Le rayon en Y de l'ellipse.
 * \param color La couleur du tracé.
 */
void MLV_draw_ellipse(
	int x, int y, int radius_x, int radius_y, MLV_Color color
);

/** \~french 
 * \brief Dessine une ellipse pleine.
 *
 * \param x La coordonnée en X du centre de l'ellipse.
 * \param y La coordonnée en Y du centre de l'ellipse.
 * \param radius_x Le rayon en X de l'ellipse.
 * \param radius_y Le rayon en Y de l'ellipse.
 * \param color La couleur du tracé.
 */
void MLV_draw_filled_ellipse(
	int x, int y, int radius_x, int radius_y, MLV_Color color
);

/** \~french 
 * \brief Dessine un polygone à partir d'une liste de sommets.
 *
 * \param vx La liste des coordonnées en X des différents sommets du polygone.
 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
 * \param nb_points Le nombre de sommets du polygone.
 * \param color La couleur du tracé.
 */
void MLV_draw_polygon(
	const int* vx, const int* vy, int nb_points, MLV_Color color
);

/** \~french 
 * \brief Dessine un polygone plein à partir d'une liste de sommets.
 *
 * \param vx La liste des coordonnées en X des différents sommets du polygone.
 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
 * \param nb_points Le nombre de sommets du polygone.
 * \param color La couleur du tracé.
 */
void MLV_draw_filled_polygon(
	const int* vx, const int* vy, int nb_points, MLV_Color color
);

/** \~french 
 * \brief Dessine une courbe de Bézier à partir d'une liste de sommets.
 *
 * \param vx La liste des coordonnées en X des différents sommets de la courbe.
 * \param vy La liste des coordonnées en Y des différents sommets de la courbe.
 * \param nb_points Le nombre de sommets disponibles pour dessiner la courbe de 
 *                Bézier.
 * \param color La couleur du tracé.
 */
void MLV_draw_bezier_curve(
	const int* vx, const int* vy, int nb_points, MLV_Color color
);

/** \~french 
 * \brief Dessine un polygone plein à partir d'une liste de sommets.
 *
 * \param vx La liste des coordonnées en X des différents sommets du polygone.
 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
 * \param nb_points Le nombre de sommets du polygone.
 * \param color La couleur du tracé.
 */
void MLV_draw_filled_polygon(
	const int* vx, const int* vy, int nb_points, MLV_Color color
);

/** \~french 
 * \brief Dessine un rectangle dont la taille, la couleur et la position du 
 *        sommet Nord-Ouest sont données en paramètres.
 *
 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
 * \param width La largeur du rectangle.
 * \param height La hauteur du rectangle.
 * \param color La couleur du tracé.
 */
void MLV_draw_rectangle(int x, int y, int width, int height, MLV_Color color);

/** \~french 
 * \brief Dessine un rectangle dont la taille, la couleur et la position du 
 *        sommet Nord-Ouest sont données en paramètres.
 *
 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
 * \param width La largeur du rectangle.
 * \param height La hauteur du rectangle.
 * \param color La couleur du tracé.
 */
void MLV_draw_rectangle(int x, int y, int width, int height, MLV_Color color);

/** \~french 
 * \brief Dessine un rectangle plein dont la taille, la couleur et la position 
 *        du sommet Nord-Ouest sont données en paramètres.
 *
 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
 * \param width La largeur du rectangle.
 * \param height La hauteur du rectangle.
 * \param color La couleur du tracé.
 */
void MLV_draw_filled_rectangle(
	int x, int y, int width, int height, MLV_Color color
);

/** \~french 
 * \brief Dessine une ligne.
 *
 * \param x1 La coordonnée en X de la première extrémité de la ligne.
 * \param y1 La coordonnée en Y de la première extrémité de la ligne.
 * \param x2 La coordonnée en X de la deuxième extrémité de la ligne.
 * \param y2 La coordonnée en Y de la deuxième extrémité de la ligne.
 * \param color La couleur du tracé.
 */
void MLV_draw_line(int x1, int y1, int x2, int y2, MLV_Color color);

/** \~french 
 * \brief Dessine un pixel dont les coordonnées sont passées en paramètres.
 *
 * \param x La coordonnée en X du pixel.
 * \param y La coordonnée en Y du pixel.
 * \param color La couleur du tracé.
 */
void MLV_draw_pixel(int x, int y, MLV_Color color);

/** \~french 
 * \brief Dessine un point dont les coordonnées sont passées en paramètres.
 *        Cette fonction est identique à MLV_draw_pixel.
 *
 * \param x La coordonnée en X du point.
 * \param y La coordonnée en Y du point.
 * \param color La couleur du tracé.
 */
void MLV_draw_point(int x, int y, MLV_Color color);






///////////////////////////////////////////////////////////////////////////////
// Drawing operation on images                                               //
///////////////////////////////////////////////////////////////////////////////

/** \~french 
 * \brief Dessine un cercle à une position et un rayon spécifiés en paramètres
 *        dans une image.
 *
 * \param x La coordonnée en X du centre.
 * \param y La coordonnée en Y du centre.
 * \param radius Le rayon du cercle.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_circle_on_image(
	int x, int y, int radius, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine un disque plein dont le centre et le rayon sont passés en
 *        parametres dans une image.
 *
 * \param x La coordonnée en X du centre.
 * \param y La coordonnée en Y du centre.
 * \param radius Le rayon du cercle.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_filled_circle_on_image(
	int x, int y, int radius, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine une ellipse dans une image.
 *
 * \param x La coordonnée en X du centre de l'ellipse.
 * \param y La coordonnée en Y du centre de l'ellipse.
 * \param radius_x Le rayon en X de l'ellipse.
 * \param radius_y Le rayon en Y de l'ellipse.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_ellipse_on_image(
	int x, int y, int radius_x, int radius_y, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine une ellipse pleine dans une image.
 *
 * \param x La coordonnée en X du centre de l'ellipse.
 * \param y La coordonnée en Y du centre de l'ellipse.
 * \param radius_x Le rayon en X de l'ellipse.
 * \param radius_y Le rayon en Y de l'ellipse.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_filled_ellipse_on_image(
	int x, int y, int radius_x, int radius_y, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine un polygone à partir d'une liste de sommets dans une image.
 *
 * \param vx La liste des coordonnées en X des différents sommets du polygone.
 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
 * \param nb_points Le nombre de sommets du polygone.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_polygon_on_image(
	const int* vx, const int* vy, int nb_points, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine un polygone plein à partir d'une liste de sommets dans une
 *        image.
 *
 * \param vx La liste des coordonnées en X des différents sommets du polygone.
 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
 * \param nb_points Le nombre de sommets du polygone.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_filled_polygon_on_image(
	const int* vx, const int* vy, int nb_points, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine une courbe de Bézier à partir d'une liste de sommets dans une
 *        image.
 *
 * \param vx La liste des coordonnées en X des différents sommets de la courbe.
 * \param vy La liste des coordonnées en Y des différents sommets de la courbe.
 * \param nb_points Le nombre de sommets disponibles pour dessiner la courbe de
 *                Bézier.
 * \param color La couleur du tracé.
 * \param image image dans laquelle la figure est dessinée 
 */
void MLV_draw_bezier_curve_on_image(
	const int* vx, const int* vy, int nb_points, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine un polygone plein à partir d'une liste de sommets dans une
 *        image.
 *
 * \param vx La liste des coordonnées en X des différents sommets du polygone.
 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
 * \param nb_points Le nombre de sommets du polygone.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée 
 */
void MLV_draw_filled_polygon_on_image(
	const int* vx, const int* vy, int nb_points, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine un rectangle dont la taille, la couleur et la position du
 *        sommet Nord-Ouest sont données en paramètres dans une image.
 *
 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
 * \param width La largeur du rectangle.
 * \param height La hauteur du rectangle.
 * \param color La couleur du rectangle.
 * \param image L'image dans laquelle la figure est dessinée .
 */
void MLV_draw_rectangle_on_image(
	int x, int y, int width, int height, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine un rectangle dont la taille, la couleur et la position du 
 *        sommet Nord-Ouest sont données en paramètres dans une image.
 *
 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
 * \param width La largeur du rectangle.
 * \param height La hauteur du rectangle.
 * \param color La couleur du rectangle.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_rectangle_on_image(
	int x, int y, int width, int height, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine un rectangle plein dont la taille, la couleur et la position
 *        du sommet Nord-Ouest sont données en paramètres dans une image.
 *
 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
 * \param width La largeur du rectangle.
 * \param height La hauteur du rectangle.
 * \param color La couleur du rectangle.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_filled_rectangle_on_image(
	int x, int y, int width, int height, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine une ligne dans une image.
 *
 * \param x1 La coordonnée en X de la première extrémité de la ligne.
 * \param y1 La coordonnée en Y de la première extrémité de la ligne.
 * \param x2 La coordonnée en X de la deuxième extrémité de la ligne.
 * \param y2 La coordonnée en Y de la deuxième extrémité de la ligne.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_line_on_image(
	int x1, int y1, int x2, int y2, MLV_Color color, MLV_Image* image
);

/** \~french 
 * \brief Dessine un pixel dont les coordonnées sont passées en paramètres dans
 *        une image.
 *
 * \param x Coordonnée en X du pixel
 * \param y Coordonnée en Y du pixel
 * \param color Couleur du tracé
 * \param image image dans laquelle la figure est dessinée 
 */
void MLV_draw_pixel_on_image(int x, int y, MLV_Color color, MLV_Image* image);

/** \~french 
 * \brief Dessine un point dont les coordonnées sont passées en paramètres.
 *        Cette fonction est identique à MLV_draw_pixel dans une image.
 *
 * \param x La coordonnée en X du point.
 * \param y La coordonnée en Y du point.
 * \param color La couleur du tracé.
 * \param image L'image dans laquelle la figure est dessinée.
 */
void MLV_draw_point_on_image(int x, int y, MLV_Color color, MLV_Image* image);


#ifdef __cplusplus
}
#endif

#endif
