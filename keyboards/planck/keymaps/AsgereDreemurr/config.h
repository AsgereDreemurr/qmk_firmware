/* Copyright 2015-2021 Jack Humbert
 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(NO_SOUND)
//#    define STARTUP_SONG SONG(PLANCK_SOUND)

#    define DEFAULT_LAYER_SONGS \
     { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif

#define COMBO_COUNT 19

#define AUDIO_CLICKY
// #define AUDIO_ENABLE_TONE_MULTIPLEXING
// #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 20