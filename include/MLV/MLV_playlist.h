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

#ifndef __MLV__MLV_PLAYLIST_H__
#define __MLV__MLV_PLAYLIST_H__


#include "MLV_audio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _MLV_Playlist MLV_Playlist;

void MLV_init_playlists();
void MLV_close_playlists();

MLV_Playlist* MLV_create_playlist( int loop );
void MLV_close_playlist( MLV_Playlist* playlist );

void MLV_playlist_add( MLV_Playlist* playlist, const char* file_music );
void MLV_playlist_add_sheet_music(  MLV_Playlist* playlist, MLV_Music* );
void MLV_playlist_remove( MLV_Playlist* playlist, int index );
void MLV_playlist_clear( MLV_Playlist* playlist );

void MLV_playlist_volume(  MLV_Playlist* playlist, double volume );
void MLV_playlist_play( MLV_Playlist* playlist );
void MLV_playlist_pause( MLV_Playlist* playlist );
void MLV_playlist_stop( MLV_Playlist* playlist );
void MLV_playlist_next( MLV_Playlist* playlist );
void MLV_playlist_previous( MLV_Playlist* playlist );
void MLV_playlist_first( MLV_Playlist* playlist );
void MLV_playlist_last( MLV_Playlist* playlist );
void MLV_playlist_index( MLV_Playlist* playlist, int index);

#ifdef __cplusplus
}
#endif

#endif
