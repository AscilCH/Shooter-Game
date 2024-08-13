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
 * \file MLV_animation.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * Cette interface est inspiré du tutoriel : 
 * http://www.gnurou.org/writing/linuxmag/sdl/partie3
 *
 * \brief Ce fichier définit les prototypes des fonctions permettant de mettre 
 *        en oeuvre des animations.
 */

#ifndef __MLV__MLV_ANIMATION_H__
#define __MLV__MLV_ANIMATION_H__

#include "MLV_image.h"
#include "MLV_audio.h"

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////
//    Animation data
///////////////////////////////////////////////

/** \~french 
 * \brief Ce type code une animation.
 * 
 * Une animation est une succéssion de k+l+1 uplets.
 * Chaque uplet contient :
 *   - k images,
 *   - l sons,
 *   - 1 temps d'affichage
 * Les k images correspondent à k représentations différentes d'une
 * même scène animée.
 * Les l sons correspondent à l différents fonds sonores pour la 
 * même scène animée.
 * Le temps d'affichage est le temps d'affichage des images dans 
 * l'animation.
 * 
 * On appelle "couche graphique i", l'ensemble des images situées à la 
 * position i du k+l+1-uplet.
 * On appelle "couche sonore j", l'ensemble des sons situées à la 
 * position k+j du k+l+1-uplet.
 *
 * Voici la Structure d'une animatione représentée à l'aide d'un tableau :
 *
 * \verbatim
|-------------------------------------------------------------|
|   MLV_Animation                                             |
|-------------------------------------------------------------|
|                                                             |
|   Couche graphique 0    |  Image    Image    Image    ...   |
|   Couche graphique 1    |  Image    Image    Image    ...   |
|      ...                |   ...      ...      ...     ...   |
|   Couche graphique k-1  |  Image    Image    Image    ...   |
|   -------------------------------------------------------   |
|   Couche sonore 0       |   Son      Son      Son     ...   |
|   Couche sonore 1       |   Son      Son      Son     ...   |
|      ...                |   ...      ...      ...     ...   |
|   Couche sonore k-1     |   Son      Son      Son     ...   |
|   -------------------------------------------------------   |
|   Temps d'affichage     |    1        3        1      ...   |
|                                                             |
|-------------------------------------------------------------|
\endverbatim
 *
 */
typedef struct _MLV_Animation MLV_Animation;

/** \~french 
 * \brief Créé une animation comportant un nombre d'image donné
 *
 * Une animationV est une succession d'image où à chaque image est 
 * associé un temps. Ce temps code le temps d'affichage de chaque image, 
 * lors du rendu de de l'animation.
 * Pour des raisons de commodité, nos séquence d'animations sont composés de 
 * plusieurs  couches. Elles sont donc des successions de couches contenant 
 * chacunes une image.
 *
 * Une sequence d'animation (à ne pas confondre avec une animation) est une 
 * pure structure de donnée. Elle peut donc pas s'animer, ni s'afficher à 
 * l'ecran.
 * Pour afficher une séquence d'animation, il faut utiliser une animation, 
 * qui s'aidera de la séquence d'animation pour s'afficher ou pour mettre en
 * mouvement les images de la séquence d'animation.
 *
 * Le temps d'une s'quence d'animation n'est pas codée en secondes. Il s'agit 
 * d'un entier. Lorsque vous utilisez une animation, l'animateur à un temps qui
 * lui est propre et qui est codé à l'aide d'un entier qui croit. Les duree que
 * vous ajouterez dans l'animation sont donc définit par rapport au temps de 
 * l'animation qui utilise la séquence d'animation.
 *
 * \param nb_frames Le nombre d'image que doit contenir l'animation
 * \param nb_layers Nombre de couches graphique de l'animation.
 * \param nb_channels Nombre de canaux sonore de l'animation.
 * \return Un pointeur vers une animation.
 */
MLV_Animation* MLV_create_animation(
	unsigned int nb_frames,	unsigned int nb_layers,	unsigned int nb_channels
);

/** \~french 
 * \brief Cette fonction libère les données allouées pour l'animation
 *
 * \param animation L'animation à fermer. 
 */
void MLV_free_animation( MLV_Animation* animation );

/** \~french 
 * \brief Change un animation en remplacant une image et son temps d'affichage 
 *        associé. L'image concerné est repéré à l'aide de son index et de
 *        l'index de la couche où elle appartient.
 *
 * \param array_of_images Un tableau d'adresse contenant les addresses de images
 *                        correspondat aux différentes couches d'une animation.
 * \param array_of_sounds Un tableau d'adresse contenant les addresses de sons
 *                        correspondant aux différentes canaux d'une animation.
 * \param delay temps d'affichage de l'image
 * \param animation Animation à modifier
 * \param position position de l'image dans l'animation
 */
void MLV_change_frame_in_animation(
	MLV_Image** array_of_images, MLV_Sound** array_of_sounds, unsigned int delay,
	MLV_Animation* animation, unsigned int position
);

/** \~french 
 * \brief Change un animation en remplacant uniquement une image.
 *        L'image concerné est repéré à l'aide de son index et de
 *        de l'index de sa couche.
 *
 * \param image image a ajouter dans l'animation
 * \param animation Animation à modifier
 * \param position position de l'image dans l'animation
 * \param layer     Couche de l'image.
 */
void MLV_change_frame_image_in_animation(
	MLV_Image* image, MLV_Animation* animation, unsigned int position,
	unsigned int layer
);

/** \~french 
 * \brief Change un animation en remplacant uniquement un bruitage.
 *        Le son image concerné est repéré à l'aide de son index et de
 *        de l'index de son canaul.
 *
 * \param sound     son a ajouter dans l'animation
 * \param animation Animation à modifier
 * \param position  position de l'image dans l'animation
 * \param channel   Canal du son.
 */
void MLV_change_frame_sound_in_animation(
	MLV_Sound* sound, MLV_Animation* animation, unsigned int position,
	unsigned int channel
);

/** \~french 
 * \brief Change le temps d'affichage d'une image donnée d'une animation.
 *
 * \param delay temps d'affichage de l'image
 * \param animation Animation à modifier
 * \param position position de l'image dans l'animation
 */
void MLV_change_frame_delay_in_animation(
	unsigned int delay, MLV_Animation* animation, unsigned int position
);

/** \~french 
 * \brief Recupère l'image et le temps présents à une position et une couche 
 *        donnée d'une animation.
 *
 * \param animation Animation à modifier
 * \param layer Couche de l'image.
 * \param position position de l'image dans l'animation
 * \param image image a ajouter dans l'animation
 * \param delay temps d'affichage de l'image
 */
void MLV_get_frame_from_animation(
	MLV_Animation* animation, unsigned int position,
	unsigned int layer,
	MLV_Image** image, unsigned int* delay
);



/** \~french 
 * \brief Renvoie le temps d'affichage de l'image  présente à une position 
 *        donnée d'une animation donnée.
 *
 * \param animation Animation à modifier
 * \param position position de l'image dans l'animation
 *
 * \return le temps d'affichage de l'image
 */
int MLV_get_frame_delay_from_animation(
	MLV_Animation* animation, unsigned int position
);

/** \~french 
 * \brief Renvoie l'image présente à une position et une couche donnée d'une
 *        animation donnée.
 *
 * \param animation Animation à modifier
 * \param position position de l'image dans l'animation
 * \param layer Couche de l'image.
 *
 * \return l'image extraite.
 */
MLV_Image* MLV_get_frame_image_from_animation(
	MLV_Animation* animation, unsigned int position,
	unsigned int layer
);




////////////////////////////////////////////////
//    Animation engine
///////////////////////////////////////////////

/** \~french 
 * \brief Ce type code un lecteur d'animation.
 *
 * Un lecteur d'animation est une structure qui permet d'animer une animation.
 * Cette structure contient :
 *   - un pointeur vers une animation
 *   - la position de l'image courante de l'animation
 *   - une horloge interne ( dont le temps est discret et indépendant du temps courant )
 *
 * 
 *
 * L'aiguille de l'horologe interne d'une animation avance d'une unité 
 * à chaque appel de la fonction MLV_update_animation_player().
 * Les animations sont alors jouée en fonction de l'évolution du temps de chaque
 * animateur. Ainsi, deux lecteurs différents peuvent avoir une courbe du
 * temps différente.
 *
 * La bonne façon d'utiliser des lecteurs est de mettre a jour tous les
 * lecteurs en même temps à un intervalle de temps régulier.
 * Pour cela vous pouvez utiliser la fonction framerate qui endort le programme 
 * de façon a assurer l'execution d'un tour de boucle à une fréquence donnée
 *
 * Voici un exemple d'utilisation du lecteur :
 * \code
 * MLV_Image* creature1 = MLV_load_image("creature1.png");
 * MLV_Image* creature2 = MLV_load_image("creature2.png");
 * int time_per_image = 1;
 *
 * MLV_Animation* animation;
 * animation = MLV_create_animation( 2 );
 * MLV_change_frame_in_animation( creature1, time_per_image, animation, 0 );
 * MLV_change_frame_in_animation( creature2, time_per_image, animation, 0 );
 *
 * MLV_Animation_player* animation_player; 
 * animation_player = MLV_create_animation_player( animation );
 *
 * int frequence = 24; // nombre d'images par secondes
 * MLV_change_frame_rate( frequence );
 * while( 1 ){ 
 *     MLV_update_animation_player( animation_player );
 *     MLV_draw_image_from_animation_player(0, 0, 0, animation_player);
 *     MLV_frame_rate_delay();
 * }
 * \endcode
 *
 */
typedef struct _MLV_Animation_player MLV_Animation_player;


/** \~french 
 * \brief Cree un lecteur d'animation et l'initialise avec une animation donnée en
 *        paramètre.
 *
 * \param animation L'animation que devra animer l'animateur.
 *
 * \return L'animateur créé.
 */
MLV_Animation_player* MLV_create_animation_player( MLV_Animation* animation );

/** \~french 
 * \brief Libère l'espace mémoire alloué pour un animateur donné.
 *
 * \param animation_player Le lecteur d'animation à suprimer
 */
void MLV_free_animation_player( MLV_Animation_player* animation_player );

/** \~french 
 * \brief Demare la lecture de l'animation lu par le lecteur d'animation.
 *
 * \param animation_player Le lecteur d'animation
 */
void MLV_play_animation_player( MLV_Animation_player* animation_player );

/** \~french 
 * \brief Demande à un lecteur d'animation donné de jouer l'animation à l'envers.
 *
 * \param animation_player Le lecteur d'animation
 */
void MLV_play_revert_animation_player( MLV_Animation_player* animation_player );

/** \~french 
 * \brief Met en pause la lecture d'un lecteur d'animation donné.
 *
 * \param animation_player Le lecteur d'animation
 */
void MLV_stop_animation_player( MLV_Animation_player* animation_player );

/** \~french 
 * \brief Demande à l'animateur de reprendre la lecture de l'animation depuis le
 *        début.
 *
 * \param animation_player Le lecteur d'animation
 */
void MLV_rewind_animation_player( MLV_Animation_player* animation_player );

/** \~french 
 * \brief Force le lecteur d'animation à passer à l'image suivante.
 *
 * \param animation_player Le lecteur d'animation
 */
void MLV_next_frame( MLV_Animation_player* animation_player );

/** \~french 
 * \brief Force l'animateur à revenir sur l'image précédente.
 *
 * \param animation_player Le lecteur d'animation
 */
void MLV_previous_frame( MLV_Animation_player* animation_player );

/** \~french 
 * \brief Met a jour un lecteur d'animation.
 *
 * L'horloge interne du lecteur voit son temps incrémenter de 1 unité
 * exactement.
 *
 * La position de lecture de l'animation est mis a jour en conséquence de la 
 * mis à jour de l'horloge interne.
 *
 * \param animation_player Le lecteur d'animation à mettre à jour
 */
void MLV_update_animation_player( MLV_Animation_player* animation_player );

/** \~french 
 * \brief Change le volume sonore d'un bruitage.
 *
 * \param animation_player L'animateur dans lequel se trouve le son.
 * \param channel Le canal concerné.
 * \param volume le nouveau volume sonore.
 */
void MLV_change_sound_volume_of_animation_player(
	MLV_Animation_player* animation_player, unsigned int channel, float volume
);

/** \~french 
 * \brief Active le son du canal d'un lecteur d'animation donnée.
 *
 * \param animation_player L'animateur concerné.
 * \param channel Le canal concerné.
 */
void MLV_turn_on_sound_of_animation_player(
	MLV_Animation_player* animation_player, unsigned int channel
);

/** \~french 
 * \brief Désactive le son du canal d'une animation donnée.
 *
 * \param animation_player L'animateur concerné.
 * \param channel Le canal concerné.
 */
void MLV_turn_off_sound_of_animation_player(
	MLV_Animation_player* animation_player, unsigned int channel
);


////////////////////////////////////////////////
//    Drawing animation
///////////////////////////////////////////////

/** \~french 
 * \brief Dessine à une position donnée l'image actuellement lue par 
 *        l'animateur. Cette image est situè à une couche donnée en paramètre.
 *
 * \param animation_player Le lecteur de l'animation à aficher
 * \param layer     Couche de l'image.
 * \param x         Coordonnée en X de la position du sommet Nord-Ouest de
 *                  l'image à afficher.
 * \param y         Coordonnée en Y de la position du sommet Nord-Ouest de
 *                  l'image à afficher.
 */
void MLV_draw_image_from_animation_player(
	MLV_Animation_player* animation_player, unsigned int layer,
	int x, int y
);

/** \~french 
 * \brief Joue le son d'une couche sonore donnée correspondant à l'image en 
 *        cours de lecture dans l'animation.
 *
 * Si le son a déjà été joué, cette fonction ne fait rien.
 *
 * \param animation_player Le lecteur de l'animation à aficher.
 * \param layer     Couche du son.
 */
void MLV_play_sound_from_animation_player(
	MLV_Animation_player* animation_player, unsigned int layer
);

/** \~french 
 * \brief Même chose que MLV_play_sound_from_animation_player() sauf que cette
 *        fonction permet de lancer plusieurs sons en même temps.
 *
 * La liste des couches sonores à jouer doivent être passé en paramètre 
 * (un paramètre par couche), et le dernier paramètre doit valoir -1 pour
 * dire à la fonction quand il doit s'arrêter.
 *
 * Par exemple, pour jouer les couches 2, 3 et 5 d'une animation, 
 * il suffit d'écrire: 
 *
 * \code
 * MLV_play_sounds_from_animation_player(
 *     animation,
 *     2, 3, 5,
 *     -1
 * ); 
 * \endcode
 *
 * \param animation_player Le lecteur de l'animation à aficher.
 * \param ... la liste des couches sonores, dont la veleure finale doit toujours être -1.
 */
void MLV_play_sounds_from_animation_player(
	MLV_Animation_player* animation_player,
	...
);

/** \~french 
 * \brief Même chose que MLV_play_sound_from_animation_player() sauf que cette
 *        fonction permet de lancer plusieurs sons en même temps.
 *
 * \param animation_player Le lecteur de l'animation à aficher.
 * \param layers     Tableau contenant les couches du son à jouer.
 * \param nb_layers Nombre de couches dans le tableau. 
 * \
 */
void MLV_play_list_of_sounds_from_animation_player(
	MLV_Animation_player* animation_player, unsigned int* layers,
	unsigned int nb_layers
);


/** \~french 
 * \brief Dessine à l'écran à une position donnée, une portion de 
 *        l'image actuellement lue par l'animateur et extraite de la 
 *        couche spécifiée en paramètre.
 *
 * \param animation_player Le lecteur de l'animation à aficher
 * \param layer     Couche de l'image.
 * \param image    image sur laquel il faut dessiner l'animation
 * \param source_x       Coordonnée en X de la position de la portion à recopier
 * \param source_y       Coordonnée en Y de la position de la portion à recopier
 * \param source_width   Largeur de la portion à recopier
 * \param source_height  Hauteur de la portion à recopier
 * \param x        Coordonnée en X de la position du sommet Nord-Ouest de
 *                 l'image à afficher.
 * \param y        Coordonnée en Y de la position du sommet Nord-Ouest de
 *                 l'image à afficher.
 */
void MLV_draw_partial_image_from_animation_player(
	MLV_Animation_player* animation_player, unsigned int layer,
	int source_x, int source_y, int source_width, int source_height,
	MLV_Image* image,
	int x, int y
);

/** \~french 
 * \brief Dessine sur une image donnée à une position donnée l'image 
 *        actuellement lue par l'animateur et située à une couche donnée.
 *
 * \param animation_player Le lecteur de l'animation à aficher
 * \param layer     Couche de l'image.
 * \param image    image sur laquel il faut dessiner l'animation
 * \param x        Coordonnée en X de la position du sommet Nord-Ouest de
 *                 l'image à afficher.
 * \param y        Coordonnée en Y de la position du sommet Nord-Ouest de
 *                 l'image à afficher.
 */
void MLV_draw_image_from_animation_player_on_image(
	MLV_Animation_player* animation_player, unsigned int layer,
	MLV_Image* image,
	int x, int y
);

/** \~french 
 * \brief Dessine sur une image donnée à une position donnée une portion de 
 *        l'image actuellement lue par l'animateur et située à une couche
 *        donnée.
 *
 * \param animation_player Le lecteru de l'animation à aficher
 * \param layer     Couche de l'image.
 * \param image    image sur laquel il faut dessiner l'animation
 * \param source_x       Coordonnée en X de la position de la portion à recopier
 * \param source_y       Coordonnée en Y de la position de la portion à recopier
 * \param source_width   Largeur de la portion à recopier
 * \param source_height  Hauteur de la portion à recopier
 * \param x        Coordonnée en X de la position du sommet Nord-Ouest de
 *                 l'image à afficher.
 * \param y        Coordonnée en Y de la position du sommet Nord-Ouest de
 *                 l'image à afficher.
 */
void MLV_draw_partial_image_from_animation_player_on_image(
	MLV_Animation_player* animation_player, unsigned int layer,
	int source_x, int source_y, int source_width, int source_height,
	MLV_Image* image,
	int x, int y
);




////////////////////////////////////////////////
//    Loading animations from files
///////////////////////////////////////////////

/** \~french 
 * \brief Ce type correspond à un livre contenant de nombreuses animations.
 * 
 * Un livre d'animations est un fichier XML qui code des animations.
 * Le type MLV_Animation_book code le contenu d'un live d'animation.
 *
 */
typedef struct _MLV_Animation_book MLV_Animation_book;


/** \~french 
 * \brief Charge en memoire un livre contenant une multitude d'animations.
 *
 * \param xml_file Fichiers xml.
 * \param image_directory Le dossier ou se trouve toutes les images du livre 
 *        d'animation. Si NULL est passe en parametre, alors le programme 
 *        cherche dans le repertoire du fichier de configuration du livre 
 *        d'animation.
 * \param sound_directory Le dossier ou se trouve toutes les échantillons
 *        sonore du livre d'animation. Si NULL est passe en parametre, 
 *        alors le programme cherche dans le repertoire du fichier de 
 *        configuration du livre d'animation.
 * \return L'adresse de la sructure de données contenant toutes les animations.
 */
MLV_Animation_book* MLV_load_animation_book(
	const char* xml_file,
	const char* image_directory,
	const char* sound_directory
);

/** \~french 
 * \brief Libère la memoire contenue par le livre d'animation.
 *
 * \param animation_book Le livre d'animation.
 */
void MLV_free_animation_book(
	MLV_Animation_book* animation_book
);

/** \~french 
 * \brief Détermine le nombre d'animations contenus par le livre d'animation.
 *
 * \param animation_book Le livre d'animation.
 * \return le nombre d'animations contenus par le livre d'animation.
 */
int MLV_get_number_of_animations(
	MLV_Animation_book* animation_book
);

/** \~french 
 * \brief Renvoie une animation donnée contenue dans le livre d'animation.
 *
 * \param animation_book Le livre d'animation.
 * \param id L'identifiant
 * \return La séquence d'animation.
 */
MLV_Animation* MLV_get_animation_from_id(
	MLV_Animation_book* animation_book,
	int id
);

/** \~french 
 * \brief Renvoie une animation donnée contenue dans le livre d'animation.
 *
 * \param animation_book Le livre d'animation.
 * \param name Le nom de l'animation
 * \return La séquence d'animation.
 */
MLV_Animation* MLV_get_animation_from_name(
	MLV_Animation_book* animation_book,
	const char* name
);

/** \~french 
 * \brief Renvoie le nom d'un animation à partir de son identifiant dans le
 *        livre d'animation.
 *
 * \param animation_book Le livre d'animation.
 * \param id_animation L'identifiant de l'animation dans le livre.
 * \return Le nom de l'animation.
 */
const char* MLV_get_name_from_id_animation(
	MLV_Animation_book* animation_book, int id_animation
);

/** \~french 
 * \brief Ajoute un image dans la séquence d'animation.
 *        Cette fonction ne peux pas augmenter le nombre d'image d'une
 *        animation.
 *
 * \param array_of_images Liste d'image à ajouter. Il s'agit de toutes les 
 *                        images assiciée à toutes les couches correspondnant de
 *                        l'animation.
 * \param array_of_sounds Liste de sons à ajouter. Il s'agit de toutes les 
 *                        sons assiciées à tous les cannaux correspondnant de
 *                        l'animation.
 * \param delay le temps d'afficahge d'une image.
 * \param animation  La sequence d'animation à moifier.
 */
void MLV_add_frame_in_animation(
	MLV_Image** array_of_images, MLV_Sound** array_of_sounds,  unsigned int delay,
	MLV_Animation* animation
);

#ifdef __cplusplus
}
#endif

#endif

