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
 * \file MLV_time.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit tous les prototypes des fonctions concernant la
 *        gestion du temps.
 * 
 */

#ifndef __MLV__MLV_TIME_H__
#define __MLV__MLV_TIME_H__

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Le programme s'intérompt pendant un nombre de milli-secondes donné 
 *        en paramètre.
 *
 * \param milliseconds Le nombre de milli-secondes à attendre.
 */
void MLV_wait_milliseconds(int milliseconds);

/** \~french 
 * \brief Le programme s'intérompt pendant un nombre de secondes.
 *
 * \param seconds Le nombre de secondes à attendre.
 */
void MLV_wait_seconds(int seconds);

/** \~french 
 * \brief Renvoie le nombre de millisecondes écoulées depuis le début de
 *        l'initialisation de la bibliothèque MLV ( avec MLV_create_window ).
 * \return Le temps écoulé depuis l'initialisation de la bibliothèque MLV.
 */
int MLV_get_time();

/** \~french 
 * \brief Donne la date du jour (seconde/heure/jour/mois/annee).
 *
 * L'année est donnée depuis l'an 0.
 *
 * Une valeur nulle peut être passée en paramètre de la fonction. Dans ce cas, 
 * le paramètre est ignoré par la fonction.
 *
 * \param seconds Le nombre de secondes écoulées depuis le dernier changement de
 *                minute.
 * \param minutes Le nombre de minutes écoulées depuis le dernier changement
 *                d'heure
 * \param hours Le nombre d'heures écoulées depuis minuit.
 * \param day Le quantième du mois.
 * \param month Le nombre de mois écoulés depuis le début de l'année.
 * \param year Le nombre d'années depuis l'an 0.
 * \param day_of_the_week Le jour de la semaine ( 0: Lundi, 1:Mardi, ..., 
 *                        6:Dimanche).
 * \return Renvoie 1 si le décalage heure d'hivers et heure d'été a été 
 *         pris en compte, 0 si il ne l'a pas été et -1 si l'information 
 *         n'est pas disponible.
 */
int MLV_get_date(
	int* seconds, int* minutes, int* hours,
	int* day, int* month, int* year,
	int* day_of_the_week
);

/** \~french 
 * \brief Configure la fréquence de rafraichissement en Hz.
 *
 * La fréquence de rafraîchissement par defaut est de 100 Hz. Cela signifie 
 * que si l'on utilise MLV_delay_according_to_frame_rate() entre chaque  
 * rafraîchissement de la fenêtre graphique, on obtient un rafraichissement 
 * de 100 images par secondes.
 *
 * \param rate Fréquence de rafraîchissement.
 */
void MLV_change_frame_rate( int rate );

/** \~french 
 * \brief Donne la fréquence de rafraîchissement courante.
 *
 * \return La fréquence de rafraîchissement courante.
 */
int MLV_get_frame_rate( );

/** \~french 
 * \brief Suspend l'exécution du programme de façon à ce que le temps écoulé 
 *        depuis le drenier appel à cette fonction, soit égale à la période de 
 *        la fréquence de rafraîchissement configuré par MLV_change_frame_rate.
 */
void MLV_delay_according_to_frame_rate( );

#ifdef __cplusplus
}
#endif

#endif
