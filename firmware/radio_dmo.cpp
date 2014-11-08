/* Copyright (C) 2014  Jack Tan (BH1RBH)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "config.h"
#include "pin.h"
#include "radio_dmo.h"
#include <WProgram.h>


void RadioDMO::setup()
{
  // Configure pins
  pinMode(PTT_PIN, OUTPUT);
  pin_write(PTT_PIN, HIGH);
  pinMode(AUDIO_PIN, OUTPUT);
}

void RadioDMO::ptt_on()
{
  pin_write(PTT_PIN, LOW);
  delay(25);   // The DMO takes 5 ms from PTT to full RF, give it 25
}

void RadioDMO::ptt_off()
{
  pin_write(PTT_PIN, HIGH);
}
