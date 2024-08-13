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
 * \file MLV_image.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit tous les prototypes concernant les fonctions
 * permettant d'insérer des images.
 */

#ifndef __MLV__MLV_IMAGE_H__
#define __MLV__MLV_IMAGE_H__

#include "MLV_color.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Définit le type Image dans la bibliothèque MLV.
 *
 * Une image dans la bibliothèque MLV est un tableau à deux dimentions
 * dont chaque entée contient une couleur (voir MLV_Color).
 * Nous rapellons que dans MLV les couleurs sont définies à l'aide de 4 
 * entiers compris entre 0 et 256 exclu, que l'on appelle composantes : 
 * - la composante Rouge ( R );
 * - la composante Verte ( G );
 * - la composant Blue ( B );
 * - la composante Alpha, c'est la transparence ( A ).
 *
 */
typedef struct _MLV_Image MLV_Image;

/** \~french 
 * \brief Charge en mémoire une image contenue dans un fichier.
 *
 * Cette fonction permet de charger les images des formats suivants:
 * ICO(Icon)/CUR(Cursor)/BMP, PNM (PPM/PGM/PBM), XPM, LBM(IFF ILBM), PCX, GIF, 
 * JPEG, PNG, TGA, TIFF, and XV.
 *
 * \bug Cette fonction provoque une erreur de segmentation si elle est utilisée
 *      avant MLV_create_window(). Pour l'instant, nous vous conseillons
 *      d'utiliser cette fonction apres MLV_create_window().
 *
 * \bug Il est possible que cette fonction n'arrive pas à charger correctement
 *      les images qui ne sont pas en 32 bits (RGBA) - bug à tester.
 *
 * \bug BUG PRESENT SOUS WINDOWS ET MACOS X : Lorsque la composante alpha d'un 
 *      pixel est à 0, MLV_load_image met à 0 les composantes Rouge, Verte 
 *      et bleue du pixel associé. Ce bug provient de la bibliothèque SDL_image.
 *
 * \param file_image Chemin d'accès du fichier contenant l'image.
 * \return L'image chargée.
 */
MLV_Image* MLV_load_image( const char* file_image );


/** \~french 
 * \brief Sauvegarde une image dans une fichier BMP.
 *
 * \bug Cette fonction ne sauvegarde pas la composante alpha.
 *
 * \param image Image à sauvegarder
 * \param file_image Chemin d'accès du fichier contenant l'image.
 * \return 0 si c'est un succés, -1 s'il y a eut une erreur.
 */
int MLV_save_image_as_bmp( const MLV_Image* image,  const char* file_image );

/** \~french 
 * \brief Créer une image de composante alpha opaque.
 *
 * \param width Largeur de l'image
 * \param height Hauteur de l'image
 * \return L'image créé.
 */
MLV_Image* MLV_create_image( int width, int height );

/** \~french 
 * \brief Libère la mémoire utilisée par l'image.
 *
 * \param image Image à supprimer de la mémoire
 */
void MLV_free_image( MLV_Image *image );

/** \~french 
 * \brief Copie une image.
 *
 * Cette fonction créé une nouvelle image qui est la copie conforme de l'image
 * passée en paramètre.
 * La gestion de la mémoire de l'image créée est laissée à l'utilisateur.
 *
 * \param image L'image à copier.
 * \return La copie de l'image.
 */
MLV_Image* MLV_copy_image( const MLV_Image* image );

/** \~french 
 * \brief Copie une partie de l'image.
 *
 * Cette fonction créé une nouvelle image qui est la copie conforme d'une partie
 * de l'image passée en paramètre.
 * La gestion de la mémoire de l'image créée est laissée à l'utilisateur.
 *
 * \param image L'image à copier.
 * \param x Abscisse du sommet Nord-Ouest de la partie de l'image à copier
 * \param y Ordonnée du sommet Nord-Ouest de la partie de l'image à copier
 * \param width Largeur de la partie de l'image à copier
 * \param height Hauteur de la partie de l'image à copier
 * \return La copie de l'image.
 */
MLV_Image* MLV_copy_partial_image(
	const MLV_Image* image, int x, int y, int width, int height
);

/** \~french 
 * \brief Retourne la taille d'une image donnée.
 *
 * \param image L'image pour laquelle la fonction doit retourner sa taille.
 * \param width La largeur de l'image.
 * \param height La hauteur de l'image.
 */
void MLV_get_image_size( const MLV_Image* image, int* width, int* height );

/** \~french 
 * \brief Retourne la largeur d'une image donnée.
 *
 * \param image L'image à analyser.
 * \return La largeur de l'image.
 */
int MLV_get_image_width( const MLV_Image* image );

/** \~french 
 * \brief Retourne la hauteur d'une image donnée.
 *
 * \param image L'image à analyser.
 * \return La hauteur de l'image
 */
int MLV_get_image_height( const MLV_Image* image );


/** \~french 
 * \brief Redimensionne l'image en ne respectant pas les proportions de l'image
 *        originale.
 *
 * La hauteur et la largeur de la nouvelle image deviennent respectivement la 
 * hauteur et la largeur passées en paramètres.
 *
 * \param image L'image à redimentionner.
 * \param width La largeur de l'image.
 * \param height La hauteur de l'image.
 */
void MLV_resize_image( MLV_Image* image, int width, int height );

/** \~french 
 * \brief Modifie l'image en réalisant une réflexion verticale.
 *
 * \param image L'image à modifier.
 */ 
void MLV_vertical_image_mirror( MLV_Image* image );

/** \~french 
 * \brief Modifie l'image en réalisant une réflexion horizontale.
 *
 * \param image L'image à modifier.
 */ 
void MLV_horizontal_image_mirror( MLV_Image* image );

/** \~french 
 * \brief Cette fonction redimensionne l'image en repsectant les proportions 
 *        de l'image originale.
 *
 * L'image résultat est la plus grande image possible incluse dans le rectangle
 * de largeur width et de hauteur height.
 *
 * L'utilisateur peut entrer un entier négatif pour les champs width et height.
 * Ces champs ne sont alors pas pris en compte dans le redimensionnement de 
 * l'image. Dans ce cas, si le paramètre width (resp. height) est 
 * négatif, alors l'image finale aura pour largeur (resp. hauteur) la taille 
 * spécifiée dans le paramètre width (resp. height).
 *
 * \param image L'image à redimentionner.
 * \param width La nouvelle largeur de l'image.
 * \param height La nouvlle hauteur de l'image.
 */ 
void MLV_resize_image_with_proportions(
	MLV_Image* image, int width, int height
);

/** \~french 
 * \brief Modifie l'image à l'aide d'une homotétie ( Étire l'image )
 *
 * \param image L'image à modifier.
 * \param scalar Coefficient de proportionalité de l'homotétie ( >1 l'image est
 *               agrandie, <1 l'image est rétrécie ). 
 */
void MLV_scale_image( MLV_Image* image, double scalar );

/** \~french 
 * \brief Éffectue une rotation sur une image donnée.
 *
 * \param image L'image à modifier.
 * \param rotation L'angle de la rotation.
 */
void MLV_rotate_image( MLV_Image* image, double rotation );

/** \~french 
 * \brief Éffectue une rotation suivie d'une homotétie
 *
 * \param image L'image à modifier.
 * \param rotation L'angle de la rotation.
 * \param scalar Le coéfficient de proportionnalité de l'homotétie.
 */
void MLV_rotate_and_scale_image( MLV_Image* image, double rotation, double scalar );

/** \~french 
 * \brief Étire l'image suivant l'axe X et l'axe Y avec des coefficients de 
 *        proportionnalité différents pour les deux axes.
 *
 * \param image L'image à modifier.
 * \param scalar_x Le coéfficient de proportionnalité de l'axe X.
 * \param scalar_y Le coéfficient de proportionnalité de l'axe Y.
 */
void MLV_scale_xy_image( MLV_Image* image, double scalar_x, double scalar_y );

/** \~french 
 * \brief Éffectue une rotation, puis étire l'image suivant l'axe X et l'axe Y
 *        avec des coefficients de proportionnalité différents pour les deux
 *        axes.
 *
 * \param image L'image à modifier.
 * \param rotation L'angle de la rotaiton.
 * \param scalar_x Le coéfficient de proportionnalité de l'axe X.
 * \param scalar_y Le coéfficient de proportionnalité de l'axe Y.
 *
 */
void MLV_rotate_and_scale_xy_image(
	MLV_Image* image, double rotation, double scalar_x, double scalar_y 
);

/** \~french 
 * \brief Dessine une image donnée à une position donnée de la fenêtre.
 *
 * \param image Image à dessiner.
 * \param x Coordonnée en X de la position dans la fenêtre de sommet Nord-Ouest
 *          de l'image.
 * \param y Coordonnée en Y de la position dans la fenêtre du sommet Nord-Ouest
 *          de l'image.
 */
void MLV_draw_image( const MLV_Image *image, int x, int y );

/** \~french 
 * \brief Dessine une partie d'une image donnée à une position donnée sur la 
 *        fenêtre.
 * \param image L'image à afficher sur la fenêtre
 * \param x_source La coordonnée en X du sommet Nord-Ouest de la partie de
 *                 l'image à afficher.
 * \param y_source La coordonnée en Y du sommet Nord-Ouest de la partie de 
 *                 l'image à afficher.
 * \param width_source La largeur de la partie de l'image à afficher.
 * \param height_source La hauteur de la partie de l'image à afficher.
 * \param x Coordonnée en X de la position dans la fenêtre du sommet Nord-Ouest
 *          de la partie de l'image à afficher.
 * \param y Coordonnée en Y de la position dans la fenêtre du sommet Nord-Ouest
 *          de la partie de l'image à afficher.
 */
void MLV_draw_partial_image(
	const MLV_Image *image, int x_source, int y_source, 
	int width_source, int height_source, 
	int x, int y
);


/** \~french 
 * \brief La composante alpha de l'image est remplacée par une composante
 *        alpha homogène dont la valeur est donnée en paramètre.
 *
 * La transparence joue un role lorsqu'une image est dessinée à l'écran, ou
 * lorsqu'une image est recopiée à l'intérieure d'une autre image.
 * Lorsque l'on recopie une image, les pixels du résultat final sont obtenus en
 * faisant un barycentre entre le pixel de l'image source avec celui de l'image
 * destination. Les poids des barycentres sont définis par la composante 
 * transparente ( composante alpha ) de l'image source.
 * La transparence de l'image destination reste inchangée.
 *
 * Par exemple,
 * \verbatim
couleur pixel source : RGBA( 60,80,100,128 )
couleur destination : RGBA( 0,20,40,30 )
couleur final après recopie : 
  RGBA(  
    barycentre( 60,  128,  0,   256-128 ),
    barycentre( 80,  128,  20,  256-128 ),
    barycentre( 100, 128,  40,  256-128 ),
    30
 ) =
 RGBA(
     ( 60  * 128  +  0  * (256-128) ) / 256,
     ( 80  * 128  +  20 * (256-128) ) / 256,
     ( 100 * 128  +  40 * (256-128) ) / 256,
     30
 ) =
 RGBA( 30, 50, 70, 30 )
\endverbatim
 *
 * \param image L'image à modifier.
 * \param alpha La nouvelle composante alpha de l'image.
 */
void MLV_set_alpha_on_image( MLV_Alpha alpha, MLV_Image *image );

/** \~french
 *
 * \brief Écrase les composantes rouge, bleue, vert et alpha d'un pixel par 
 *        celles passées en paramètre de la fonction.
 *
 * \param x La coordonnée en x du pixel à modifier.
 * \param y La coordonnée en y du pixel à modifier.
 * \param color La nouvelle couleur du pixel.
 * \param image  L'image à modifier.
 */
void MLV_set_pixel_on_image(
	int x, int y,
	MLV_Color color, 
	MLV_Image *image
);

/** \~french 
 * \brief Renvoie la couleur du pixel de l'écran pour une position donnée.
 *
 * Les paramètres red, blue, green et alpha peuvent être égaux à 0. Dans ce
 * cas, ils sont ignorés.
 *
 * \param x Coordonnée en X de la position du pixel.
 * \param y Coordonnée en Y de la position du pixel.
 * \param red Composante rouge du pixel.
 * \param green Composante verte du pixel.
 * \param blue Composante bleue du pixel.
 * \param alpha Composante alpha (transparence) du pixel.
 */
void MLV_get_pixel(
	int x, int y, int* red, int* green, int* blue, int* alpha
);

/** \~french 
 * \brief Renvoie la couleur du pixel présent à une position donnée d'une image
 *        donnée.
 *
 * Les paramètres red, blue, green et alpha peuvent être égaux à NULL. Dans ce
 * cas, ils sont ignorés.
 *
 * \param image Image à inspecter.
 * \param x Coordonnée en X de la position du pixel à inspecter.
 * \param y Coordonnée en Y de la position du pixel à inspecter.
 * \param red Composante rouge du pixel.
 * \param green Composante verte du pixel.
 * \param blue Composante bleue du pixel.
 * \param alpha Composante alpha (transparence) du pixel.
 */
void MLV_get_pixel_on_image(
	const MLV_Image* image, int x, int y,
	int* red, int* green, int* blue, int* alpha
);

/** \~french 
 * \brief Dessine une image dans une image destination
 *
 * \param source_image Image source
 * \param source_x Abscisse du sommet nord-Ouest de la position de la portion
 *                 d'image à recopier
 * \param source_y Ordonné du sommet nord-Ouest de la position de la portion
 *                 d'image à recopier
 * \param width Largeur de la position à recopier
 * \param height Hauteur de la position à recopier
 * \param destination_image Image destination
 * \param destination_x Abscisse de la position où devra être recopier l'image.
 *                      Il s'agit de la futur position du sommet nord-Ouest de 
 *                      la portion d'image à recopier.
 * \param destination_y Ordonnée de la position où devra être recopier l'image.
 *                      Il s'agit de la futur position du sommet nord-Ouest de 
 *                      la portion d'image à recopier.
 */
void MLV_draw_partial_image_on_image(
	const MLV_Image* source_image,
	int source_x, int source_y,
	int width, int height,
	MLV_Image* destination_image,
	int destination_x, int destination_y
);

/** \~french 
 * \brief Dessine une image dans une image destination
 *
 * \param source_image Image source
 * \param destination_image Image destination
 * \param destination_x Abscisse de la position où devra être recopier l'image.
 *                      Il s'agit de la futur position du sommet nord-Ouest de 
 *                      la portion d'image à recopier.
 * \param destination_y Ordonnée de la position où devra être recopier l'image.
 *                      Il s'agit de la futur position du sommet nord-Ouest de 
 *                      la portion d'image à recopier.
 */
void MLV_draw_image_on_image(
	const MLV_Image* source_image,
	MLV_Image* destination_image,
	int destination_x, int destination_y
);

/** \~french
 * \brief Renvoie les données internes de l'image.
 *
 * Cette fonction renvoie un pointeur vers la structure de donnée 
 * de la libriaire SDL codant une image.
 *
 * N'utilisez cette fonction que si vous souhaitez effectuer une opération
 * sur une image qui n'existe pas dans la bibliothèque MLV.
 * En effet, modifier les données internes d'une image de type MLV_Image 
 * peut corrompre le fonctionnement de la bibliothèque MLV.
 *
 * Vous pouvez alors utiliser les routines de la lirairie SDL pour 
 * modifier l'image. (http://libsdl.org)
 *
 * Voici un exemple de code montrant comment il est possible de récupérer les 
 * composantes rouge, vert, bleu et alpha du pixel (3,4) de l'image.
 *
 * \code
 * int x=3, y=4;
 *
 * SDL_Surface* surface = MLV_get_image_data( image );
 * Uint32 red, blue, green, alpha;
 * 
 * // Extracting color components from a 32-bit color value
 * SDL_PixelFormat *fmt;
 * Uint32 pixel;
 * 
 * SDL_LockSurface(surface);
 * fmt = surface->format;
 * pixel = *(((Uint32*) surface->pixels)+ y*surface->pitch/4 + x  );
 * 
 * // Get Red component
 * red = pixel & fmt->Rmask;  // Isolate red component
 * red = red >> fmt->Rshift; // Shift it down to 8-bit
 * red = red << fmt->Rloss;  // Expand to a full 8-bit number
 * 
 * // Get Green component
 * green = pixel & fmt->Gmask;  // Isolate green component
 * green = green >> fmt->Gshift; // Shift it down to 8-bit
 * green = green << fmt->Gloss;  // Expand to a full 8-bit number
 * 
 * // Get Blue component
 * blue = pixel & fmt->Bmask;  // Isolate blue component
 * blue = blue >> fmt->Bshift; // Shift it down to 8-bit
 * blue = blue << fmt->Bloss;  // Expand to a full 8-bit number
 * 
 * // Get Alpha component 
 * alpha = pixel & fmt->Amask;  // Isolate alpha component
 * alpha = alpha >> fmt->Ashift; // Shift it down to 8-bit
 * alpha = alpha << fmt->Aloss;  // Expand to a full 8-bit number
 *
 * MLV_unlock_image( image );
 * \endcode
 *
 * \param image L'image dont vous souhaitez récuperer les données internes.
 * \return un pointeur vers une image de la bibliothèque SDL.
 */
SDL_Surface* MLV_get_image_data( MLV_Image* image );

/** \~french 
 * \brief Enregistre l'image de l'écran dans un presse papier interne à la 
 *        bibliothèque MLV..
 *
 */
void MLV_save_screen();

/** \~french 
 * \brief Charge l'image présent dans le presse papier interne de la bibliothèque
 *        MLV.
 *
 */
void MLV_load_screen();

// TODO
#if 0
/** \~french 
 * \brief Enmére différents types d'opérations mathématiques.
 *
 */
typedef enum {
	MLV_NONE,
	MLV_REPLACE,
	MLV_MAX,
	MLV_MIN,
	MLV_BARYCENTER
} MLV_Mathematic_operations;


/** \~french 
 * \brief Dessine une image dans une image destination
 *
 * Cette fonction offre diférentes façon de dessiner une image
 * dans une autre.
 * Ces différentes façon concerne d'une part les couveh RGB 
 * ( rouge-vert-bleue) de l'image et d'autre part la couche alpha
 * Les différentes façons sont décrites par les paramètres : rgb_treatment
 * et alpha_treatment
 * Voici un tableau récapitulatif des effets obtenus
 * Opération ........ Éffet
 *	MLV_NONE ........ Les composante destination sont laissée intactes       
 *	MLV_REPLACE ..... Les composantes contenues dans l'image destinatiion sont
 *                    remplacées par celle de l'image source
 *	MLV_MAX ......... La composante maximale entre source et destination est 
 *                    stocké dans l'image destination
 *	MLV_MIN ......... La composante minimale entre source et destination est 
 *                    stocké dans l'image destination
 *	MLV_BARYCENTER .. Cette opération n'est définit que pour les composantes 
 *                    RGB. La composane destination est obtenu en faisant un 
 *                    barycentre entre l'image source et l'image destination 
 *                    en utilisant la composante alpha de l'image source.
 *
 *
 * \param source_image Image source
 * \param source_x Abscisse du sommet nord-Ouest de la position de la portion 
 *                 d'image à recopier
 * \param source_y Ordonné du sommet nord-Ouest de la position de la portion 
 *                 d'image à recopier
 * \param with Largeur de la position à recopier
 * \param height Hauteur de la position à recopier
 * \param destination_image Image destination
 * \param destination_x Abscisse de la position où devra être recopier l'image.
 *                      Il s'agit de la futur position du sommet nord-Ouest de 
 *                      la portion d'image à recopier.
 * \param destination_y Ordonnée de la position où devra être recopier l'image.
 *                      Il s'agit de la futur position du sommet nord-Ouest de
 *                      la portion d'image à recopier.
 * \param rgb_treatment Opération mathématique à appliquer pour traiter les 
 *                      composantes RGB de l'image
 * \param alpha_treatment Opération mathématique à appliquer pour traiter la 
 *                        composante alpha de l'image
 */
void MLV_draw_partial_image_on_image(
	const MLV_Image* source_image,
	int source_x, int source_y,
	int with, int height,
	MLV_Image* destination_image,
	int destination_x, int destination_y,
	MLV_Mathematic_operations rgb_treatment,
	MLV_Mathematic_operations alpha_treatment
);

/** \~french 
 * \brief Dessine une image dans une image destination en utilisant
 *        l'accélération de la carte graphique.
 *
 * Les couleurs RGB des images sources et destinations sont mélangé suivant
 * les proportions préssentes dans la couches alpha de l'image" source.
 * Par exemple, si pour un pixel de l'image, la composant alpha 
 * vaut 200, alors le pixal final sera composé à 200/255 de la couleur de 
 * l'image source et de 255-200/255 = 55/200 de l'image destination.
 * La composant alpha de l'image destination reste inchangée.
 *
 * Cette opération est identique à 
 *     MLV_draw_partial_image_on_image(
 *			X,X,X,X,X,X,X,X,
 *			MLV_BARYCENTER,
 *			MLV_NONE,
 *      );
 * Cependant, MLV_draw_partial_image_on_image_FAST est un opération 
 * qui bénéficie d'optimisation par la carte graphique.
 *
 * \param source_image Image source
 * \param source_x Abscisse du sommet nord-Ouest de la position de la portion 
 *                 d'image à recopier
 * \param source_y Ordonné du sommet nord-Ouest de la position de la portion 
 *                 d'image à recopier
 * \param with Largeur de la position à recopier
 * \param height Hauteur de la position à recopier
 * \param destination_image Image destination
 * \param destination_x Abscisse de la position où devra être recopier l'image.
 *                      Il s'agit de la futur position du sommet nord-Ouest de
 *                      la portion d'image à recopier.
 * \param destination_y Ordonnée de la position où devra être recopier l'image.
 *                      Il s'agit de la futur position du sommet nord-Ouest de 
 *                      la portion d'image à recopier.
 */
void MLV_draw_partial_image_on_image_FAST(
	const MLV_Image* source_image,
	int source_x, int source_y,
	int with, int height,
	const MLV_Image* destination_image,
	int destination_x, int destination_y
);
#endif

/* TODO  : A Vérifier !
void MLV_draw_rotated_image(  MLV_Image *image, int x, int y, double rotation );
void MLV_draw_scaled_image(  MLV_Image *image, int x, int y, double scalar );
void MLV_draw_scaled_rotated_image(  MLV_Image *image, int x, int y, double roation, double scalar );
*/

#ifdef __cplusplus
}
#endif

#endif
