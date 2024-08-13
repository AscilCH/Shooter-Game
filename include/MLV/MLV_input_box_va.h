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
 * \file MLV_input_box_va.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les prototypes des fonctions permettant de 
 *        demander à l'utilisateur du texte par l'intermédiaire de boîtes 
 *        de saisie.
 *
 */

#ifndef __MLV__MLV_INPUT_BOX_VA_H__
#define __MLV__MLV_INPUT_BOX_VA_H__

#include "MLV_color.h"
#include "MLV_text.h"
#include "MLV_input_box.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 *
 * \brief Cette fonction suspend l'exécution du programme, affiche une boîte 
 *        de saisie et attends que l'utilisateur rentre une phrase dans le 
 *        champs de la boîte.
 *
 * La boîte de saisie contient deux zones de textes. 
 * La première zone ne peut pas être éditée par l'utilisateur et sert à 
 * afficher un message d'information. 
 * La deuxième est vide et peut être éditée par l'utilisateur.
 * Lorsque l'utilisateur appuie sur la touche entrée, le texte qui 
 * se trouve dans la zone de texte est renvoyé par la fonction
 * grâce au paramètre text.
 * Le texte, la taille et les couleurs de la boîte de saisie sont
 * paramétrables.
 * 
 * MLV_wait_input_box() alloue lui même la mémoire associée au paramètre "text".
 * Par contre, après utilisation, vous devez libérer l'espace mémoire qui a été 
 * alloué.
 *
 * \param sommetHautGaucheX     La coordonnée en X du coin Nord-Ouest de la 
 *                              boîte de saisie.
 * \param sommetHautGaucheY     La coordonnée en Y du coin Nord-Ouest de la 
 *                              boîte de saisie.
 * \param sommetBasDroitX       La coordonnée en X du coin Sud-Est de la 
 *                              boîte de saisie.
 * \param sommetBasDroitY       La coordonnée en Y du coin Sud-Est de la 
 *                              boîte de saisie.
 * \param borderColor           La couleur de la bordure de la boîte de saisie.
 * \param textColor             La couleur du texte de la boîte de saisie.
 * \param backgroundColor       La couleur de fond de la boîte de saisie.
 * \param informativeMessage    Le message à afficher devant la boîte de saisie.
 * \param text                  L'addresse où sera placé la réponse donnée par 
 *                              l'utilisateur.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 */
void MLV_wait_input_box_va(
	int sommetHautGaucheX, int sommetHautGaucheY,
	int sommetBasDroitX, int sommetBasDroitY,
	MLV_Color borderColor, MLV_Color textColor,
	MLV_Color backgroundColor,
	const char* informativeMessage,
	char** text,
	va_list pile
);

/** \~french 
 *
 * \brief Même chose que MLV_wait_input_box(), mais il est possible de 
 *        changer la fonte du du texte.
 * 
 * MLV_wait_input_box_with_font() alloue lui même la mémoire associée au 
 * paramètre "text".
 * Par contre, après utilisation, vous devez libérer l'espace mémoire qui a 
 * été alloué.
 *
 * \param sommetHautGaucheX   La coordonnée en X du coin Nord-Ouest de la 
 *                            boîte de saisie.
 * \param sommetHautGaucheY   La coordonnée en Y du coin Nord-Ouest de la 
 *                            boîte de saisie.
 * \param sommetBasDroitX     La coordonnée en X du coin Sud-Est de la boîte 
 *                            de saisie.
 * \param sommetBasDroitY     La coordonnée en Y du coin Sud-Est de la boîte 
 *                            de saisie.
 * \param borderColor         La couleur de la bordure de la boîte de saisie.
 * \param textColor           La couleur du texte de la boîte de saisie.
 * \param backgroundColor     La couleur de fond de la boîte de saisie.
 * \param informativeMessage  Le message à afficher devant la boîte de saisie.
 * \param text                L'addresse où sera placé la réponse donnée par 
 *                            l'utilisateur.
 * \param font                La font du texte à utiliser.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 */
void MLV_wait_input_box_with_font_va(
	int sommetHautGaucheX, int sommetHautGaucheY,
	int sommetBasDroitX, int sommetBasDroitY,
	MLV_Color borderColor, MLV_Color textColor,
	MLV_Color backgroundColor,
	const char* informativeMessage,
	char** text,
	const MLV_Font* font,
	va_list pile
);

/** \~french 
 * \brief Cette fonction créé une boîte de saisie.
 *
 * Une fois la boîte de saisie créé, si l'utilisateur clique sur la boîte 
 * de saisie, la boîte de saisie devient active.
 * Cela veux dire que tout les évènements clavier sont récupérés par la 
 * boîte de saisie qui s'en sert pour enregistrer le texte tapé par 
 * l'utilisateur.
 * De même, tout clique de souris réalisé sur la boîte de saisie est 
 * acaparé par la boîte de saisie.
 *
 * Pour dessiner une ou toutes les boîtes de saisies, dans la zone où vous 
 * les avez créées, vous devez utiliser les fonctions : 
 * - MLV_draw_input_box()
 * - MLV_draw_all_input_boxes()
 *
 * \param sommetHautGaucheX La coordonnée en X du sommet Nord-Ouest de la boîte 
 *                          de saisie.
 * \param sommetHautGaucheY La coordonnée en Y du sommet Nord-Ouest de la boîte 
 *                          de saisie.
 * \param width La largeur de la boîte de saisie.
 * \param height La hauteur de la boîte de saisie.
 * \param borderColor La couleur de la bordure de la boîte de saisie.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond.
 * \param informativeMessage La message d'entête de la boîte de saisie.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 */
MLV_Input_box* MLV_create_input_box_va(
	int sommetHautGaucheX, int sommetHautGaucheY,
	int width, int height,
	MLV_Color borderColor, MLV_Color textColor,
	MLV_Color backgroundColor,
	const char* informativeMessage,
	va_list pile
);

/** \~french 
 * \brief Cette fonction créé une boîte de saisie avec une font spécifique.
 *
 * \param sommetHautGaucheX La coordonnée en X du sommet Nord-Ouest de la boîte de saisie.
 * \param sommetHautGaucheY La coordonnée en Y du sommet Nord-Ouest de la boîte de saisie.
 * \param width La largeur de la boîte de saisie.
 * \param height La hauteur de la boîte de saisie.
 * \param borderColor La couleur de la bordure de la boîte de saisie.
 * \param textColor La couleur du texte.
 * \param backgroundColor La couleur du fond.
 * \param informativeMessage Le message d'entête de la boîte de saisie.
 * \param font La font à utiliser pour le texte.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 */
MLV_Input_box* MLV_create_input_box_with_font_va(
	int sommetHautGaucheX, int sommetHautGaucheY,
	int width, int height,
	MLV_Color borderColor, MLV_Color textColor,
	MLV_Color backgroundColor,
	const char* informativeMessage,
	const MLV_Font* font,
	va_list pile
);

/** \~french 
 * \brief Cette fonction change le message d'entête d'une boîte de saisie.
 *
 * \param input_box La boîte de saisie à modifier.
 * \param message Le message d'entête.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 */
void MLV_change_informative_message_of_input_box_va(
	MLV_Input_box* input_box, const char* message, va_list pile
);

#ifdef __cplusplus
}
#endif

#endif
