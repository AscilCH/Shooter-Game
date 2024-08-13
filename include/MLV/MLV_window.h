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
 * \file MLV_window.h
 * \brief Ce fichier définit les prototypes des fonctions permettant de créer,
 * initialiser et fermer des fenêtres.
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 */


#ifndef __MLV__MLV_WINDOW_H__
#define __MLV__MLV_WINDOW_H__

#include "MLV_color.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french  
 * \brief Créé une fenêtre dont la taille, et les différents noms sont passés en
 *        paramètres.
 *
 * Cette fonction initialise la bibliothèque MLV.
 * Un programme donné ne peut pas ouvrir plus d'une fenêtre à la
 * fois.
 * Les paramètres largeur et hauteur peuvent éventuellement prendre des valeurs 
 * négatives. Dans ce cas, la fenêtre est dessinée en plein écran.
 *
 * \bug BOGUES WINDOWS ET MACOSX UNIQUEMENT\n\n
 *      Sous Windows uniquement, la fenêtre crée ne peut pas toujours être 
 *      fermée à l'aide de la croix. En effet, la bibliothèque MLV implémente
 *      une fermeture automatique de la fenêtre lorsque l'utilisateur utilise
 *      la croix. Or, ce mécanisme utilise les threads SDL qui ne sont 
 *      malheureusement pas bien supportés sous Windows et MacOSX.\n\n
 *      En fait, la bibliothèque MLV utilise un second thread pour 
 *      récuperer en permanance tous les évènements SDL de la pile et pour les
 *      traiter au fur et à mesure de leurs apparitions. OR, sous Windos et 
 *      Mac OS X, comme les threads ne fonctionnent pas, la bibliothèque ne peux 
 *      pas lire les évènements systèmes comme ceux de la fermeture de la
 *      fenêtre. 
 *      Elle n'est donc plus informée de ce qui ce passe.
 *      Pour permettre à la bibliothèque de récupérer ces informations, il vous 
 *      suffit de demander un évènement à l'aide de la fonction :
 *      MLV_get_event().
 *      Cela obligera la bibliothèque MLV à dépiler et à traiter tous les 
 *      évènements SDL de la pile. Cela aura pour conséquence de traiter 
 *      l'évènement système de la fermeture de la fenêtre.
 *      Dans l'implémentation des fonctions : MLV_wait_keyboard(), 
 *      MLV_wait_mouse(), etc ..., nous utilisons la fonction MLV_get_event().
 *      C'est pourquoi, la croix fonctionne correctement lorsque le programme 
 *      est en attente d'une information provenant de l'utilisateur.
 *
 * \param window_name Le nom de la fenêtre.
 * \param icone_name Le nom de l'icône de la fenêtre.
 * \param width La largeur de la fenêtre.
 * \param height La hauteur de la fenêtre.
 */
void MLV_create_window(
	const char* window_name, const char* icone_name, 
	unsigned int width, unsigned int height
);


/** \~french  
 * \brief Même chose que MLV_create_window(), mais en utilisant une fonte 
 *        de caractères particulière.
 *
 * \bug Même bogues que la fonction MLV_create_window().
 *
 * \param window_name Le nom de la fenêtre.
 * \param icone_name Le nom de l'icône de la fenêtre.
 * \param width La largeur de la fenêtre.
 * \param height La hauteur de la fenêtre.
 * \param path_to_font Le chemin d'accès vers une fonte de caratères au standard
 *        'TrueType' (fichiers d'extension .ttf).
 * \param size_font La taille de la fonte de caractères. la hauteur de la fenêtre.
 */
void MLV_create_window_with_default_font(
	const char* window_name, const char* icone_name, 
	unsigned int width, unsigned int height,
	const char* path_to_font, unsigned int size_font
);

/** \~french  
 * \brief Change la fonte de caractères par défault de la bibliothèque MLV.
 *
 * Cette fonction change la fonte de caractères par défault de la bibliothèque.
 * Cette fonction ne peux s'exécuter qu'après avoir initialisé la bibliothèque 
 * MLV en créant une fenêtre à l'aide de la fonction MLV_create_window().
 * Cette fonction n'a pas de sens si vous ne souhaitez pas changer de fontes
 * plusieurs fois durant l'exécution de votre programme.
 * Si vous n'utilisez qu'une seule fonte de caractères, il vaut mieux 
 * l'indiquer à la bibliothèque MLV lors de la création de la fenêtre en utilisant 
 * la fonction: MLV_create_window_with_default_font().
 *       
 * \param path_to_font Le chemin d'accès vers une fonte de caratères au 
 *                     standard "TrueType" (fichiers d'extension .ttf).
 * \param size_font La taille de la fonte de caractères.
 */
void MLV_change_default_font( const char* path_to_font, unsigned int size_font );

/** \~french  
 * \brief Même chose que MLV_create_window(), mais configure la fenêtre en 
 *        mode plein écran.
 *
 * \bug Même bogues que MLV_create_window().
 *
 * \param window_name Le nom de la fenêtre.
 * \param icone_name Le nom de l'icône de la fenêtre.
 * \param width La largeur de la fenêtre ( en mode plein écran, cette valeur 
 *              correspond à la coordonnée en X de la résolution de l'image ).
 * \param height La hauteur de la fenêtre ( en mode plein écran, cela 
 *               correspond à la coordonnée en Y de la résolution de l'image ).
 */
void MLV_create_full_screen_window(
	const char* window_name, const char* icone_name,
	unsigned int width, unsigned int height
);

/** \~french  
 * \brief Même chose que MLV_create_window(), mais configure la fenêtre en 
 *        mode plein écran.
 *
 * \bug Même bogues que MLV_create_window().
 *
 * \param window_name Le nom de la fenêtre.
 * \param icone_name Le nom de l'icône de la fenêtre.
 * \param width La largeur de la fenêtre ( en mode plein écran, cette valeur 
 *              correspond à la coordonnée en X de la résolution de l'image ).
 * \param height La hauteur de la fenêtre ( en mode plein écran, cela 
 *               correspond à la coordonnée en Y de la résolution de l'image ).
 * \param path_to_font Le chemin d'accès vers une fonte de caratères au 
 *                     standard "TrueType" (fichiers d'extension .ttf).
 * \param size_font La taille de la fonte de caractères.
 */
void MLV_create_full_screen_window_with_default_font(
	const char* window_name, const char* icone_name, 
	unsigned int width, unsigned int height,
	const char* path_to_font, unsigned int size_font
);


/** \~french  
 * \brief Affiche la fenêtre en plein ecran.
 *
 * La résolution de l'image est donnée alors par la taille de l'image.
 * Pour que l'application soit en plein écran, il faut que la taille de la
 * fenêtre soit compatible avec la résolution de l'écran.
 */
void MLV_enable_full_screen();

/** \~french  
 * \brief Désactve le mode plein écran de la fenêtre.
 */
void MLV_disable_full_screen();

/** \~french 
 * \brief Test si l'affichage est en mode plein écran ou en mode fenêtre.
 *
 * \return Renvoie 1 si l'affichage est en mode plein écran, 0 sinon.
 */
int MLV_is_full_screen();

/** \~french  
 * \brief Change la taille de la fenêtre.
 *
 * Si la fenêtre est configurée en mode plein ecran, l'application reste alors 
 * en mode plein écran.
 * Pour que l'application soit en plein écran, il faut que la taille de la 
 * fenêtre soit compatible avec la résolution de l'écran.
 * De plus, en mode plein écran, la taille de la fenêtre correspond à la 
 * résolution de l'image sur l'écran.
 *
 * \param width la largeur de la fenêtre
 * \param height la hauteur de la fenêtre
 */
void MLV_change_window_size( unsigned int width, unsigned int height );

/** \~french  
 * \brief Change les intitulés de la fenêtre principale.
 *
 * \param window_name Intitulé apparaissaissant sur la barre de la fenêtre.
 * \param icone_name  Intitulé apparaissaissant dans la barre des tâches.
 */
void MLV_change_window_caption(
	const char* window_name, const char* icone_name
);

/** \~french  
 * \brief Renvoie dans les paramètres, la hauteur et la largeur de la fentre.
 *
 * \param width La largeur de la fenêtre.
 * \param height La hauteur de la fenêtre.
 */
void MLV_get_window_size( unsigned int* width, unsigned int* height );

/** \~french  
 * \brief Retourne la hauteur de la fenêtre.
 */
int MLV_get_window_height( );

/** \~french  
 * \brief Retourne la largeur de la fenêtre.
 */
int MLV_get_window_width( );

/** \~french  
 * \brief Éfface la fenêtre et la remplace par un monochrome de la couleur 
 *        donnée en paramètre.
 *
 * \param color La couleur du fond de la fênetre.
 */
void MLV_clear_window( MLV_Color color );

/** \~french 
 * \brief Ferme la fenêtre de la bibliothèque MLV.
 *
 * Cette fonction libère correctement toutes les données qui ont été crées par la
 * bibliothèque MLV 
 *
 */
void MLV_free_window();

/** \~french  
 * \brief Actualise l'affichage de la fenêtre.
 *
 * Vois La fonction MLV_update_window 
 *
 * Lorsque vous utilisez des fonctions de dessins, les différents changements
 * effectués ne sont pas visibles. Pour les afficher vous devez utiliser cette
 * fonction.
 */
void MLV_actualise_window();

/** \~french  
 * \brief Met à jour l'affichage de la fenêtre.
 *
 * Lorsque vous utilisez des fonctions de dessins, les différents changements
 * effectués ne sont pas visibles. Pour les afficher vous devez utiliser cette
 * fonction.
 */
void MLV_update_window();

/** \~french  
 * \brief Exécute la fonction de call back donnée en paramètre lorsque le système
 * envoie un signal d'arrêt, ou lorsque l'utilisateur clique sur la croix de la 
 * fenêtre.
 *
 * La fonction de call back est alors exécutée avec en
 * paramêtre un pointeur vers une structure de donnée qui 
 * est aussi donné en paramètre à la fonction 
 * MLV_execute_at_exit().
 *
 * \param function Le pointeur de la fonction de call back qui  doit être exécutée.
 * \param data La Donnée à passer en paramètre à la fonction de call back lors de
 *             son exécution.
 */
void MLV_execute_at_exit( void (*function)(void*), void* data );

/** \~french  
 * \brief Renvoie dans les paramètres, la hauteur et la largeur de 
 *        l'environement de bureau de l'ordinateur.
 *
 * \param width La largeur du bureau.
 * \param height La hauteur du bureau.
 */
void MLV_get_desktop_size( unsigned int* width, unsigned int* height );

/** \~french  
 * \brief Renvoie la hauteur de l'environement de bureau de l'ordinateur.
 */
int MLV_get_desktop_height( );

/** \~french  
 * \brief Renvoie la largeur de l'environement de bureau de l'ordinateur.
 */
int MLV_get_desktop_width( );


#ifdef __cplusplus
}
#endif

#endif
