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
 * \file MLV_information.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les prototypes des fonctions permettant de récupérer
 *        des informations sur la bibliothèque.
 */

#ifndef __MLV__MLV_INFORMATIONS_H__
#define __MLV__MLV_INFORMATIONS_H__

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Renvoie le nom de la bibliothèque.
 *
 * \return Le nom de la bibliothèque.
 */
const char* MLV_get_package_name( );

/** \~french 
 * \brief Renvoie la version de la bibliothèque
 *
 * \return La version de la bibliothèque.
 */
const char* MLV_get_version( );

/** \~french 
 * \brief Renvoie la révision du dépot du logiciel de gestion de version de 
 *        mlv.
 *
 * \return La révision du dépot du logiciel de gestion de version de mlv.
 */
const char* MLV_get_revision_of_revision_control_software( );


/** \~french 
 * \brief Renvoie l'adresse du dépot de code source où se trouve la 
 *        bibliothèque.
 *
 * \return Le dépôt de la bibliothèque.
 */
const char* MLV_get_repository( );

/** \~french 
 * \brief Renvoie l'addresse mail à laquelle vous pouvez envoyer les bugs que 
 *        vous rencontrez.
 *
 * \return L'addresse mail.
 */
const char* MLV_get_bug_report_address( );

/** \~french 
 * \brief Renvoie le nom de la licence de la bibliothèque.
 *
 * \return Le nom de la licence de la bibliothèque.
 */
const char* MLV_get_licence( );

/** \~french 
 * \brief Renvoie l'addresse internet où l'on peut trouver le code source de la
 *        bibliothèque.
 *
 * \return L'addresse internet où l'on peut trouver le code source de la
 *         bibliothèque.
 */
const char* MLV_get_web_distribution( );

#ifdef __cplusplus
}
#endif

#endif

