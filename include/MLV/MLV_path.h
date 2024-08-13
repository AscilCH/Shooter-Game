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
 * \file MLV_path.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les prototypes des fonctions permettant de
 *        manipuler les chemins d'accès aux fichiers et répertoires.
 *
 */

#ifndef __MLV__MLV_PATH_H__
#define __MLV__MLV_PATH_H__

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \~french
 * \brief Renvoie la chaîne de caractères après le dernier séparteur / dans un
 *        chemin donné en paramètre.
 *
 * La chaîne de caractères doit être désallouée après utilisation.
 *
 * \param path Le chemin à analyser.
 * \return Une chaîne de caractères.
 */
char* MLV_get_base_name( const char* path );

/** \~french
 *
 * \brief Renvoie la chaîne de caractères s'étendant jusqu'au dernier séparateur
 *        / du chemin donné en paramètre.
 *
 * La chaîne de caractères doit être désallouée après utilisation.
 *
 * \param path Le chemin à analyser.
 * \return Une chaîne de caractères.
 */
char* MLV_get_directory_name( const char* path );

/** \~french
 * \brief Teste si un chemin est absolu.
 *
 * \param path Le chemin
 * \return Renvoie 1 si le chemin est absolue, 0 sinon.
 */
int MLV_path_is_absolute( const char* path );

/** \~french
 * \brief Teste si un chemin est relatif.
 *
 * \param path Le chemin
 * \return Renoie 1 si le chemin est relatif, 0 sinon.
 */
int MLV_path_is_relative( const char* path );

/** \~french
 *
 * \brief Teste si le chemin corespond au chemin d'un fichier ou dossier
 *        existant.
 *
 * \param path Le chemin
 * \return Renvoie 1 si le chemin est associé à un dossier ou à un fichier
 *         existant, 0 sinon.
 */
int MLV_path_exists( const char* path );

/** \~french
 * \brief Vérifie si un chemin est associé à un répertoire.
 *
 * \param path Le chemin
 * \return Renvoie 1 si le chemin est associé à un dossier, 0 sinon.
 */
int MLV_path_is_a_directory( const char* path );

/** \~french
 * \brief Vérifie si un chemin est associé à un fichier.
 *
 * \param path Le chemin
 * \return Renvoie 1 si le chemin est associé à un fichier, 0 sinon.
 */
int MLV_path_is_a_file( const char* path );

/** \~french
 * \brief Construit en concaténant différents textes, une chaîne de caractères 
 *        représentant un chemin dont les séparateurs corespondent aux 
 *        spécifications de la plateforme sur laquel s'exécute le programme.
 *
 * \bug Cette fonction ne fait que concaténer les differentes chaînes en 
 *      mettant entre chaque chaîne un séparateur de répertoire compatible
 *      avec le système d'exploitation. Par contre, ce qui constitue le bug, il
 *      ne convertit pas chaque chaîne dans un format compatible avec celui du
 *      système d'exploitation.
 *
 * La chaîne de caractères doit être désallouée après utilisation.
 *
 * \param first_element La première chaîne à concaténer.
 * \param ... Les autres éléments à concaténer.
 * \return Le chemin vérifiant les normes de la plateforme hôte.
 */
char* MLV_build_path( const char* first_element, ... );

/** \~french
 * \brief Même chose que MLV_build_path
 *
 * La chaîne de caractères doit être désallouée après utilisation.
 *
 * \param elements Les éléments à concaténer ensemble.
 * \return Le chemin vérifiant les normes de la plateforme qui va exécuter 
 *         le programme.
 */
char* MLV_build_path_v( char** elements );

/** \~french
 * \brief Détermine le répertoire courant.
 *
 * La chaîne de caractères doit être désallouée après utilisation.
 *
 * \return Le chemin du répertoire courant.
 */
char * MLV_get_current_directory( );

/** \~french
 * \brief Détermine le répertoire temporaire.
 *
 * Le répertoire temporaire est le répertoire dans lequel les applications
 * ont le droit d'ajouter et de modifier des fichiers.
 * Ce répertoire est génaralement vidé lorsque la machine est étteinte.
 *
 * La chaîne de caractères doit être désallouée après utilisation.
 *
 * \return Le chemin du répertoire temporaire.
 */
const char * MLV_get_temporary_directory( );

/** \~french
 * \brief Détermine le répertoire personnel de l'utilisateur courant.
 *
 * La chaîne de caractères doit être désallouée après utilisation.
 *
 * \return Le chemin du répertoire personnel.
 */
const char * MLV_get_home_directory( );

#ifdef __cplusplus
}
#endif

#endif
