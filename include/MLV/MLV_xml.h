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
 * \file MLV_xml.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les prototypes des fonctions permettant de lire des
 *        fichiers xml.
 *
 * Les fichiers xml sont utilisés pour stocker les données nécessaires au 
 * fonctionnement d'un programme. Ils permettent de modifier facilement
 * l'exécution du programme sans avoir à le modifier. En effet, ils sont 
 * lisibles par l'homme et par la machine en même temps.
 * Ils constituent donc une interface pratique entre l'ordinateur et 
 * l'utilisateur.
 *
 */

#ifndef __MLV__MLV_XML_H__
#define __MLV__MLV_XML_H__

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Définit le type de donnée stockée au format xml dans la bibliothèque MLV.
 */
typedef struct _MLV_Xml MLV_Xml;

/** \~french 
 * \brief Charge en mémoire un fichier au format xml.
 *
 * Cette fonction renvoi NULL, lorsque le fichier n'a pas pu être correctement
 * chargé.
 *
 * \param xml_file_path Chemin d'accès du fichier xml.
 * \return Le fichier xml lu, analysé et chargé.
 */
MLV_Xml* MLV_load_xml( const char* xml_file_path );

/** \~french 
 * \brief Libère la mémoire utilisée par les données du fichier xml.
 *
 * \param xml_data Les données xml a supprimer.
 */
void MLV_free_xml( MLV_Xml* xml_data );

/** \~french 
 * \brief Énumère les différents codes d'erreurs que l'on peut rencontrer 
 *        lorsque l'ordinateur lit un document xml.
 */
typedef enum {
	MLV_XML_NONE, /**< \~french Aucune erreur detectée. */
	MLV_XML_THE_FIELD_DOESNT_EXIST, /**< \~french Le champs n'existe pas dans le document xml. */
	MLV_XML_THE_FIELD_IS_NOT_A_REAL, /**< \~french Le champs ne contient pas une chaîne de caractères codant un reel. */
	MLV_XML_THE_FIELD_IS_NOT_AN_INTEGER, /**< \~french Le champs ne contient pas un chaîne de caractères codant un entier. */
	MLV_XML_THE_FIELD_IS_TOO_BIG /**< \~french La chaîne code un réel/entier trop long pour être stocké dans la variable. */
} MLV_Xml_error;

/** \~french 
 * \brief Permet d'accéder à l'interieur d'un champs donné du fichier xml.
 *
 * Cette fonction peut contenir un nombre variable de paramètres.
 * Comme avec la fonction printf les paramètres suplémentaires, 
 * situées après le paramètre xpath, permettent de construire des
 * requêtes xpath évolué.
 *
 * Par exemple,

 * \code
 * int id_batiment = 2;
 * char * type_salle = "informatique"
 * int id_salle = 4;
 * char* nom_salle;
 * MLV_get_string_value_from_xml(
 *		xml_data, &(nom_salle),
 *      "/batiment[%d]/salle[type=%s][%d]/nom",
 *      id_batiment, type_salle, id_salle
 * )
 * free( nom_salle ); // on oublie pas de libérer la mémoire après avoir 
 *                    // utilisé nom_salle
 * \endcode
 *
 * permet de recupérer le contenu du champs "nom" situé dans la 4eme salle
 * informatique du 2eme batiment.
 *
 * Attention: Il ne faut pas oublier de libérer la mémoire associée au champs 
 *            result.
 *
 * \param xml_data Les données xml.
 * \param result Un pointeur vers une addresse vide qui contiendra l'addresse de la chaîne de caractères correspondant au résultat de la fonction.
 * \param xpath Le chemin d'accès.
 * \return renvoie un code d'erreur si la fonction n'a pa reussie à extraire la donnée souhaitée du document xml.
 */
MLV_Xml_error MLV_get_string_value_from_xml(
	const MLV_Xml* xml_data, char** result , const char* xpath, ...
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
 * \return renvoie un code d'erreur si la fonction n'a pa reussie à extraire la donnée souhaitée du document xml.
 */
MLV_Xml_error MLV_get_integer_value_from_xml(
	const MLV_Xml* xml_data, int* result, const char* xpath, ...
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
 * \return renvoie un code d'erreur (voir MLV_Xml_error) si la fonction n'a pas reussie à extraire la donnée souhaitée du document xml.
 */
MLV_Xml_error MLV_get_double_value_from_xml(
	const MLV_Xml* xml_data, double* result, const char* xpath, ...
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
 * \return renvoie un code d'erreur (voir MLV_Xml_error) si la fonction n'a pas reussie à extraire la donnée souhaitée du document xml.
 */
MLV_Xml_error MLV_get_float_value_from_xml(
	const MLV_Xml* xml_data, float* result, const char* xpath, ...
);


/** \~french 
 * \brief Compte le nombre d'objets présents dans le fichier xml verifiant
 *        un certain nombre de critères passés en paramètre de la fonction.
 *
 * \param xml_data Les données xml.
 * \param xpath Le chemin d'accès.
 * \param ... Les paramètres de la fonction.
 *
 * \return Cette fonction renvoie le nombre d'objet ayant pour chemin d'accès 
 *         "xpath". 
 */
int MLV_get_number_of_objects_from_xml(
	const MLV_Xml* xml_data, const char* xpath, ...
);

/** \~french 
 * \brief Permet de récupérer un noeud interne de l'arbre représentant le 
 *        fichier XML.
 *
 * Cette fonction n'est pas encore implémentée.
 *
 * \param xml_data Les données xml.
 * \param xpath Le chemin d'accès.
 * \param ... Les paramètres de la fonction.
 *
 * \return Un noeud interne de l'arbre XML.
 */
MLV_Xml* MLV_get_xml_object_of( const MLV_Xml* xml_data, const char* xpath, ... );

/** \~french 
 * \brief Écrit sur le terminal le contenu d'un fichier xml.
 *
 * Cette fonction n'est pas encore implémentée.
 *
 * \param xml_data Les données xml.
 * \param ... Les paramètres de la fonction.
 */
void MLV_print_xml( const MLV_Xml* xml_data );

#ifdef __cplusplus
}
#endif

#endif
