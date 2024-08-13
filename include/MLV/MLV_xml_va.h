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
 * \file MLV_xml_va.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les même prototypes des fonctions que MLV_xml.h
 *        mais en utilisant en argument sulémentaire une liste de type va_list.
 *
 * Les fichiers xml sont utilisés pour stocker les données nécessaires au 
 * fonctionnement d'un programme. Ils permettent de modifier facilement
 * l'exécution du programme sans avoir à le modifier. En effet, ils sont 
 * lisibles par l'homme et par la machine en même temps.
 * Ils constituent donc une interface pratique entre l'ordinateur et 
 * l'utilisateur.
 *
 */

#ifndef __MLV__MLV_XML_VA_H__
#define __MLV__MLV_XML_VA_H__

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Permet d'accéder à l'interieur d'un champs donné du fichier xml.
 *
 * Attention: Il ne faut pas oublier de libérer la mémoire associée au 
 *            champs result.
 *
 * \param xml_data Les données xml.
 * \param result Un pointeur vers une addresse vide qui contiendra l'addresse de la chaîne de caractères correspondant au résultat de la fonction.
 * \param xpath Le chemin d'accès.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 * \return renvoie un code d'erreur si la fonction n'a pa reussie à extraire la donnée souhaitée du document xml.
 */
MLV_Xml_error MLV_get_string_value_from_xml_va(
	const MLV_Xml* xml_data, char** result, const char* xpath, va_list pile
);


/** \~french 
 * \brief Permet de récupérer l'entier d'un champs donné du fichier xml.
 *
 * Tout comme la fonction MLV_get_string_value_from_xml(), cette fonction peut 
 * contenir un nombre variable de paramètres.
 * Pour plus d'informations, veuillez lire la documentation de la fonction 
 * MLV_get_string_value_from_xml().
 *
 * \param xml_data Les données xml.
 * \param result Un pointeur vers un entier dans lequel le résultat de la fonction sera enregistré.
 * \param xpath Le chemin d'accès.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 * \return renvoie un code d'erreur si la fonction n'a pa reussie à extraire la donnée souhaitée du document xml.
 */
MLV_Xml_error MLV_get_integer_value_from_xml_va(
	const MLV_Xml* xml_data, int* result, const char* xpath, va_list pile
);

/** \~french 
 * \brief Permet de récupérer le reel d'un champs donné du fichier xml.
 *
 * Tout comme la fonction MLV_get_string_value_from_xml(), cette fonction peut 
 * contenir un nombre variable de paramètres.
 * Pour plus d'informations, veuillez lire la documentation de la fonction 
 * MLV_get_string_value_from_xml().
 *
 * \param xml_data Les données xml.
 * \param result Un pointeur vers un réel dans lequel le résultat de la fonction sera enregistré.
 * \param xpath Le chemin d'accès.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 * \return renvoie un code d'erreur (voir MLV_Xml_error) si la fonction n'a pas reussie à extraire la donnée souhaitée du document xml.
 */
MLV_Xml_error MLV_get_double_value_from_xml_va(
	const MLV_Xml* xml_data, double* result, const char* xpath, va_list pile
);

/** \~french 
 * \brief Permet de récupérer le réel d'un champs donné du fichier xml.
 *
 * Tout comme la fonction MLV_get_string_value_from_xml(), cette fonction peut 
 * contenir un nombre variable de paramètres.
 * Pour plus d'informations, veuillez lire la documentation de la fonction 
 * MLV_get_string_value_from_xml().
 *
 * \param xml_data Les données xml.
 * \param result Un pointeur vers un réel dans lequel le résultat de la fonction sera enregistré.
 * \param xpath Le chemin d'accès.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 * \return renvoie un code d'erreur (voir MLV_Xml_error) si la fonction n'a pas reussie à extraire la donnée souhaitée du document xml.
 */
MLV_Xml_error MLV_get_float_value_from_xml_va(
	const MLV_Xml* xml_data, float* result, const char* xpath, va_list pile
);


/** \~french 
 * \brief Compte le nombre d'objets présents dans le fichier xml verifiant
 *        un certain nombre de critères passés en paramètre de la fonction.
 *
 * \param xml_data Les données xml.
 * \param xpath Le chemin d'accès.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 *
 * \return Cette fonction renvoie le nombre d'objet ayant pour chemin d'accès 
 *         "xpath". 
 */
int MLV_get_number_of_objects_from_xml_va(
	const MLV_Xml* xml_data, const char* xpath, va_list pile
);

/** \~french 
 * \brief Permet de récupérer un noeud interne de l'arbre représentant le 
 *        fichier XML.
 *
 * Cette fonction n'est pas encore implémentée.
 *
 * \param xml_data Les données xml.
 * \param xpath Le chemin d'accès.
 * \param pile La pile des complements de paramètres comme dans vaprintf.
 *
 * \return Un noeud interne de l'arbre XML.
 */
MLV_Xml* MLV_get_xml_object_of_va(
	const MLV_Xml* xml_data, const char* xpath, va_list pile
);

#ifdef __cplusplus
}
#endif

#endif
