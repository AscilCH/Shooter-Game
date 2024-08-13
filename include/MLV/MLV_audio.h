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
 * \file MLV_audio.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les prototypes des fonctions permettant de faire 
 *        jouer de la musique et des échantillons sonores à l'aide de la bibliothèque
 *        MLV.
 */

#ifndef __MLV__MLV_AUDIO_H__
#define __MLV__MLV_AUDIO_H__

#ifndef MEMORY_DEBUG
#include <SDL/SDL.h>
#else
#include "memory_debug.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Ce type code un morceau de musique.
 */
typedef struct _MLV_Music MLV_Music;

/** \~french 
 * \brief Ce type code un échantillon sonore.
 */
typedef struct _MLV_Sound MLV_Sound;

/** \~french 
 * \brief Cette fonction initialise la bibliothèque MLV pour pouvoir jouer de la 
 *        musique et des sons.
 *
 *  \return Renvoie 0 si l'infrastructure audio a été correctement initialisé, 
 *          renvoie -1 sinon.
 */
int MLV_init_audio();

/** \~french 
 * \brief Ferme proprement les différents périphériques audios.
 */
void MLV_free_audio();

/** \~french 
 * \brief Change la taille du buffer audio. La taille doit être une puissance 
 *        de 2.
 *
 * Le porgramme rempli périodiquement un buffer audio à faire jouer par la 
 * carte son. Plus la taille du buffer audio est grande, plus le programme
 * à le temps de remplir le buffer avant qu'il se vide. Plus le buffer est
 * grand, plus le programme met du temps à le remplir.
 *
 * Ainsi, si il y a un temps de latence entre une action et l'execution sonore
 * du son correspondant, c'est que vous devez réduire la taille du buffer audio.
 *
 * Si le son est coupé et crépite, c'est que le buffer est trop petit et que le 
 * processeur est trop lent pour remplir le buffer avant qu'il se vide.
 * Vous devez donc agrandir la taille du buffer.
 *
 * MLV_change_buffer_size vous permet d'ajuster la taille de ce buffer.
 * par default la taille du buffer est mis à 1024.
 *
 * Si vous utilisez le programme uniquement pour jouer de la musique, nous vous 
 * vous conseillons de configurer la taille du buffer à 4096.
 *
 * \param buffer_size Taille du buffer audio ( une puissance de 2 )
 *
 *  \return Renvoie 0 si l'infrastructure audio a été correctement initialisé, 
 *          renvoie -1 sinon.
 */
int MLV_change_audio_buffer_size( int buffer_size );

/** \~french 
 * \brief Change le nombre d'écahantillons sonores qui peuvent être joués en 
 *        même temps.
 *
 * \param n Le nombre d'échantillons sonores.
 */
void MLV_change_number_of_parallel_sounds( unsigned int n );

/** \~french 
 * \brief Charge un ficher contenant de la musique en mémoire.
 *
 * Cette fonction prends en paramètre le chemin d'accès du 
 * fichier contenant la musique et renvoie un pointeur vers l'espace mémoire où
 * a été chargé la musique.
 *
 * Les formats de fichier acceptés sont les suivants .ogg, .mp3, .wav, etc ...
 *
 * \param file_music Chemin d'accès vers un fichier contenant de la musique 
 *        codée en format .wav.
 * \return Un pointeur vers la musique chargée en mémoire, ou NULL si la 
 *         bibliothèque n'a pas réussi à charger la musique en mémoire.
 */
MLV_Music* MLV_load_music( const char* file_music );

/** \~french 
 * \brief Ferme un morceau de musique chargé en mémoire.
 *
 * \param music Le morceau de musique à fermer
 */
void MLV_free_music( MLV_Music* music );

/** \~french 
 * \brief Joue un morceau de musique qui est chargée en mémoire.
 *
 * \param music Le morceau de musique à jouer.
 * \param volume Le volume sonore.
 * \param loop Le nombre de fois que le morceau doit être joué. Si loop est
 *        strictement négatif, le morceau sera joué indéfiniment.
 */
void MLV_play_music( const MLV_Music* music, float volume, int loop );

/** \~french 
 * \brief Arrête toutes les musiques.
 */
void MLV_stop_music();


/** \~french 
 * \brief Charge un ficher contenant un échantillon sonore en mémoire.
 *
 * Cette fonction prends en paramètre le chemin d'accès du 
 * fichier contenant l'échantillon sonore et renvoie un pointeur vers l'espace
 * mémoire où a été chargé l'échantillon sonore.
 *
 * Les formats de fichier acceptés sont les suivants : WAVE, AIFF, RIFF, OGG, and
 * VOC.
 *
 * \param file_sound Chemin d'accès vers un fichier contenant un échantillon 
 *        sonore.
 * \return Null si le fichier n'a pas pu être chargé en mémoire. Un pointeur vers
 *         l'échantllon sonore sinon.
 */
MLV_Sound* MLV_load_sound( const char* file_sound );

/** \~french 
 * \brief Ferme un échantillon sonore chargé en mémoire.
 *
 * \param sound L'échantillon sonore à fermer
 */
void MLV_free_sound( MLV_Sound* sound );

/** \~french 
 * \brief Joue un échantillon sonore chargé en mémoire.
 *
 * \param sound L'échantillon sonore à jouer.
 * \param volume Le volume sonore.
 */
void MLV_play_sound( const MLV_Sound* sound, float volume );

/** \~french 
 * \brief Arrête tous les échantillons sonores.
 */
void MLV_stop_all_sounds();


#ifdef __cplusplus
}
#endif

#endif
