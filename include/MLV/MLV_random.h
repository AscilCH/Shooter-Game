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
 * \file MLV_random.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit tous les prototypes des fonctions concernant
 *        la manipulation des nombres aléatoires.
 * 
 */

#ifndef __MLV__MLV_RANDOM_H__
#define __MLV__MLV_RANDOM_H__

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Renvoie 0 ou 1 aléatoirement.
 *
 * \return 0 ou 1 aléatoirement.
 */
int MLV_get_random_boolean();

/** \~french 
 * \brief Renvoie un entier aléatoire choisi dans un intervalle donné en 
 *        paramètre.
 *
 * \param begin Borne inférieur de l'intervalle ( inclusif )
 * \param end Borne supérieur de l'intervalle ( inclusif )
 * \return  Un entier aléatoire choisi dans l'intervalle [begin, end].
 */
int MLV_get_random_integer(int begin, int end);

/** \~french 
 * \brief Renvoie un réel aléatoire choisi dans un intervalle donné en 
 *        paramètre.
 *
 * \param begin Borne inférieur de l'intervalle ( inclusif )
 * \param end Borne supérieur de l'intervalle ( inclusif )
 * \return Un réel aléatoire choisi dans l'intervalle [begin, end].
 */
double MLV_get_random_double(double begin, double end);

#ifdef __cplusplus
}
#endif

#endif
