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
 * \file MLV_all.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Fichier d'entête principal incluant tous les autres fichiers entêtes 
 *        de la bibliothèque MLV.
 *
 * Vous trouverez tous les prototypes des fonctions proprées par la bibliothèque 
 * MLV dans les fichiers entêtes (.h) suivants :
 * 
 * MLV_animation.h : permet de mettre en oeuvre des animations.
 *
 *
 * MLV_audio.h : permet de jouer de la musique.
 *
 *
 * MLV_color.h : definit les différentes couleurs de la bibliothèque MLV.
 * 
 * 
 * MLV_event.h : propose une gestion avancée des évènements. Avec les fonctions 
 * proposées par MLV_evenement.h, il est possible de traiter les évènements 
 * sans intérrompre l'exécution du programme.
 * 
 * 
 * MLV_image.h : charger, modifier et afficher des images.
 *
 * 
 * MLV_information.h : permet d'obtenir quelques informations concernant la 
 * bibliothèque MLV (web, auteurs, version).
 *
 * 
 * MLV_input_box.h : définit différents outils pour créer et utiliser des 
 *                   boîtes de saisies.
 *
 *
 * MLV_keyboard.h : définit les types concerant le clavier et définit la 
 *                  fonction MLV_keyboard_wait pour récuperer des évènements 
 *                  provenant du clavier.
 *
 *
 * MLV_mouse.h : définit les types concerant la souris ainsi que la fonction 
 *               MLV_mouse_wait pour récuperer des évènements provenant de la 
 *               souris.
 * 
 * 
 * MLV_path.h : définit différents outils pour utiliser des chemins d'accès aux
 *              fichiers.
 *
 *
 * MLV_random.h : propose des outils pour engendrer des nombres aléatoires.
 * 
 * 
 * MLV_shape.h : permet de créer des figures ( cercle, ellipse, polygone, 
 * courbe de bezier, rectangle, ligne , point).
 * 
 * 
 * MLV_text.h : définit differents outils permettant d'afficher du texte seul ou
 * dans une boîte.
 * 
 * MLV_text_va.h : définit les même outils que MLV_text.h mais en prenant une 
 *                 comme argument suplémentaire une liste d'arguments.
 * 
 * MLV_time.h : propose des outils pour gérer le temps.
 *
 * MLV_xml.h : propose des outils pour lire des fichiers XML.
 * 
 * MLV_xml_va.h : définit les même outils que MLV_xml.h mais en prenant une 
 *                 comme argument suplémentaire une liste d'arguments.
 * 
 * MLV_window.h : propose des fonctions pour
 *     - initialiser, créer et fermer une fenêtre
 *     - actualiser l'affichage de la fenêtre
 *     - exécuter du code à la fermeture de la fenêtre
 *
 * \see MLV_animation.h MLV_audio.h MLV_color.h MLV_event.h MLV_image.h
 *      MLV_information.h MLV_input_box.h MLV_keyboard.h MLV_mouse.h 
 *      MLV_path.h MLV_random.h MLV_shape.h MLV_text.h MLV_text_va.h MLV_time.h 
 *      MLV_xml.h MLV_xml_va.h MLV_window.h 
 */

/** \~spanish
 * \file MLV_all.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Archivo principal de cabecera incluyendo todos los otros archivos de 
 *        cabecera de la biblioteca informática MLV.
 *
 * Puede encontrar todos los prototipos des las subrutinas propuestas para la 
 * biblioteca MLV en los archivos de cabecera (.h) suiquiente : 
 * 
 * MLV_animation.h : permite de añadir animaciónes.
 *
 * MLV_audio.h : permite de tocar música.
 *
 *
 * MLV_color.h : défine los differentes colores de la biblioteca MLV.
 * 
 * 
 * MLV_event.h : proppone una gestión advencada des los eventos. Con las 
 *               subrutinas propuestas para MLV_evenment.h, es possible de 
 *               tratar los eventos sin interrumpir la ejecución del programa 
 *               informático.
 * 
 * 
 * MLV_shape.h : permite de creer figuras geométricas (círculo, elipse, 
 *                 polígono, Curva de Bézier, rectángulo, linea recta, punto).
 * 
 * 
 * MLV_image.h : modificar and fijara las imagenes.
 *
 * 
 * MLV_information.h : permite de obtener algunas noticias concerniendo la 
 *                      biblioteca MLV. concernant la 
 *
 *
 * MLV_keyboard.h : define los tipos de dato por el teclado y la subrutina 
 *                  MLV_keyboard_wait para obtener los eventos del teclado.
 *
 *
 * MLV_mouse.h : define los tipos de dato por el ratón y la subrutina 
 *               MLV_mouse_wait para obtener eventos des ratón.
 * 
 * 
 * MLV_input_box.h : define algunas herramientas para creer y utilisar caja de 
 *                texto
 * 
 * 
 * MLV_text.h : define algunas herramientas para fijar textos.
 * 
 * MLV_text_va.h : TODO 
 * 
 * MLV_time.h : propone herramientas para utilisar el tiempo.
 *
 * MLV_xml.h : TODO
 *
 * MLV_xml_va.h : TODO
 *
 * MLV_random.h : propone herramientas para generar números aleatorios.
 *
 * 
 * MLV_window.h : propone las subrutina para
 *     - creer, inicializar, cerrar ventanas
 *     - actualizar la visualización de una ventana
 *     - ejecutar código al fin del programa
 *
 * 
 * \see MLV_animation.h MLV_audio.h MLV_color.h MLV_event.h MLV_shape.h 
 *      MLV_image.h MLV_keyboard.h MLV_mouse.h MLV_input_box.h MLV_random.h 
 *      MLV_text.h MLV_text_va.h MLV_time.h MLV_xml.h MLV_xml_va.h MLV_window.h 
 */

#ifndef __MLV__MLV_ALL_H__
#define __MLV__MLV_ALL_H__

#include "MLV_animation.h"
#include "MLV_audio.h"
#include "MLV_color.h"
#include "MLV_event.h"
#include "MLV_shape.h"
#include "MLV_image.h"
#include "MLV_information.h"
#include "MLV_keyboard.h"
#include "MLV_mouse.h"
#include "MLV_path.h"
#include "MLV_playlist.h"
#include "MLV_input_box.h"
#include "MLV_random.h"
#include "MLV_text.h"
#include "MLV_text_va.h"
#include "MLV_time.h"
#include "MLV_xml.h"
#include "MLV_xml_va.h"
#include "MLV_window.h"

#endif
